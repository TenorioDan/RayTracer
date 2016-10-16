#include "Sphere.h";

Sphere::Sphere()
	: center(Vect()), radius(1.0), color(Color())
{

}

Sphere::Sphere(Vect c, double r, Color col)
	: center(c), radius(r), color(col)
{

}

Vect Sphere::getNormalAt(Vect point)
{
	return (point - center).normalize();
}

double Sphere::findIntersection(Ray ray)
{
	Vect rayOrigin = ray.getOrigin();
	double rayOriginX = rayOrigin.getX();
	double rayOriginY = rayOrigin.getY();
	double rayOriginZ = rayOrigin.getZ();

	Vect rayDirection = ray.getDirection();
	double rayDirX = rayDirection.getX();
	double rayDirY = rayDirection.getY();
	double rayDirZ = rayDirection.getZ();

	double sphereCenterX = center.getX();
	double sphereCenterY = center.getY();
	double sphereCenterZ = center.getZ();

	// find values for the qaudratic formula
	double a = 1; // normalized
	double b =    (2 * (rayOriginX - sphereCenterX) * rayDirX) 
				+ (2 * (rayOriginY - sphereCenterY) * rayDirY)
				+ (2 * (rayOriginZ - sphereCenterZ) * rayDirZ);
	double c = pow(rayOriginX - sphereCenterX, 2) + pow(rayOriginY - sphereCenterY, 2) + pow(rayOriginZ - sphereCenterZ, 2) - (radius*radius);
	double discriminant = b*b - 4*a*c;

	//std::cout << discriminant << endl;

	if (discriminant > 0) 
	{
		// the ray intersects the sphere
		// the first root
		double root_1 = ((-b - sqrt(discriminant)) / (2 * a)) - 0.000001;

		if (root_1 > 0)
		{
			// the first root is the smallest positive root
			return root_1;
		}
		else
		{
			// the second root is the smallest positive root
			double root_2 = ((sqrt(discriminant) - b) / 2);
			return root_2;
		}
	}
	else
	{
		// the ray missed the sphere
		return -1;
	}

}