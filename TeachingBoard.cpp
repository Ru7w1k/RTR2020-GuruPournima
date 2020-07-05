#include <GL/freeglut.h>
#include "TeachingBoard.h"

GLfloat widthTeachingBoard = 0.50f, topOfTeachingBoard = 0.60f, heightOfTeachingBoard = 0.4f;
GLfloat borderMargin = 0.01f;
GLfloat boardColor[] = {0.25f, 0.25f, 0.25f};
GLfloat borderColor[] = {0.35f, 0.35f, 0.25f};

void DrawTeachingBoard(void)
{
	//Border 
	glBegin(GL_QUADS);
		glColor3fv(borderColor);
		glVertex3f(-widthTeachingBoard/2.0f - borderMargin, topOfTeachingBoard + borderMargin, 0.0f);
		glVertex3f(-widthTeachingBoard/2.0f - borderMargin, topOfTeachingBoard, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f + borderMargin, topOfTeachingBoard, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f + borderMargin, topOfTeachingBoard + borderMargin, 0.0f);
		
		glVertex3f(-widthTeachingBoard/2.0f - borderMargin, topOfTeachingBoard + borderMargin, 0.0f);
		glVertex3f(-widthTeachingBoard/2.0f - borderMargin, topOfTeachingBoard - heightOfTeachingBoard - borderMargin, 0.0f);
		glVertex3f(-widthTeachingBoard/2.0f, topOfTeachingBoard - heightOfTeachingBoard - borderMargin, 0.0f);
		glVertex3f(-widthTeachingBoard/2.0f, topOfTeachingBoard + borderMargin, 0.0f);
		
		glVertex3f(-widthTeachingBoard/2.0f - borderMargin, topOfTeachingBoard - heightOfTeachingBoard, 0.0f);
		glVertex3f(-widthTeachingBoard/2.0f - borderMargin, topOfTeachingBoard - heightOfTeachingBoard - borderMargin, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f + borderMargin, topOfTeachingBoard - heightOfTeachingBoard - borderMargin, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f + borderMargin, topOfTeachingBoard - heightOfTeachingBoard, 0.0f);
		
		glVertex3f(widthTeachingBoard/2.0f, topOfTeachingBoard + borderMargin, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f, topOfTeachingBoard - heightOfTeachingBoard - borderMargin, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f + borderMargin, topOfTeachingBoard - heightOfTeachingBoard - borderMargin, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f + borderMargin, topOfTeachingBoard + borderMargin, 0.0f);
		
	glEnd();
	
	//Board
	glBegin(GL_QUADS);
		glColor3fv(boardColor);
		glVertex3f(-widthTeachingBoard/2.0f, topOfTeachingBoard, 0.0f);
		glVertex3f(-widthTeachingBoard/2.0f, topOfTeachingBoard - heightOfTeachingBoard, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f, topOfTeachingBoard - heightOfTeachingBoard, 0.0f);
		glVertex3f(widthTeachingBoard/2.0f, topOfTeachingBoard, 0.0f);
	glEnd();
}