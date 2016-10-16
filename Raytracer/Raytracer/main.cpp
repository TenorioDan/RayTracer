#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Vect.h";
#include "Ray.h";
#include "Camera.h";
#include "Color.h";
#include "Light.h";
#include "Object.h";
#include "Sphere.h";
#include "Plane.h";


using namespace std;

struct RGBType 
{
	double r;
	double g;
	double b;
};


/*
* A function that we can pass color data to that spits out a file
*/
void saveBMP(const char* filename, int w, int h, int dpi, RGBType* data) 
{
	FILE *f;
	int k = w*h;
	int s = 4 * k;
	int filesize = 54 + s;

	double factor = 39.375;
	int m = static_cast<int>(factor);

	int ppm = dpi*m;


	// Create the file structure for a bitmap image
	// info at https://en.wikipedia.org/wiki/BMP_file_format

	unsigned char bmpFileHeader[14] = { 'B', 'M', 0,0,0,0,  0,0,0,0,  54,0,0,0 };
	unsigned char bmpInfoHeader[40] = { 40,0,0,0,  0,0,0,0,  0,0,0,0,  1,0,24,0 };

	bmpFileHeader[2] = (unsigned char)(filesize);
	bmpFileHeader[3] = (unsigned char)(filesize>>8);
	bmpFileHeader[4] = (unsigned char)(filesize>>16);
	bmpFileHeader[5] = (unsigned char)(filesize>>24);

	bmpInfoHeader[4] = (unsigned char)(w);
	bmpInfoHeader[5] = (unsigned char)(w>>8);
	bmpInfoHeader[6] = (unsigned char)(w>>16);
	bmpInfoHeader[7] = (unsigned char)(w>>24);

	bmpInfoHeader[8] = (unsigned char)(h);
	bmpInfoHeader[9] = (unsigned char)(h >> 8);
	bmpInfoHeader[10] = (unsigned char)(h >> 16);
	bmpInfoHeader[11] = (unsigned char)(h >> 24);

	bmpInfoHeader[21] = (unsigned char)(s);
	bmpInfoHeader[22] = (unsigned char)(s >> 8);
	bmpInfoHeader[23] = (unsigned char)(s >> 16);
	bmpInfoHeader[24] = (unsigned char)(s >> 24);

	bmpInfoHeader[21] = (unsigned char)(s);
	bmpInfoHeader[22] = (unsigned char)(s >> 8);
	bmpInfoHeader[23] = (unsigned char)(s >> 16);
	bmpInfoHeader[24] = (unsigned char)(s >> 24);

	bmpInfoHeader[25] = (unsigned char)(ppm);
	bmpInfoHeader[26] = (unsigned char)(ppm >> 8);
	bmpInfoHeader[27] = (unsigned char)(ppm >> 16);
	bmpInfoHeader[28] = (unsigned char)(ppm >> 24);

	bmpInfoHeader[29] = (unsigned char)(s);
	bmpInfoHeader[30] = (unsigned char)(s >> 8);
	bmpInfoHeader[31] = (unsigned char)(s >> 16);
	bmpInfoHeader[32] = (unsigned char)(s >> 24);

	f = fopen(filename, "wb");
	fwrite(bmpFileHeader, 1, 14, f);
	fwrite(bmpInfoHeader, 1, 40, f);

	for (int i = 0; i < k; i++) {
		RGBType rgb = data[i];

		double red = (data[i].r)*255;
		double green = (data[i].g) * 255;
		double blue = (data[i].b) * 255;

		unsigned char color[3] = { (int)floor(blue), (int)floor(green), (int)floor(red) };

		fwrite(color, 1, 3, f);
	}

	fclose(f);
}


int nearestObjectIndex(vector<double> intersections)
{
	int mininumIndex;

	// prevent unnecessary calculations
	if (intersections.size() == 0) 
	{
		return -1;
	}
	else if (intersections.size() == 1)
	{
		if (intersections.at(0) > 0) 
		{
			// of that intersection is greater than zero then its the index of minimum value
			return 0;
		}
		else 
		{
			// otherwise the only interesection is negative
			// the ray missed every object in the scene
			return -1;
		}
	}
	else
	{
		// there is more than one intersection and we have to find the minimum value
		// first find the maximum value
		double max = 0;
		for (int i = 0; i < intersections.size(); i++)
		{
			if (max > intersections.at(i))
				max = intersections.at(i);
		}

		 // then starting form the maximum value find the minimum position
		if (max > 0)
		{
			// we only want positive intersections
			for (int index = 0; index < intersections.size(); index++) 
			{
				if (intersections.at(index) > 0 && intersections.at(index) <= max)
				{
					max = intersections.at(index);
					mininumIndex = index;
				}
			}

			return mininumIndex;
		}
		else
		{
			// all intersections were negative
			return -1;
		}
	}
}


