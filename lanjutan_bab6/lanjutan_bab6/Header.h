#include <stdlib.h>
#include <glut.h>
int objek;
using namespace std;

float w = 500, h = 500;
float sudut = 0, sx = 0, sy = 0, sz = 0;
float zoomFactor = 1.0;
float rotationSpeed = 3.0;
bool rotateLeft = false;
bool rotateRight = false;
float a = 0.7;
void setMaterial(){
	GLfloat mat_ambient[] = {
		0.7f, 0.7f, 0.7f, 1.0f
	};
	GLfloat mat_diffuse[] = {
		0.6f, 0.6f, 0.6f, 1.0f
	};
	GLfloat mat_specular[] = {
		0.0f, 1.0f, 1.0f, 1.0f
	};
	GLfloat mat_shininess[] = { 50.0f };
	//membuat parameter yg mempunyai value RGBA
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setLighting(){
	GLfloat lightIntensity[] = {
		0.0f, 0.7f, 0.7f, 1.0f
	};
	GLfloat light_position[] = {
		2.0f, 6.0f, 3.0f, 0.0f
	};
	//pencahayaan
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void setViewport(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt = 2.0;
	//half height of thewindow
	glOrtho(-winHt * 64 / 48, winHt * 64 / 48, -winHt, winHt, 0.1,
		100.0);
}
void setCamera(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.3, 3.3, 3.0, 0, 0.25, 0, 0.0, 1.0, 0.0);
}
void sphere() {
	glColor3f(82.0f / 255.0f, 114.0f / 255.0f, 242.0f / 255.0f);
	glutSolidSphere(10, 15, 23);
}
void cube() {
	
	glColor3f(178.0f / 255.0f, 39.0f / 255.0f, 39.0f / 255.0f);
	glutSolidCube(20);
}
void cone() {
	glColor3f(54.0f / 255.0f, 47.0f / 255.0f, 217.0f / 255.0f);
	glutSolidCone(2, 8, 15, 17);
}
void dodecahedron() {
	glColor3f(168.0f / 255.0f, 100.0f / 255.0f, 100.0f / 255.0f);
	glutSolidDodecahedron();
}
void teapot() {
	glTranslated(a, a, a);
	glColor3f(248.0f / 255.0f, 203.0f / 255.0f, 46.0f / 255.0f);
	glutSolidTeapot(1);
}
void torus() {
	glColor3f(0.0f, 110.0f / 255.0f, 127.0f / 255.0f);
	glutSolidTorus(1, 10, 35, 50);
}

void display() {

	setMaterial();
	setLighting();
	setViewport();
	setCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -40);
	teapot();
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
	if (key == 's' || key == 'S') {
		a -= 0.1;
		sy = 0;
		sz = 0;
		sudut += 10;
		rotateLeft = false;
		rotateRight = false;
	}
	else if (key == 'w' || key == 'W') {
		sx = 1;
		sy = 0;
		sz = 0;
		sudut -= 10;
		rotateLeft = false;
		rotateRight = false;
	}
	else if (key == 'a' || key == 'A') {
		sx = 0;
		sy = 1;
		a += 0.1;
		sudut -= 10;
		rotateLeft = false;
		rotateRight = false;
	}
	else if (key == 'd' || key == 'D') {
		sx = 0;
		sy = 1;
		sz = 0;
		sudut += 10;
		rotateLeft = false;
		rotateRight = false;
	}
	else if (key == '+') {
		zoomFactor += 0.1;
	}
	else if (key == '-') {
		zoomFactor -= 0.1;
		if (zoomFactor < 0.1) {
			zoomFactor = 0.1;
		}
	}
	else if (key == 'q' || key == 'Q') {
		rotateLeft = true;
	}
	else if (key == 'r' || key == 'R') {
		rotateRight = true;
	}
}

void myKeyboardUp(unsigned char key, int x, int y) {
	if (key == 'q' || key == 'Q') {
		rotateLeft = true;
		rotateRight = false;
	}
	if (key == 'r' || key == 'R') {
		rotateRight = true;
		rotateLeft = false;
	}
}

void update(int value) {
	if (rotateLeft) {
		sx = 0;
		sy = 1;
		sz = 0;
		sudut -= rotationSpeed;
	}
	if (rotateRight) {
		sx = 0;
		sy = 1;
		sz = 0;
		sudut += rotationSpeed;
	}
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}
