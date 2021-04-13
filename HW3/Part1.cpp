

// house.cpp
#include <windows.h>
#include <iostream>
#include <GL/glut.h>

void display() {
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);
	/* draw scene */
	glPushMatrix();


	

	// light parameters 
	GLfloat light0_ambient[] = { 0.6, 0.6, 0.6, 1.0 };
	GLfloat light0_diffuse[] = { 0.6, 0.6, 0.6, 1.0 };
	GLfloat light0_specular[] = { 0.6, 0.6, 0.6, 1.0 };
	GLfloat light0_position[] = { 1.0f, 1.0f, 1.0f, 1.0 };

	// set ;ight parameters and enable light 
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	glEnable(GL_LIGHT0);

	//set material 
	GLfloat ambientLight[] = { 0.10588, 0.058824, 0.0113725 };
	GLfloat diffuseLight[] = { 0.427451, 0.470588, 0.541176 };
	GLfloat specularLight[] = { 0.3333, 0.3333, 0.521569 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseLight);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);

	// house
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(2); // building
	glPopMatrix();
	
	// roof	
	glPushMatrix();
	glColor3f(0.835, 0.298, 0.980);
	glTranslatef(0.0, 1.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glutSolidCone(1.5, 1, 16, 8);	
	glPopMatrix();
	
	// chimney		
	glPushMatrix();
	glColor3f(0.478, 0.313, 0);
	glTranslatef(1.25, 2.0, 0.0);	
	glScaled(1.0, 2.5, 1.0);
	glutSolidCube(.25);
	glPopMatrix();

	// window
	glPushMatrix();
	glColor3f(0.196, 0.905, 0.890);
	glTranslatef(0.0, 0.0, 0.92);
	glScaled(2.0, 2.0, 0.75);
	glutSolidCube(.25);
	glPopMatrix();

	// door
	glPushMatrix();
	glColor3f(0.905, 0.647, 0.196);
	glTranslatef(0.93, -0.5, 0.0);
	glScaled(0.75, 4.0, 2.0);
	glutSolidCube(.25);
	glPopMatrix();


	// snow
	glPushMatrix();
	glColor3f(0.796, 0.925, 0.921);
	glTranslatef(0.0, -1.0, 0.0);
	glScaled(0.75, 4.0, 2.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidCone(8.0, 0.01, 16, 8);
	glPopMatrix();



	// car
	
	// body
	glPushMatrix();
	glColor3f(0.329, 0.298, 0.980);
	glTranslatef(0.5, 0.2, 2.5);
	glScaled(2.0, 0.5, 1.0);
	glutSolidCube(.5);
	glPopMatrix();	

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.1, 0.0, 2.75);
	glutSolidTorus(.05, .1, 8, 8); // wheel
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.85, 0.0, 2.75);
	glutSolidTorus(.05, .1, 8, 8); // wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.85, 0.0, 2.25);
	glutSolidTorus(.05, .1, 8, 8); // wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, 0.0, 2.25);
	glutSolidTorus(.05, .1, 8, 8); // wheel
	glPopMatrix();

	// snowman

	//big snow ball
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(3.0, 0.0, 1.0);	
	glutSolidSphere(0.2, 32, 8);
	glPopMatrix();

	//medium snow ball
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(3.0, 0.5, 1.1);
	glutSolidSphere(0.15, 32, 8);
	glPopMatrix();

	//small snow ball
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(3.0, 0.8, 1.15);
	glutSolidSphere(0.1, 32, 8);
	glPopMatrix();

	//carrot
	glPushMatrix();
	glColor3f(0.905, 0.447, 0.196);
	glTranslatef(3.0, 0.8, 1.2);
	glRotatef(0.0, 1.0, 0.0, 0.0);
	glutSolidCone(0.02, 0.15, 16, 8);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(3.05, 0.9, 1.25);
	glutSolidSphere(0.02, 32, 8);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(2.98, 0.88, 1.25);
	glutSolidSphere(0.02, 32, 8);
	glPopMatrix();
	
	glPopMatrix();
	glPopMatrix();
	/* flush drawing routines to the window */
	glFlush();
}
void reshape(int width, int height) {
	/* define the viewport transformation */
	glViewport(0, 0, width, height);
}
int main(int argc, char* argv[]) {
	/* initialize GLUT, using any commandline parameters passed to the

	program */
	glutInit(&argc, argv);
	/* setup the size, position, and display mode for new windows */
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	/* create and set up a window */
	glutCreateWindow("hello, house!");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);
	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
	// Enable shading
	glShadeModel(GL_SMOOTH); // GL_FLAT is a rough shading 

	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);
	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/* tell GLUT to wait for events */
	glutMainLoop();
	return 0;
}