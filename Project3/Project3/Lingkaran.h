// Lingkaran.h
#include <stdio.h>
#include <iostream>
#include <glut.h>
using namespace std;

int centerX, centerY, radius;

void drawPoint(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void myInit(void) {
	glClearColor(0.0, 0.0, 0.0, 0);
	glColor3f(0.0f, 1.0f, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 20, -15, 15);
}

void midPointAlgorithm() {
	int x = 0, y = radius;
	int p = 1 - radius; // Initial value of the decision parameter

	while (x <= y) {
		drawPoint(centerX + x, centerY + y);
		drawPoint(centerX - x, centerY + y);
		drawPoint(centerX + x, centerY - y);
		drawPoint(centerX - x, centerY - y);
		drawPoint(centerX + y, centerY + x);
		drawPoint(centerX - y, centerY + x);
		drawPoint(centerX + y, centerY - x);
		drawPoint(centerX - y, centerY - x);

		if (p < 0) {
			x++;
			p += 2 * x + 1;
		}
		else {
			x++;
			y--;
			p += 2 * (x - y) + 1;
		}
	}

	drawLine(-20, 0, 20, 0); // X-axis
	drawLine(0, -15, 0, 15); // Y-axis
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(5);
	midPointAlgorithm();
	glFlush();
}
