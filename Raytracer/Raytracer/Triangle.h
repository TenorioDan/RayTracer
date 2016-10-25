#pragma once

#include "Vect.h";
#include "Color.h";
#include "Object.h"

class Triangle : public Object
{
	Vect A, B, C;
	Vect normal;
	double distance;
	Color color;

public:
	Triangle();
	Triangle(Vect, Vect, Vect, Color c);

	// methods
	Vect getNormal();
	double getDistance();

	Color getColor() override;
	Vect getNormalAt(Vect) override;
	double findIntersection(Ray) override;

};