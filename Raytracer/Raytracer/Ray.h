#pragma once

#include "vect.h";

class Ray {
	Vect origin, direction;

public:
	Ray();
	Ray(Vect, Vect);

	// methods
	Vect getOrigin();
	Vect getDirection();
};