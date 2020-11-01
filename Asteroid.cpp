#include "Asteroid.h"

//##################
#include "RGBpixmap.h"
#include "Sphere.h"
//##################

static RGBpixmap myText[1];
static GLuint name[1];

Asteroid::Asteroid(float tx0, float tx1, float tx2) {
	translate[0] = tx0;
	translate[1] = tx1;
	translate[2] = tx2;
	asteroid = new Sphere(0.9);
	asteroid->SetTexture(&name[0]);
}

void Asteroid::SetTexture(char * filename) {
	glGenTextures(1, name);
	myText[0].readBMPFile(filename);
	myText[0].SetTexture(name[0]);
}

void Asteroid::Draw() {
	glPushMatrix();
		glRotated((GLfloat)year, 0.0, 1.0, 0.0);
		glTranslated(translate[0], translate[1], translate[2]);
		glRotated((GLfloat)day, 0.0, 1.0, 0.0);

		asteroid->HaSolidSphere();

		if (doAuto) {
			year = (GLfloat)(((GLint)(year * 100.f + yearInc * 100.f)) % 36000) / 100.0f;
			day = (GLfloat)(((GLint)(day * 100.f + dayInc * 100.f)) % 36000) / 100.0f;
		}
	glPopMatrix();
}
