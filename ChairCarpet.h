#include<GL\freeglut.h>

void DisplayChairCarpet(float alpha)
{
	//code

	glBegin(GL_QUADS);

	//glColor3f(0.68f, 0.18f, 0.19f);    //Dark color
	//glColor3f(0.78f, 0.21f, 0.22f);    //Light Color

	glColor4f(0.78f, 0.21f, 0.22f, alpha);
	glVertex3f(-0.2f, -0.30f, 0.0f);     //left top

	glColor4f(0.68f, 0.18f, 0.19f, alpha);
	glVertex3f(-0.25f, -0.45f, 0.0f);     //left bottom

	glColor4f(0.68f, 0.18f, 0.19f, alpha);
	glVertex3f(0.25f, -0.45f, 0.0f);      //right bottom	

	glColor4f(0.78f, 0.21f, 0.22f, alpha);
	glVertex3f(0.2f, -0.30f, 0.0f);      //right top

	glEnd();

}
