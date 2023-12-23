#include <stdio.h>
#include <glut.h>
void segilima() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2d(0, 80);
	glVertex2d(60, 40);
	glVertex2d(30, -20);
	glVertex2d(-30, -20);
	glVertex2d(-60, 40);
	glEnd();

	
	glFlush();
}