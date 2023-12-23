#include "Cohen-Sutherland-Line-Clipping.h"
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Clipping");
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	init();
	glutMainLoop();
	return 0;
}