#include <iostream>
#include "Header.h"
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	cout << "PILIH OBJECT 3D" << endl;
	cout << "1. Sphere" << endl;
	cout << "2. Cube" << endl;
	cout << "3. Cone" << endl;
	cout << "4. Dodecahedron" << endl;
	cout << "5. Teapot" << endl;
	cout << "6. Torus" << endl;
	cout << "7. Gabung 4 Objek" << endl;
	cout << "************************************" << endl;
	cout << "Pilih : ";
	cin >> objek;

	if (objek == 1) {
		glutCreateWindow("Tugas6_Sphere_2118052");
	}
	else if (objek == 2) {
		glutCreateWindow("Tugas6_Cube_2118052");
	}
	else if (objek == 3) {
		glutCreateWindow("Tugas6_Cone_2118052");
	}
	else if (objek == 4) {
		glutCreateWindow("Tugas6_Dodecahedron_2118052");
	}
	else if (objek == 5) {
		glutCreateWindow("Tugas6_Teapot_2118052");
	}
	else if (objek == 6) {
		glutCreateWindow("Tugas6_Torus_2118052");
	}
	else if (objek == 7) {
		glutCreateWindow("Tugas6_Gabungan Objek_2118052");
	}
	glutInitWindowSize(w, h);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(myKeyboard);
	glutKeyboardUpFunc(myKeyboardUp);
	glutTimerFunc(25, update, 0);
	glutMainLoop();


}
