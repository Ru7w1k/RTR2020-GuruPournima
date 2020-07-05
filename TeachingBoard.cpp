#include "TeachingBoard.h"

GLfloat widthTeachingBoard = 0.001f, topOfTeachingBoard = 0.50f, heightOfTeachingBoard = 0.001f;//Change width & height to 0.001f when using AnimateBoard()
GLfloat borderMargin = 0.005f;
GLfloat borderColor[] = {0.35f, 0.35f, 0.25f};
GLfloat boardColor[] = {0.25f, 0.25f, 0.25f};
GLfloat boardColor1[] = {0.05f, 0.05f, 0.05f};

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
	
	// Board with light shade
	// glBegin(GL_QUADS);
		// glColor3fv(boardColor);
		// glVertex3f(-widthTeachingBoard/2.0f, topOfTeachingBoard, 0.0f);
		// glColor3fv(boardColor1);
		// glVertex3f(-widthTeachingBoard/2.0f, topOfTeachingBoard - heightOfTeachingBoard, 0.0f);
		// glColor3fv(boardColor1);
		// glVertex3f(widthTeachingBoard/2.0f, topOfTeachingBoard - heightOfTeachingBoard, 0.0f);
		// glColor3fv(boardColor);
		// glVertex3f(widthTeachingBoard/2.0f, topOfTeachingBoard, 0.0f);
	// glEnd();	
}

void AnimateBoard(void)
{
	if(widthTeachingBoard < 0.5)
		widthTeachingBoard += 0.001;
	
	if(heightOfTeachingBoard < 0.5)
		heightOfTeachingBoard += 0.001;
}