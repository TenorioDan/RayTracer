#pragma once

#include "math.h";
#include <iostream>;


class Vect {
	double x, y, z;

public:
	Vect();
	Vect(double, double, double);

	// methods
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
	
	double magnitude();
	Vect normalize();
	Vect negative();
	
	// returns a vector that is orthogonal to the two vectors
	Vect crossProduct(Vect v);

	// operator overloading for vector operations
	Vect operator+(Vect v);
	Vect operator-(Vect v);
	
	// performs the dot product on two vectors
	double operator*(Vect v);

	// performs scalar multiplication 
	friend Vect operator*(double s, Vect v);
	friend Vect operator*(Vect v, double s);
	// For printing vectors
	friend std::ostream& operator<<(std::ostream& os, const Vect v);
};
