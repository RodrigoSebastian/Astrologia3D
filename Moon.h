#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

//#################
#include "Sphere.h"
#include "Planet.h"
#include "Moon.h"
#include "Disk.h"
//#################

class Moon {
private:
	Sphere* moon;

	float year;
	float day;
	float yearInc;
	float dayInc;

	float initialX;
	float initialY;
	float initialZ;

	float space;

	static bool doAuto;
	static bool seeOrbits;

public:

	Moon();
	void DrawMoon();
	void ChangeInc(float);
	void InitialPos(float, float, float);
	void Space(float);
	static void DoAuto(bool);
	static void SeeOrbits(bool);
};