////Memanggil Library
//#include <stdlib.h> //utk operasi pembanding dan konversi
//#include <string.h> //utk memanipulasi string
//#include <stdarg.h> //utk mengakses argumen
//#include <glut.h> //utk menerjemahkan glut agar proses dapat dirunning
////Deklarasi Variable
//float z_pos = -10.0f;
//float rot = 0.0f;
////Membuat Method resize
//void resize(int width, int height){
//	glViewport(0, 0, width, height); //lembar kerja
//	glMatrixMode(GL_PROJECTION); //menentukan nilai matriks
//	glLoadIdentity(); //merubah matriks
//	gluPerspective(45.0, (float)width / (float)height, 1.0, 300.0);
//	//menampilkan tampilan ke dalam world koordinat
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
////Membuat Method timeout
//void myTimeOut(int id){
//	// dipanggil jika waktu berjalan
//	// ...menjalankan animasi secara bertahap...
//	rot +=6;
//	glutPostRedisplay(); // request redisplay
//	glutTimerFunc(100, myTimeOut, 0); // request next timer event
//}
////Membuat Method keyboard
//void myKeyboard(unsigned char key, int x, int y) //unsigned = menandakan sebuah variabel
//{
//	if ((key == '<') || (key == ',')) z_pos -= 0.1f;
//	if ((key == '>') || (key == '.')) z_pos += 0.1f;
//}
////Membuat Method display
//void mydisplay(void){
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	glTranslatef(0.0, 0.0f, z_pos);
//	glRotatef(rot, 1, 1, 1);
//	glBegin(GL_QUADS);
//	// Front Face, red
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex3f(-1.0f, -1.0f, 1.0f);
//	glVertex3f(1.0f, -1.0f, 1.0f);
//	glVertex3f(1.0f, 1.0f, 1.0f);
//	glVertex3f(-1.0f, 1.0f, 1.0f);
//	// Back Face, green
//	glColor3f(0.0, 1.0, 0.0);
//	glVertex3f(1.0f, -1.0f, -1.0f);
//	glVertex3f(1.0f, 1.0f, -1.0f);
//	glVertex3f(-1.0f, 1.0f, -1.0f);
//	glVertex3f(-1.0f, -1.0f, -1.0f);
//	// Top Face, blue
//	glColor3f(0.0, 0.0, 1.0);
//	glVertex3f(-1.0f, 1.0f, -1.0f);
//	glVertex3f(-1.0f, 1.0f, 1.0f);
//	glVertex3f(1.0f, 1.0f, 1.0f);
//	glVertex3f(1.0f, 1.0f, -1.0f);
//	// Bottom Face, yellow
//	glColor3f(1.0, 1.0, 0.0);
//	glVertex3f(-1.0f, -1.0f, -1.0f);
//	glVertex3f(1.0f, -1.0f, -1.0f);
//	glVertex3f(1.0f, -1.0f, 1.0f);
//	glVertex3f(-1.0f, -1.0f, 1.0f);
//	// Right face, cyan
//	glColor3f(0.0, 1.0, 1.0);
//	glVertex3f(1.0f, -1.0f, -1.0f);
//	glVertex3f(1.0f, 1.0f, -1.0f);
//	glVertex3f(1.0f, 1.0f, 1.0f);
//	glVertex3f(1.0f, -1.0f, 1.0f);
//	// Left Face, magenta
//	glColor3f(1.0, 0.0, 1.0);
//	glVertex3f(-1.0f, -1.0f, -1.0f);
//	glVertex3f(-1.0f, -1.0f, 1.0f);
//	glVertex3f(-1.0f, 1.0f, 1.0f);
//	glVertex3f(-1.0f, 1.0f, -1.0f);
//	glEnd();
//	glFlush();
//	glutSwapBuffers(); //menukar buffer ke screen buffer
//}
////Membuat Method inisialisasi
//void init(){
//	glEnable(GL_DEPTH_TEST); //mengaktifkan grafis
//	glClearColor(0.0, 0.0, 0.0, 1.0); //Background Colour
//	glMatrixMode(GL_PROJECTION); //menentukan nilai matriks
//	glLoadIdentity(); //merubah matriks
//	gluPerspective(45, (GLdouble)500.0 / (GLdouble)500.0, 0, 100);
//	//menampilkan tampilan ke dalam world koordinat
//	glMatrixMode(GL_MODELVIEW);
//	return;
//}
//int main(int argc, char** argv){
//	glutInit(&argc, argv); //inisialisasi library glut
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); //utk membuat tampilan glut rgb dan buffer
//		glutInitWindowSize(500, 500); //utk menentukan ukuran window
//	glutInitWindowPosition(0, 0); //utk mengatur posisi
//	glutCreateWindow("3d"); //memberi judul window
//	// callbacks
//	glutDisplayFunc(mydisplay); //memanggil display
//	glutKeyboardFunc(myKeyboard); //memanggil fungsi
//	glutTimerFunc(100, myTimeOut, 0); //timing
//	glutReshapeFunc(resize); //memanggil reshape
//	init(); //memanggil fungsi
//	glutMainLoop(); //melakukan perulangan event
//	return 0;
//}



#include "cubWire.h"
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w, h);
	glutCreateWindow("Cube");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
	glutTimerFunc(50, update, 0);
	glutKeyboardFunc(myKeyboard);
	glutMainLoop();
}
