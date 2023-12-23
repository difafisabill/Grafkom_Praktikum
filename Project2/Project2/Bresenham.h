#include <iostream>
#include <glut.h>
using namespace std;
int X_Akhir, Y_Akhir, X0, Y0;
void drawLineBresenham(int X0, int Y0, int X_Akhir, int Y_Akhir) {
	int dx = abs(X_Akhir - X0);
	int dy = abs(Y_Akhir - Y0);
	int Pk = 2 * dy - dx;
	int Xk, Yk;
	if (X0 < X_Akhir) {
		Xk = X0;
		Yk = Y0;
	}
	else {
		Xk = X_Akhir;
		Yk = Y_Akhir;
		X_Akhir = X0;
		Y_Akhir = Y0;
	}
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(Xk, Yk);
	while (Xk < X_Akhir) {
		Xk++;
		if (Pk < 0) {
			Pk += 2 * dy;
		}
		else {
			Yk++;
			Pk += 2 * dy - 2 * dx;
		}
		glVertex2i(Xk, Yk);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	drawLineBresenham(1, 4, 8, 10);
	glFlush();
}
void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0, 15, 0, 15);
}