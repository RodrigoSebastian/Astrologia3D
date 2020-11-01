#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

//#####################
#include "Cubemap.h"
#include "RGBpixmap.h"
//#####################

Cubemap::Cubemap(float _size) {
	size = _size;
	glGenTextures(1, &name);
}

void Cubemap::SetTexture(char* fname) {
	myText[0].readBMPFile(fname);
	myText[0].SetTexture(name);
}

void Cubemap::Draw() {
	glPushMatrix();
	glRotated(-35, 1.0, 0.0, 0.0);
		glBindTexture(GL_TEXTURE_2D, name);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

			glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 0.0);
			glVertex3f(-750,	-250,	-450);
		glTexCoord2f(1.0, 0.0);
			glVertex3f(750,		-250,	-450);
		glTexCoord2f(1.0, 1.0);
			glVertex3f(750,		 520,	-450);
		glTexCoord2f(0.0, 1.0);
			glVertex3f(-750,	 520,	-450);

		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}