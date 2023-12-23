# include <stdlib.h>
# include <glut.h>
# include <stdio.h>
# include <iostream>
using namespace std;

void Triangles(){
	glBegin(GL_TRIANGLES);
	glVertex2i(0, 0);
	glVertex2i(100, -30);
	glVertex2i(100, 30);
	glEnd();

}
void cube() {

	glColor3d(0, 1, 1);
	glutWireSphere(100, 25, 50); // fungsi disamping adalah bentukpendeklarasian fungsi “Cube”
}

void mouseku(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON){
		cout << "Tombol Kiri (" << x << ", " << y << ")";
	}
	else if (button == GLUT_MIDDLE_BUTTON){
		cout << "Tombol Tengah (" << x << ", " << y << ")";
	}
	else{
		cout << "Tombol Kanan (" << x << ", " << y << ")";
	}
	if (state == GLUT_DOWN){
		printf("tombol ditekan \n");
	}
	else {
		printf      ("tombol dilepas \n");
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glRotated(15, 0., 0., 1.);
	
	//glutWireCube(100);
	glutWireSphere(100, 4, 50);
	// glutSwapBuffers();
	glFlush();
	
}
void Timer(int value){
	glutPostRedisplay();
	glutTimerFunc(10, Timer, 50);
}

void motionku(int x, int y) {
	printf("posisi printer mouse (%d, %d)\n",x,y );
}