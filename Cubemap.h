#pragma once
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;

#include <fstream>

//#############################
#include "RGBpixmap.h"
//############################

class Cubemap
{
private:

	RGBpixmap myText[1];
	GLuint name;
	float size = 150;

public:
	Cubemap(float);

	void SetTexture(char* fname);
	void Draw();
};