/*
* A ray tracer is a program that produces an image where each pixel in that image has a color
* and the color of the pixel needs to correspond to the color of an object in the scene
*/
int main(int argc, char *argv[])
{
	cout << "rendering..." << endl;

	int dpi = 72;
	int width = 640;
	int height = 480;
	double aspectRatio = (double)width / (double)height;
	int n = width*height;
	RGBType* pixels = new RGBType[n];

	Vect origin = Vect();
	Vect X(1, 0, 0);
	Vect Y(0, 1, 0);
	Vect Z(0, 0, 1);
	
	Vect cameraPosition = Vect(3, 1.5, -4);
	Vect lookAt = Vect();

	Vect differenceBetween = cameraPosition - lookAt;
	Vect cameraDirection = differenceBetween.negative().normalize();
	Vect cameraRight = Y.crossProduct(cameraDirection).normalize();
	Vect cameraDown = cameraRight.crossProduct(cameraDirection).normalize();

	Camera sceneCamera = Camera(cameraPosition, cameraDirection, cameraRight, cameraDown);

	// Colors
	Color whiteLight = Color(1.0, 1.0, 1.0, 0.0);
	Color prettyGreen = Color(0.5, 1.0, 0.5, 0.3);
	Color gray = Color(0.5, 0.5, 0.5, 0.0);
	Color black = Color(0.0, 0.0, 0.0, 0.0);
	Color maroon = Color(0.5, 0.25, 0.25, 0);

	Vect lightPosition(-7, 10, -10);
	Light sceneLight = Light(lightPosition, whiteLight);

	// scene objects
	Sphere sphere1 = Sphere(origin, 1, prettyGreen);
	Plane plane1 = Plane(Y, -1, maroon);

	vector<Object*> sceneObjects;
	sceneObjects.push_back(dynamic_cast<Object*>(&sphere1));
	sceneObjects.push_back(dynamic_cast<Object*>(&plane1));

	int currentPixel;
	double xAmount, yAmount;

	// look at each pixel one at time and return a color
	for (int x = 0; x < width; x++) 
	{
		for (int y = 0; y < height; y++) 
		{
			// an indexing value that's gonna change as we go through the pixels
			// and is a value used to determine the x and y coordiantes of an individual pixel;
			currentPixel = y*width + x;

			// start with no anti-aliasing
			// offset a position from the camera direction to create rays that go to the left, right, above and below
			// of this direction
			if (width > height) 
			{
				// the image is wider than it is taller
				xAmount = ((x + 0.5) / width) * aspectRatio - (((width - height) / (double)height) / 2);
				yAmount = ((height - y) + 0.5) / height;
			}
			else if (height > width)
			{
				// the image is taller than it is wide
				xAmount = (x + 0.5) / width;
				yAmount = (((height - y) + 0.5) / height) / aspectRatio - (((height - width) / (double)width) / 2);
			}
			else
			{
				// the image is square
				xAmount = (x + 0.5) / width;
				yAmount = ((height - y) + 0.5) / height;
			}

			Vect cameraRayOrigin = sceneCamera.getPosition();
			Vect cameraRayDirection = cameraDirection + ( (cameraRight * (xAmount - 0.5)) + (cameraDown * (yAmount - 0.5)) );
			cameraRayDirection = cameraRayDirection.normalize();

			// This ray goes into the pixel and looks for intersections
			Ray cameraRay = Ray(cameraRayOrigin, cameraRayDirection);

			vector<double> intersections;

			for (auto object : sceneObjects)
			{
				intersections.push_back(object->findIntersection(cameraRay));
			}

			int indexOfNearestObject = nearestObjectIndex(intersections);

			// restrict the color to a specific portion of the image
			if ( (x > 200 && x < 440) && (y > 200 && y < 280)) 
			{
				pixels[currentPixel].r = 23;
				pixels[currentPixel].g = 222;
				pixels[currentPixel].b = 10;
			}
			else
			{
				pixels[currentPixel].r = 0;
				pixels[currentPixel].g = 0;
				pixels[currentPixel].b = 0;
			}
		}
	}

	saveBMP("scene.bmp", width, height, dpi, pixels);

	return 0;
}