#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

//###################
#include "Planet.h"
#include "Moon.h"
#include "Disk.h"
//###################

static RGBpixmap myText[1];
static GLuint name[1];

Moon::Moon() {
	yearInc = 0.1f;
	dayInc = 0.5f;

	year = 0.0;
	day = 0.0;

	space = 0;

	initialX = 0;
	initialY = 0;
	initialZ = 0;

	glGenTextures(1, name);

	myText[0].readBMPFile((char*)"moon.bmp");
	myText[0].SetTexture(name[0]);

	moon = new Sphere(1.0);
	moon->SetTexture(&name[0]);
}

void Moon::DrawMoon() {
	glPushMatrix();
	if (seeOrbits)
		glutWireTorus(space, 0.0, 40, 1);
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	glTranslated(initialX, initialY, initialZ);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	moon->HaSolidSphere();
	glPopMatrix();

	if (doAuto) {
		year = (GLfloat)(((GLint)(year * 100.f + yearInc * 100.f)) % 36000) / 100.0f;
		day = (GLfloat)(((GLint)(day * 100.f + dayInc * 100.f)) % 36000) / 100.0f;
	}
}

void Moon::ChangeInc(float _inc) {
	yearInc += _inc;
	dayInc += _inc;
}

void Moon::DoAuto(bool _doAuto) {
	doAuto = _doAuto;
}
bool Moon::doAuto = false;

void Moon::SeeOrbits(bool _seeOrbits) {
	seeOrbits = _seeOrbits;
}

bool Moon::seeOrbits = false;

void Moon::InitialPos(float _initialX, float _initialY, float _initialZ) {
	initialX = _initialX;
	initialY = _initialY;
	initialZ = _initialZ;
}

void Moon::Space(float _space) {
	space = _space;
}