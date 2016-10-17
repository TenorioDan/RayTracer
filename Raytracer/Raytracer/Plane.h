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
	Vect getNormal();
	double getDistance();

	Color getColor() override;
	Vect getNormalAt(Vect) override;
	double findIntersection(Ray) override;

};