#include "Camera.h"

Camera::Camera()
	: position(Vect()), direction(Vect(0, 0, 1)), right(Vect()), down(Vect())
{
}

Camera::Camera(Vect pos, Vect dir, Vect r, Vect d)
	: position(pos), direction(dir), right(r), down(d)
{
}

Vect Camera::getPosition() 
{ 
	return position; 
}

Vect Camera::getDirection() 
{ 
	return direction; 
}

Vect Camera::getRight() 
{ 
	return right; 
}

Vect Camera::getDown() 
{ 
	return down; 
}