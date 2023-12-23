//#include "Garis.h"
//void main(){
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("latihan garis");
//	gluOrtho2D(-100, 100, -100, 100);
//	glutDisplayFunc(gabungan);
//	glutMainLoop();
//}


//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(240, 160);
//	glutCreateWindow("DDA");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//}#include "Bresenham.h"int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Bresenham");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}