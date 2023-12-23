#include<stdlib.h>
#include<glut.h>
float w = 480, h = 480;
float sudut = 0, sx = 0, sy = 0, sz = 0;
void torus(){
	glColor3d(0, 0, 1);
	/*glutWireCube(10);*/ // fungsi disamping adalah bentuk pendeklarasian fungsi “Cube”
	glutWireTorus(2, 12, 36, 50);
}
void Teapot() {
	glColor3d(1, 0, 0);
	/*glutWireCube(10);*/ // fungsi disamping adalah bentuk pendeklarasian fungsi “Cube”
	glutWireTeapot(5);
}

void cube(){
	glColor3f(0.5, 0.5, 0);
	/*glutWireCube(10);*/ // fungsi disamping adalah bentuk pendeklarasian fungsi “Cube”
	glutWireCube(15);

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -40);
	glRotatef(sudut, sx, sy, sz);
	cube();
	Teapot();
	torus();


	glutSwapBuffers();
}
void resize(int w1, int h1) {
	glViewport(0, 0, w1, h1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45., (GLdouble)w / (GLdouble)h, 1., 300.);
	glMatrixMode(GL_MODELVIEW);
}
void myKeyboard(unsigned char key, int x, int y) {
	if (key == 'x') {
		sx = 1;
		sy = 0;
		sz = 0;
		sudut += 10;
	}
	else if (key == 'y') {
		sx = 0;
		sy = 1;
		sz = 0;
		sudut += 10;
	}
	else if (key == 'z') {
		sx = 0;
		sy = 0;
		sz = 1;
		sudut += 10;
	}
}
void update(int value) {
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

