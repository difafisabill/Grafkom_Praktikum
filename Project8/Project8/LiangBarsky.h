#include<conio.h>
#include<glut.h>
double xmin = 1, ymin = 1, xmax = 7, ymax = 7;
double xvmin = 20, yvmin = 20, xvmax = 25, yvmax = 25;
int diptest(double p, double q, double *t1, double *t2){
	double t = q / p;
	if (p < 0.0){
		if (t > *t1) *t1 = t;
		if (t > *t2) return (false);
	}
	else if (p > 0.0){
		if (t < *t2) *t2 = t;
		if (t < *t1) return (false);
	}
	if (p == 0.0){
		if (q < 0.0) return (false);
	}
	return (true);
}
void lblcd(double x0, double y0, double x1, double y1){
	double dx = x1 - x0, dy = y1 - y0, t1 = 1.0, te = 0.0;
	if (diptest(-dx, x0 - xmin, &te, &t1))
	if (diptest(dx, xmax - x0, &te, &t1))
	if (diptest(-dy, y0 - ymin, &te, &t1))
	if (diptest(dy, ymax - y0, &te, &t1)){
		if (t1 < 1.0){
			x1 = x0 + t1*dx;
			y1 = y0 + t1*dy;
		}
		if (te > 0.0){
			x0 = x0 + te*dx;
			y0 = y0 + te*dy;
		}
	}
	double sx = (xvmax - xvmin) / (xmax - ymin);
	double sy = (yvmax - yvmin) / (ymax - ymin);
	double vx0 = xvmin + (x0 - xmin)*sx;
	double vy0 = yvmin + (y0 - ymin)*sy;
	double vx1 = xvmin + (x1 - xmin)*sx;
	double vy1 = yvmin + (y1 - ymin)*sy;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2d(vx0, vy0);
	glVertex2d(vx1, vy1);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xvmin, yvmin);
	glVertex2f(xvmax, yvmin);
	glVertex2f(xvmax, yvmax);
	glVertex2f(xvmin, yvmax);
	glEnd();
}
void display(){
	double x1 = 1, y1 = 1, x2 = 10, y2 = 10;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);
	glEnd();
	lblcd(x1, y1, x2, y2);
	glFlush();
}
void myinit(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 35, -30, 35);
}