#pragma once
#include <iostream>;

class Color
{
	double red, green, blue, special;

public:
	Color();
	Color(double, double, double, double);
	double getRed();
	double getGreen();
	double getBlue();
	double getSpecial();

	double setRed(double value);
	double setGreen(double value);
	double setBlue(double value);
	double setSpecial(double value);

	double brightness();
	Color scaleColor(double);
	Color colorAverage(Color);
	Color clip();

	// operator overloading
	Color operator+(Color);
	Color operator-(Color);
	Color operator*(Color);
	friend std::ostream& operator<<(std::ostream&, const Color);
};