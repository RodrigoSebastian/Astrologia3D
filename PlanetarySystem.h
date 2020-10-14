#pragma once
#include "Sphere.h"
class PlanetarySystem
{
private:
	Sphere sun, mercury, venus, mars ,earth, jupiter, saturn, uranus, neptune, pluton;
	bool earthSystem = true;

public:
	PlanetarySystem(bool);
	void Draw();
};

