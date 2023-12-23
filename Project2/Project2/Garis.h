#include <stdio.h> 
#include <glut.h> 
void garis_lines() {
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2i(-80, 40);
	glVertex2i(-40, 40);
	glVertex2i(-40, 20);
	glEnd();
}
void garis_line_strip() {
		glBegin(GL_LINE_STRIP);
		glColor3f(1, 1, 1);
		glVertex2i(-80, -40);
		glVertex2i(-40, -40);
		glVertex2i(-40, -60);
		glEnd();
}
void garis_line_loop() {
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2i(20, -40);
		glVertex2i(60, -40);
		glVertex2i(60, -60);
		glEnd();
}
void gabungan() {
		glClear(GL_COLOR_BUFFER_BIT);
		garis_lines();
		garis_line_strip();
		garis_line_loop();
		glFlush();
}
	
