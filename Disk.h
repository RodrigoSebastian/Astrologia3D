#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

//#################
#include "Planet.h"
#include "Moon.h"
#include "Disk.h"
//#################

class Disk {
private:
	float year;
	float day;
	float yearInc;
	float dayInc;

	float initialX;
	float initialY;
	float initialZ;

	float space;

	static bool doAuto;

public:
	Disk();
	void DrawDisk();
	void ChangeInc(float);
	static void DoAuto(bool);
	void InitialPos(float, float, float);
	void Space(float);
};