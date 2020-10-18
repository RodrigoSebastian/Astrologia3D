#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

//####################
#include "Planet.h"
#include "Disk.h"
//####################


Disk::Disk() {
	yearInc = 0.05f;
	dayInc = 0.25f;

	year = 0.0;
	day = 0.0;

	space = 0;

	initialX = 0;
	initialY = 0;
	initialZ = 0;
}

void Disk::DrawDisk() {
	glPushMatrix();
	glScaled(1.0, 0.01, 1.0);
	glRotated(90.0, 1.0, 0.0, 0.0);
	//glutWireTorus(0.15, 0.3, 10, 10);
	glutSolidTorus(.7, space + .3, 10, 30);
	glPopMatrix();
}

void Disk::ChangeInc(float _inc) {
	yearInc += _inc;
	dayInc += _inc;
}

void Disk::DoAuto(bool _doAuto) {
	doAuto = _doAuto;
}
bool Disk::doAuto = false;

void Disk::InitialPos(float _initialX, float _initialY, float _initialZ) {
	initialX = _initialX;
	initialY = _initialY;
	initialZ = _initialZ;
}

void Disk::Space(float _space) {
	space = _space;
}