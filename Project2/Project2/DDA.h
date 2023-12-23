#include <stdlib.h>
#include <glut.h>
#include <iostream>

using namespace std;
void init(){
	glClearColor(1, 1, 1, 1);
	glPointSize(10);
	glLoadIdentity();
	gluOrtho2D(-1, 8, -1, 15);

}
void dda(void) {
	int X0, Y0, X_Akhir, Y_Akhir;
	float x, y, dx, dy, steps, x_inc, y_inc;
	X0 = 1;
	Y0 = 4;
	X_Akhir = 6;
	Y_Akhir = 11;
	x = X0;
	y = Y0;
	dx = X_Akhir - X0;
	dy = Y_Akhir - Y0;
	if (abs(dx) > abs(dy)) {
		steps = abs(dx);
	}
	else {
		steps = abs(dy);
	}
	x_inc = dx / steps;
	y_inc = dy / steps;
	glBegin(GL_LINE_STRIP);
	glVertex2i(x, y);
	//perulangan untuk menggambar titik-titik
	do {
		x += x_inc;
		y += y_inc;
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(round(x), round(y));
	} while (x < X_Akhir); //atau dengan x > X_Akhir
	glEnd();
	glFlush();
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	dda();
	glutSwapBuffers();
}