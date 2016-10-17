#pragma once
#include <iostream>;

class Color
{
	double red, green, blue, special;

public:
	Color();
	Color(double, double, double, double);
	double getRed() { return red; }
	double getGreen() { return green; }
	double getBlue() { return blue; }
	double getSpecial() { return special; }

	double setRed(double value) { red = value; return red; }
	double setGreen(double value) { green = value;  return green; }
	double setBlue(double value) { blue = value;  return blue;  }
	double setSpecial(double value) { special = value;  return special;  }

	double brightness();
	Color scaleColor(double);
	Color colorAverage(Color);
	Color clip();

	// operator overloading
	Color operator+(Color);
	Color operator-(Color);
	Color operator*(Color);
	friend std::ostream& operator<<(std::ostream& os, const Color c);
};