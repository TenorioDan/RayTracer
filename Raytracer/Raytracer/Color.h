#pragma once

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

	double setRed(double value) { red = value; }
	double setGreen(double value) { green = value; }
	double setBlue(double value) { blue = value; }
	double setSpecial(double value) { special = value; }
};