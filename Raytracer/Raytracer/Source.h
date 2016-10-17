#pragma once
#include "Vect.h"
#include "Color.h"

class Source
{
public:
	Source();
	virtual Vect getPosition();
	virtual Color getColor();
};