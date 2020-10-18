#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <time.h>
#include <math.h>

//#######################
#include "Sphere.h"
#include "Planet.h"
#include "Moon.h"
#include "Disk.h"
//#######################

					//    Separación	    Coordenas random
Planet planets[8];  //    con el sol	 sobre la circunferencia                       
float posInicial[8][3] = { {08.0,			0.0,		0.0},
							{11.0,			0.0,		0.0},
							{15.0,			0.0,		0.0},
							{19.0,			0.0,		0.0},
							{24.0,			0.0,		0.0},
							{31.0,			0.0,		0.0},
							{35.0,			0.0,		0.0},
							{39.0,			0.0,		0.0} };

static bool doAuto = false;
static bool seeOrbits = false;

//Asignar coordenadas random dentro de sus orbitas
void reColocar() {
	for (int planeta = 0; planeta < 8; planeta++) {
		float angulo = 1 + rand() % 360;
		posInicial[planeta][1] = cos(angulo) * posInicial[planeta][0];
		posInicial[planeta][2] = sin(angulo) * posInicial[planeta][0];
	}
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	planets[0] = Planet(0, 0, 0.6, 0.15f, 0.25f);
	planets[1] = Planet(1, 0, 1.0, 0.13f, 0.23f);
	planets[2] = Planet(0, 0, 0.8, 0.11f, 0.21f);
	planets[3] = Planet(2, 0, 0.75, 0.09f, 0.19f);
	planets[4] = Planet(5, 0, 2.5, 0.07f, 0.17f);
	planets[5] = Planet(2, 1, 2.0, 0.05f, 0.15f);
	planets[6] = Planet(2, 0, 1.2, 0.03f, 0.13f);
	planets[7] = Planet(1, 0, 0.8, 0.02f, 0.11f);

	reColocar();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glPushMatrix();
	glRotated(22.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(5.0, 40, 40);

	for (int i = 0; i < 8; i++) {
		switch (i) {
		case 0:
			glColor3f(1.0, 0.0, 0.0);
			break;
		case 1:
			glColor3f(1.0, 0.5, 0.0);
			break;
		case 2:
			glColor3f(0.69, 1.0, 1.0);
			break;
		case 3:
			glColor3f(0.3, 0.0, 0.0);
			break;
		case 4:
			glColor3f(0.76, 0.34, 0.19);
			break;
		case 5:
			glColor3f(0.95, 0.64, 0.37);
			break;
		case 6:
			glColor3f(0.21, 0.76, 1.0);
			break;
		case 7:
			glColor3f(0.0, 0.39, 0.56);
			break;
		}

		planets[i].DrawPlanet(posInicial[i][0], posInicial[i][1], posInicial[i][2]);
	}

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 40.0, 55.0, 0.0, -9.0, 0.0, 0.0, 1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a':
	case 'A':
		// Toggle automatic movement of planet
		if (doAuto)
			doAuto = false;
		else
			doAuto = true;
		planets->DoAuto(doAuto);
		break;
	case 'r':
	case 'R':
		// Change the planets position
		reColocar();
		glutPostRedisplay();
		break;
		// Manual control of day and year movement
	case 's':
	case 'S':
		// Toggle visibility of the orbits
		if (seeOrbits)
			seeOrbits = false;
		else
			seeOrbits = true;
		planets->SeeOrbits(seeOrbits);
		break;
	case 0x1B:
	case 'q':
	case 'Q':
		exit(0);
		break;
	default:
		break;
	}
}

void mouse(int btn, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		// Make the year move faster
		if (btn == GLUT_LEFT_BUTTON)
			for (int i = 0; i < 8; i++)
				planets[i].ChangeInc(0.02);


		// Make the day move faster
		else if (btn == GLUT_RIGHT_BUTTON)
			for (int i = 0; i < 8; i++)
				planets[i].ChangeInc(-0.02);


		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{

	srand(time(NULL));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar System Example");
	init();

	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	glutMainLoop();
	return 0;
}
