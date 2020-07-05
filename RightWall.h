#include<math.h>


void DisplayRightWall(float roomWidth, float roomHeight){

	glBegin(GL_QUADS);
	glColor3f(0.92f, 0.92f, 0.75f);
	glVertex3f(0.3 * roomWidth, 0.425 * roomHeight, 0.0f);

	glColor3f(1.0f, 1.0f, 0.8f);
	glVertex3f(roomWidth/2, roomHeight / 2, 0.0f);
	
	
	glColor3f(1.0f, 1.0f, 0.8f);
	glVertex3f(roomWidth / 2, -roomHeight / 2, 0.0f);

	glColor3f(0.92f, 0.92f, 0.75f);
	glVertex3f(0.3*roomWidth, -0.1 * roomHeight, 0.0f);

	glEnd();
}
