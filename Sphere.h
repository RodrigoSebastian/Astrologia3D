#pragma once
#define _USE_MATH_DEFINES
#define PI 3.1416
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;

#include <fstream>
#include <stdio.h>

using namespace std;

//###################
#include "RGBpixmap.h"
//###################

class Sphere
{
private:
	RGBpixmap myText[1];
	GLuint name, * paramName;

	float radius = 1;
	float speed = 0.05;
	float year;
	float translate[3] = { 0.0, 0.0, 0.0 };
	float points[15 + 1][15 + 1][3];
	float normals[15 + 1][15 + 1][3];

	int stacks = 15;
	int slices = 15;
	int texture = 0;

	bool finishCalc = false;

	void DoRotation();
	void LogicSphere();
	//void LogicNormals();

	float Map(float value, float start1, float stop1, float start2, float stop2) {
		return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
	}

public:
	Sphere();
	Sphere(float);

	void HaSolidSphere();
	void SetTexture(char*);
	void SetTexture(GLuint*);
	void HaWireSphere(float _pointSize);
	void SetSpeedAndTranslation(float _speed, float t0, float t1, float t2);
};