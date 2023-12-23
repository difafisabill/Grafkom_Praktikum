# include <stdio.h>
# include <glut.h>

void garis(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex2i(0, 1);
	glVertex2i(0, -1);

	glColor3f(0, 1, 0);
	glVertex2i(-1, 0);
	glVertex2i(1, 0);

	glColor3f(0, 0, 1);
	glVertex2i(-0.5, 0.5);
	glVertex2i(0.5, -0.5);

	glColor3f(0, 1, 1);
	glVertex2i(-5, 5);
	glVertex2i(-5, -5);

	glColor3f(1, 1, 0);
	glVertex2i(-5, 5);
	glVertex2i(5, -5);

	glEnd();
	glFlush();
}