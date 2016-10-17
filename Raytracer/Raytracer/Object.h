#pragma once

#include "Ray.h";
#include "Vect.h";
#include "Color.h";

class Object
{
public:
	Object();

	virtual Color getColor();
	virtual Vect getNormalAt(Vect);
	virtual double findIntersection(Ray);

};