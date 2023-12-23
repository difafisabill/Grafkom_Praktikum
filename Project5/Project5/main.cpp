#include "refleksi.h"
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Shear");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
