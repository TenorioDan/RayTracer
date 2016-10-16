#include <iostream>

using namespace std;

/*
* A ray tracer is a program that produces an image where each pixel in that image has a color
* and the color of the pixel needs to correspond to the color of an object in the scene
*/

int main(int argc, char *argv[])
{
	cout << "rendering..." << endl;

	int width = 640;
	int height = 490;

	// look at each pixel one at time and return a color
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			// return color 
		}
	}

	return 0;
}