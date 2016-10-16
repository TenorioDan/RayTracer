#pragma once

#include "Vect.h";
#include "Color.h";

class Light
{
	Vect position;
	Color color;

public:
	Light();
	Light(Vect, Color);

	// methods
	virtual Vect getPosition() { return position; }
	virtual Color getColor() { return color; }

};