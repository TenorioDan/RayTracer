#pragma once
#include "Vect.h"
#include "Color.h"

class Source
{
public:
	Source();
	virtual Vect getPosition() { return Vect(); }
	virtual Color getColor() { return Color(1, 1, 1, 0); }
};