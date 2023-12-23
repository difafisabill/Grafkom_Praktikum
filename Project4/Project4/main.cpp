#include "Segitiga.h"
void main() {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("latihan segilima");
	gluOrtho2D(-150, 150, -150, 150);
	glutDisplayFunc(segilima);
	glutMainLoop();
}