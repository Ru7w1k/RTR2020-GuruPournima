#include <GL\freeglut.h>
#include<math.h>


void DisplayRightWall(float roomWidth, float roomHeight){
    //glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(0.92f, 0.92f, 0.75f);
	glVertex3f(0.3 * roomWidth, 0.35 * roomHeight, 0.0f);

	glColor3f(1.0f, 1.0f, 0.8f);
	glVertex3f(roomWidth/2, roomHeight / 2, 0.0f);
	
	
	glColor3f(1.0f, 1.0f, 0.8f);
	glVertex3f(roomWidth / 2, -roomHeight / 2, 0.0f);

	glColor3f(0.92f, 0.92f, 0.75f);
	glVertex3f(0.3*roomWidth, -0.1 * roomHeight, 0.0f);

	glEnd();
//	glFlush();
}
