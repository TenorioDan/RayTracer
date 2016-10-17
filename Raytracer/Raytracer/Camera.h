#pragma once

#include "Vect.h";

class Camera
{
	// Every camera is composed of these four vectors
	Vect position, direction, right, down;

public: 
	Camera();
	Camera(Vect, Vect, Vect, Vect);

	// methods
	Vect getPosition();
	Vect getDirection();
	Vect getRight();
	Vect getDown();
};

