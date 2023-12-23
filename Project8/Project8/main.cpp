#include"LiangBarsky.h"
void main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 180);
	glutCreateWindow("Liang Barsky");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	myinit();
	glutMainLoop();
}