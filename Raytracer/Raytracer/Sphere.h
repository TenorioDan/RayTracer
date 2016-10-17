#pragma once
#include "Vect.h";
#include "Color.h";
#include "Object.h"

class Sphere : public Object
{
	Vect center;
	double radius;
	Color color;

public:
	Sphere();
	Sphere(Vect, double, Color);

	// methods
	Vect getCenter();
	double getRadius();

	Color getColor()  override;
	Vect getNormalAt(Vect) override;
	double findIntersection(Ray) override;

};