#pragma once

//##################
#include "Sphere.h"
//##################

class Asteroid
{
private:
	float day;
	float dayInc;
	float year;
	float yearInc;
	float translate[3];

	bool doAuto = true;

	Sphere* asteroid;

public:

	Asteroid(float tx0, float tx1, float tx2);

	void Draw();
	static void SetTexture(char* filename);
};

