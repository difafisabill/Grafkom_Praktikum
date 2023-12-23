# include <stdio.h> 
# include <glut.h>

void titik(){
	glPointSize(8); 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POINTS);
	 // color rgb 
	 // color rgb 
	glColor3f(1, 0, 0); // color rgb 
	glVertex2f(0.6, 0.5);
	glColor3f(0, 1, 0);
	glVertex2f(0.6, -0.5);// batas hanya mulai 0 - 1 
	glColor3f(0, 0, 1);
	glVertex2f(0, 0);
	glColor3f(0, 1, 1);
	glVertex2f(-0.6, 0.5);
	glColor3f(1, 1, 0);
	glVertex2f(-0.6, -0.5);
	

	
	glEnd(); // mengakhiri glbegin 
	glFlush();
}




