#include <glut.h>
using namespace std;
int ax = 1, ay = 1;
int bx = 4, by = 1;
int cx = 4, cy = 6;
int dx = 1, dy = 6;
int sx = 2;
void drawPolygon() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(ax, ay);
	glVertex2i(bx, by);
	glVertex2i(cx, cy);
	glVertex2i(dx, dy);
	glEnd();
	glFlush();
}
void drawPolygonShearingX() {
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2i(ax + sx * ay, ay);
	glVertex2i(bx + sx * by, by);
	glVertex2i(cx + sx * cy, cy);
	glVertex2i(dx + sx * dy, dy);
	glEnd();
	glFlush();
}
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-25, 25, -25, 25);
}
void myDisplay() {
	drawPolygon();
	drawPolygonShearingX();
}