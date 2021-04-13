#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#define W 1000
#define H 1000

double rotation = 0.0;

void displaySolid(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-W, W, -H, H, -W, W);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Turning on the lights code to be placed WHERE ? ? ?
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	//Direction / intensity of the light.
	GLfloat lightPosition[] = { 0.0f,0.0f,100.0f, 0.0f };
	GLfloat lightIntensity[] = { 0.9f, 0.9f, 0.9f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	//Add ambient light.
	//Materials.
	GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.6f, 1.0f };
	GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 90.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	
	GLfloat mat_ambient1[] = { 0.5f, 0.5f, 0.6f, 1.0f };
	GLfloat mat_diffuse1[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat mat_specular1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess1[] = { 90.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
	
	glEnable(GL_COLOR_MATERIAL);	
	

	int T_SIZE = W / 14;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			glPushMatrix();
			glColor3f(0.2 + i*0.1, 1.0 - j*0.1, 0.6);
			glTranslatef(-W + (W / 4) * i + 1.5 * T_SIZE, H - 1.5*T_SIZE - j*(H/4), 0.0);
			glRotatef(rotation, 0, 1, 0);
			glutSolidTeapot(T_SIZE);
			glPopMatrix();
		}		
	}

	
	glFlush();
	glutSwapBuffers();
}


void rotateTeapots(int a)
{
	// increment rotation angle
	rotation += 3.0;

	// call function again with delay
	
	glutTimerFunc(16, rotateTeapots, 0);

	// recall display function
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My Teapot");
	glutTimerFunc(1, rotateTeapots, 0);
	glutDisplayFunc(displaySolid);
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	glViewport(0, 0, W, H);
	glutMainLoop();
	return 1;
}


