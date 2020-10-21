#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

//####################
#include "mRGB.h"
//####################

typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;

class RGBpixmap
{
private:
	fstream inf;
public:
	int nRows, nCols;
	mRGB* pixel;

	float gr, gg, gb;

	void MakeCheckerBoard();
	void MakeShadedCircle();
	void MakeRandom();
	int readBMPFile(char* fname);

	ushort getShort();
	ulong getLong();
	void SetTexColor(float rin, float gin, float bin);
	void SetTexture(GLuint textureName);
};

