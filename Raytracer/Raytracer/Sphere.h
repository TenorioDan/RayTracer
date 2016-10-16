#pragma once
#include "Vect.h";
#include "Color.h";
#include "Object.h"

class Sphere : Object
{
	Vect center;
	double radius;
	Color color;

public:
	Sphere();
	Sphere(Vect, double, Color);

	// methods
	Vect getCenter() { return center; }
	double getRadius() { return radius; }
	Color getColor() { return color; }

};