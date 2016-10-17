#include "Light.h"

Light::Light()
	: position(Vect()), color(Color(1, 1, 1, 0))
{
}

Light::Light(Vect pos, Color c)
	: position(pos), color(c)
{
}

Vect Light::getPosition() 
{ 
	return position; 
}

Color Light::getColor() 
{ 
	return color; 
}