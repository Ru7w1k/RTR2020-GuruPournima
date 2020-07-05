#include<GL/glut.h>

void Draw_Door(void);

void Draw_Door(void){

		glEnable(GL_LINE_WIDTH);
		glLineWidth(2);
		glEnable(GL_POINT_SIZE);
		glPointSize(7);
		glEnable(GL_POINT_SMOOTH);
	
		glBegin(GL_QUADS);
			glColor3f((185.0/255),(122.0/255.0),(87.0/255.0));
			glVertex2f(-0.6,0.4);
			glVertex2f(-0.4,0.4);
			glVertex2f(-0.4,-0.2);
			glVertex2f(-0.6,-0.2);
			
			glVertex2f(0.6,0.4);
			glVertex2f(0.4,0.4);
			glVertex2f(0.4,-0.2);
			glVertex2f(0.6,-0.2);
		
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
			glVertex2f(-0.5,0.38);
			glVertex2f(-0.5,-0.18);
			glVertex2f(0.5,0.38);
			glVertex2f(0.5,-0.18);
		glEnd();

		glBegin(GL_POINTS);
			glColor3f(0.0,0.0,0.0);
			glVertex2f(-0.52,0.1);
			glVertex2f(-0.48,0.1);
			
			glColor3f(0.0,0.0,0.0);
			glVertex2f(0.52,0.1);
			glVertex2f(0.48,0.1);
		glEnd();
		
		glFlush();
}