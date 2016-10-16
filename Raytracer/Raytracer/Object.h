#pragma once

#include "Ray.h";
#include "Vect.h";
#include "Color.h";

class Object
{
public:
	Object();

	Color getColor() { return Color(0.0, 0.0, 0.0, 0.0); }
	double findIntersection(Ray);

};