#include <windows.h>
#include<glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
void display();
using namespace std;
float xd1 = 8, yd1 = 8;
float xd2 = 9, yd2 = 12;
float xd3 = -6, yd3 = -3;
float xd4 = -8, yd4 = -12;
float xmin = -10,  ymin = -10;
float xmax = 10,  ymax = 10;
void init(void){
	glClearColor(0.0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-20, 20, -20, 20);
}
int code(float x, float y){
	int c = 0;
	if (y>ymax)c = 8;
	if (y<ymin)c = 4;
	if (x>xmax)c = c | 2;
	if (x<xmin)c = c | 1;
	return c;
}
void cohen_Line(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
	int c1 = code(x1, y1);
	int c2 = code(x2, y2);
	int c3 = code(x3, y3);
	int c4 = code(x4, y4);


	float m1 = (y2 - y1) / (x2 - x1);
	float m2 = (y4 - y3) / (x4 - x3);
	while ((c1 | c2)>0){
		if ((c1 & c2)>0){
			exit(0);
		}
		float xi = x1, yi = y1;
		int c = c1;
		if (c == 0){
			c = c2;
			xi = x2;
			yi = y2;
		}
		float x, y;
		if ((c & 8)>0){
			y = ymax;
			x = xi + 1.0 / m1*(ymax - yi);
		}
		else if ((c & 4)>0){
			y = ymin;
			x = xi + 1.0 / m1*(ymin - yi);
		}
		else if ((c & 2)>0){
			x = xmax;
			y = yi + m1*(xmax - xi);
		}
		else if ((c & 1)>0){
			x = xmin;
			y = yi + m1*(xmin - xi);
		}
		if (c == c1){
			xd1 = x;
			yd1 = y;
			c1 = code(xd1, yd1);
		}
		if (c == c2){
			xd2 = x;
			yd2 = y;
			c2 = code(xd2, yd2);
		}
	}
	display();
}
// keyboard key
void mykey(unsigned char key, int x, int y){
	if (key == 'c'){
		cohen_Line(xd1, yd1, xd2, yd2, xd3, yd3, xd4, yd4);
		glFlush();
	}
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(xmin, ymin);
	glVertex2i(xmin, ymax);
	glVertex2i(xmax, ymax);
	glVertex2i(xmax, ymin);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2i(xd1, yd1);
	glVertex2i(xd2, yd2);
	glEnd();
	glFlush();
}