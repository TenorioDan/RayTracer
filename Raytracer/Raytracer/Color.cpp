#include "Color.h";

Color::Color()
	: red(0.5), green(0.5), blue(0.5), special(0)
{
}

Color::Color(double r, double g, double b, double s)
	: red(r), green(g), blue(b), special(s)
{
}

double Color::brightness()
{
	return (red + green + blue) / 3;
}

Color Color::scaleColor(double scalar)
{
	return Color(red * scalar, green * scalar, blue * scalar, special);
}

Color Color::colorAverage(Color color)
{
	return Color((red + color.getRed()) / 2, (green + color.getGreen()) / 2, (blue + color.getBlue()) / 2, special);
}

Color Color::clip()
{
	double allLight = red + green + blue;
	double excessLight = allLight - 3;
	if (excessLight > 0)
	{
		red += excessLight * (red / allLight);
		green += excessLight * (green / allLight);
		blue += excessLight * (blue / allLight);
	}

		if (red > 1) { red = 1; }
		if (green > 1) { green = 1; }
		if (blue > 1) { blue = 1; }
		if (red < 0) { red = 0; }
		if (green < 0) { green = 0; }
		if (blue < 0) { blue = 0; }

		return Color(red, green, blue, special);

}

Color Color::operator+(Color c)
{
	return Color(red + c.getRed(), green + c.getGreen(), blue + c.getBlue(), special);
}

Color Color::operator-(Color c)
{
	return Color(red - c.getRed(), green - c.getGreen(), blue - c.getBlue(), special);
}

Color Color::operator*(Color c)
{
	return Color(red * c.getRed(), green * c.getGreen(), blue * c.getBlue(), special);
}

std::ostream& operator<<(std::ostream& os, Color c)
{
	return os << "(" << c.getRed() << ", " << c.getGreen() << ", " << c.getBlue() << ")";
}