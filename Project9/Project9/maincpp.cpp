
#include "ImplementasiMouse.h"
void main(int argc, char **argv){
	glutInit( &argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutCreateWindow("Coba");
	glutDisplayFunc(display);
	gluOrtho2D(-320.0, 320.0, -320.0, 320.0);
	glutTimerFunc(10,Timer, 50);
	glutMouseFunc(mouseku);
	glutMotionFunc(motionku);

	glutMainLoop();
	
	

}