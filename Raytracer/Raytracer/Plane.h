#pragma once
#include "Vect.h";
#include "Color.h";
#include "Object.h"

class Plane : public Object
{
	Vect normal;
	double distance;
	Color color;

public:
	Plane();
	Plane(Vect, double, Color);

	// methods
	Vect getNormal() { return normal; }
	double getDistance() { return distance; }
	Color getColor() { return color; }
	
	Vect getNormalAt(Vect);
	double findIntersection(Ray);

};