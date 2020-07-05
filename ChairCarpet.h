#include<GL\freeglut.h>

void DisplayChairCarpet()
{
	//code

	glBegin(GL_QUADS);

	//glColor3f(0.68f, 0.18f, 0.19f);    //Dark color
	//glColor3f(0.78f, 0.21f, 0.22f);    //Light Color

	glColor3f(0.78f, 0.21f, 0.22f);
	glVertex3f(-0.2f, -0.35f, 0.0f);     //left top

	glColor3f(0.68f, 0.18f, 0.19f);
	glVertex3f(-0.25f, -0.5f, 0.0f);     //left bottom

	glColor3f(0.68f, 0.18f, 0.19f);
	glVertex3f(0.25f, -0.5f, 0.0f);      //right bottom	

	glColor3f(0.78f, 0.21f, 0.22f);
	glVertex3f(0.2f, -0.35f, 0.0f);      //right top

	glEnd();

}
