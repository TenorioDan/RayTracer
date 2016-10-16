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
	Vect getPosition() { return position; }
	Vect getDirection() { return direction; }
	Vect getRight() { return right; }
	Vect getDown() { return down; }
};

Camera::Camera()
{
	position = Vect(0, 0, 0);
	direction = Vect(0, 0, 1);
	right = Vect(0, 0, 0);
	down = Vect(0, 0, 0);
}

Camera::Camera(Vect pos, Vect dir, Vect r, Vect d)
{
	position = pos;
	direction = dir;
	right = r;
	down = d;
}