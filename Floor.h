
#include <GL\freeglut.h>

void DisplayFloor() {

	glBegin(GL_QUADS);
	  //top left corner
	  glColor3f(0.128f, 0.128f, 0.128f);
	  glVertex3f(-0.6f, -0.2f, 0.0f);

	  //top right corner
	  glColor3f(0.128f, 0.128f, 0.128f);
	  glVertex3f(0.6f, -0.2f, 0.0f);

	  //bottom right corner 
	  glColor3f(0.128f, 0.128f, 0.128f);
	  glVertex3f(1.0f, -1.0f, 0.0f);

	  //bottom left corner
      glColor3f(0.128f, 0.128f, 0.128f);
	  glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();

}