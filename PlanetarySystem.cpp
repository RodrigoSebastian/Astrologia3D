#include "PlanetarySystem.h"
#include <Windows.h>
#include <GL/gl.h>
#include <string.h>
#include <glut.h>
#include <math.h>
#include "Sphere.h"

PlanetarySystem::PlanetarySystem(bool _earthSystem) {
	earthSystem = _earthSystem;
	mercury.SetSpeedAndTranslation(90, 0.0, 0.0, 5.0);
	venus.SetSpeedAndTranslation(65, 0.0, 0.0, 10.0);
	mars.SetSpeedAndTranslation(30, 0.0, 0.0, 20.0);
}

void PlanetarySystem::Draw() {
	glPushMatrix();
		glRotated(45, 0.0, 0.5, 0.5);

		if (earthSystem)
			earth.HaWireSphere(1.0);
		else
			sun.HaSolidSphere();

		mercury.HaSolidSphere();

		venus.HaSolidSphere();

		if (earthSystem) {
			sun.SetSpeedAndTranslation(45, 0.0, 0.0, 15.0);
			sun.HaSolidSphere();
		}
		else {
			earth.SetSpeedAndTranslation(45, 0.0, 0.0, 15.0);
			earth.HaSolidSphere();
		}

		mars.HaSolidSphere();

	glPopMatrix();
}
