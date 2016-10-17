#pragma once

#include "math.h";
#include <iostream>;


class Vect {
	double x, y, z;

public:
	Vect();
	Vect(double, double, double);

	// methods
	double getX();
	double getY();
	double getZ();
	
	double magnitude();
	Vect normalize();
	Vect negative();
	
	// returns a vector that is orthogonal to the two vectors
	Vect crossProduct(Vect);

	// operator overloading for vector operations
	Vect operator+(Vect);
	Vect operator-(Vect);
	
	// performs the dot product on two vectors
	double operator*(Vect);

	// performs scalar multiplication 
	friend Vect operator*(double, Vect);
	friend Vect operator*(Vect, double);
	// For printing vectors
	friend std::ostream& operator<<(std::ostream&, const Vect);
};
