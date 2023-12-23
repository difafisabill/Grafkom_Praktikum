#include "lingkaran.h"
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Lingkaran MidPoint");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}