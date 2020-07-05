// header files
#include <windows.h>
#include <GL\freeglut.h>

#include "Backwall.h"
#include "Floor.h"
#include "ChairCarpet.h"
#include "TeachingBoard.h"
#include "RightWall.h"
#include "Ceiling.h"
#include "Chair.h"
#include "Draw_Door.h"

#include "resource.h"

// libraries
#pragma comment(lib, "winmm.lib") // for PlaySound()

// gloabal variables
bool bFullscreen = false;

// entry-point function
int main(int argc, char** argv)
{
	// function declarations
	void initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void uninitialize(void);
	void timerFunc(int);

	// code
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Guru Pournima");

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(10, timerFunc, 1);
	glutCloseFunc(uninitialize);
	
	glutMainLoop();

	return(0);  // this line is not necessary
}

void initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// play backgroud theme song
	PlaySound(MAKEINTRESOURCE(IDWAV_GURUMANTRA), // ID of WAVE resource
		GetModuleHandle(NULL), 					 // handle of this module, which contains the resource
		SND_RESOURCE | SND_ASYNC);				 // ID is of type resource | play async (i.e. non-blocking)

}

void resize(int width, int height)
{
	// code
	if (height <= 0)
		height = 1;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	

	/* Add drawing parts here */
	DisplayCeiling();

	DisplayBackWall();

	DisplayFloor();

	DisplayWindow();
	DisplayChairCarpet();
	DrawTeachingBoard();
	DisplayRightWall(2.0,2.0);
	Draw_Door();
	
	glScalef(0.4f, 0.6f, 0.5f);
	DisplayChair();
  
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;

	case 'F':
	case 'f':
		if (bFullscreen == false)
		{
			glutFullScreen();
			bFullscreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			bFullscreen = false;
		}
		break;

	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}
void timerFunc(int speed)
{
	AnimateBoard();
	glutPostRedisplay();
	glutTimerFunc(10, timerFunc, 1);
}
