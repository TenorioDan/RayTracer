#include "Vect.h"

Vect::Vect() 
	: x(0), y(0), z(0)
{
}

Vect::Vect(double i, double j, double k)
	: x(i), y(j), z(k)
{
}


double Vect::magnitude()
{
	return sqrt((x*x) + (y*y) + (z*z));
}

// A vector is 
Vect Vect::normalize()
{
	double magnitude = this->magnitude();
	return Vect(x / magnitude, y / magnitude, z / magnitude);
}

Vect Vect::negative()
{
	return Vect(-x, -y, -z);
}

Vect Vect::crossProduct(Vect v)
{
	return Vect(
		y*v.getZ() - z*v.getY(), 
		z*v.getX() - x*v.getZ(), 
		x*v.getY() - y*v.getX()
	);
}

Vect Vect::operator+(Vect v)
{
	return Vect(x + v.getX(), y + v.getY(), z + v.getZ());
}

Vect Vect::operator-(Vect v)
{
	return *this + v.negative();
}

double Vect::operator*(Vect v)
{
	return x*v.getX() + y*v.getY() + z*v.getZ();
}

Vect Vect::operator*(double s)
{
	return Vect(s*x, s*y, s*z);
}

std::ostream& operator<<(std::ostream& os, Vect v)
{
	return os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
}