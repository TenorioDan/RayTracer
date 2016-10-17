#pragma once

#include "Vect.h";
#include "Color.h";
#include "Source.h"

class Light : public Source
{
	Vect position;
	Color color;

public:
	Light();
	Light(Vect, Color);

	// methods
	Vect getPosition() override;
	Color getColor() override;

};