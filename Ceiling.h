#include<math.h>

void DisplayCeiling()
{
	glBegin(GL_QUADS);
		glColor3f(0.19f, 0.17f, 0.17f);
		glVertex3f(-0.6f, 0.85f, 0.0f);
		
		glColor3f(0.36f, 0.36f, 0.36f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		
		glColor3f(0.36f, 0.36f, 0.36f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		
		glColor3f(0.19f, 0.17f, 0.17f);
		glVertex3f(0.6f, 0.85f, 0.0f);
	glEnd();
}
