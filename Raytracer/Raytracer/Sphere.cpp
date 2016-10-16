#include "Sphere.h";

Sphere::Sphere()
	: center(Vect()), radius(1.0), color(Color())
{

}

Sphere::Sphere(Vect c, double r, Color col)
	: center(c), radius(r), color(col)
{

}