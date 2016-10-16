#pragma once

#include "Ray.h";
#include "Vect.h";
#include "Color.h";

class Object
{
public:
	Object();

	virtual Color getColor() { return Color(0.0, 0.0, 0.0, 0.0); }
	virtual Vect getNormalAt(Vect);
	virtual double findIntersection(Ray);

};