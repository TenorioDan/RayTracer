#include "Ray.h"

Ray::Ray() 
	: origin(Vect()), direction(Vect(1, 0, 0))
{
}

Ray::Ray(Vect o, Vect d)
	: origin(o), direction(d)
{
}

Vect Ray::getOrigin() 
{ 
	return origin; 
}

Vect Ray::getDirection() 
{ 
	return direction; 
}