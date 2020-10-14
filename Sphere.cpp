#include <Windows.h>
#include <GL/gl.h>
#include <string.h>
#include <glut.h>
#include <math.h>
#include "Sphere.h"

Sphere::Sphere(float _r) {
	radius = _r;
}

Sphere::Sphere() {
	radius = 1;
}

void Sphere::SetSpeedAndTranslation(float _speed, float t0, float t1, float t2) {
	speed = _speed;
	translate[0] = t0;
	translate[1] = t1;
	translate[2] = t2;
}

void Sphere::LogicSphere() {
	for (int i = 0; i < slices + 1; i++) {
		float lon = Map(i, 0, slices, -PI, PI);

		for (int j = 0; j < stacks + 1; j++) {
			float lat = Map(j, 0, stacks, -PI / 2, PI / 2);
			float x = radius * sin(lon) * cos(lat);
			float y = radius * sin(lon) * sin(lat);
			float z = radius * cos(lon);

			points[i][j][0] = x;
			points[i][j][1] = y;
			points[i][j][2] = z;
		}
	}
	finishCalc = true;
}

void Sphere::DoRotation() {
	//year = (GLfloat)(((GLint)(year * 100.f + speed * 100.f)) % 36000) / 100.0f;
	year += speed / 360;
	if (year >= 360)
		year -= 360;
	glRotated(year, 0.0, 1.0, 0.0);
}

void Sphere::HaSolidSphere() {
	if (!finishCalc) {
		LogicSphere();
	}
	else {
		glPushMatrix();
		DoRotation();
		glTranslated(translate[0], translate[1], translate[2]);
		for (int i = 0; i < slices; i++)
			for (int j = 0; j < stacks; j++) {
					glBegin(GL_TRIANGLES);
						glColor3f(1.0, 1.0, 1.0);
						glVertex3fv(points[i][j]);
						glVertex3fv(points[i + 1][j]);
						glVertex3fv(points[i + 1][j + 1]);
					glEnd();
					glBegin(GL_TRIANGLES);
						glColor3f(0.5, 0.5, 0.5);
						glVertex3fv(points[i + 1][j + 1]);
						glVertex3fv(points[i][j + 1]);
						glVertex3fv(points[i][j]);
					glEnd();
			}
		glPopMatrix();
	}
}

void Sphere::HaWireSphere(float _pointSize) {
	if (!finishCalc) {
		LogicSphere();
	}
	else {
		glPushMatrix();
		for(int i = 0; i < slices; i ++)
			for (int j = 0; j < stacks; j++) {
				glPointSize(_pointSize);
				glBegin(GL_POINTS);
					glColor3f(1.0, 1.0, 1.0);
					glVertex3fv(points[i][j]);
				glEnd();
			}
		glPopMatrix();
	}
}
