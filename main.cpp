// header files
#include <windows.h>
#include <GL\freeglut.h>

#include "Backwall.h"
#include "Floor.h"
#include "ChairCarpet.h"
#include "TeachingBoard.h"
#include "RightWall.h"
#include "LeftWall.h"
#include "Ceiling.h"
#include "Chair.h"
#include "Draw_Door.h"

#include "resource.h"

// libraries
#pragma comment(lib, "winmm.lib") // for PlaySound()

// gloabal variables
bool bFullscreen = false;

float yOffset = 1.0f;
float scaleBackWall = 0.0f;
float xOffsetWall = 1.0f;
float yOffsetFloor = 1.0f;
float alphaWindow = 0.0f;
float alphaDoor = 0.0f;
float scaleCarpet = 0.0f;
float aplhaChairCarpet = 0.0f;
float alphaChair = 0.0f;

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
	glutTimerFunc(15, timerFunc, 1);
	glutCloseFunc(uninitialize);
	
	glutFullScreen();
	glutMainLoop();

	return(0);  // this line is not necessary
}

void initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	/* enable blending */
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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


	glTranslatef(0.0f, yOffset, 0.0f);
	DisplayCeiling();

	glLoadIdentity();

	glScalef(scaleBackWall, scaleBackWall, scaleBackWall);
	DisplayBackWall();

	glLoadIdentity();

	glTranslatef(xOffsetWall, 0.0f, 0.0f);
	DisplayRightWall(2.0,2.0);

	glLoadIdentity();

	glTranslatef(-xOffsetWall, 0.0f, 0.0f);
	Draw_LeftWall();
	
	glLoadIdentity();

	glTranslatef(0.0f, -yOffsetFloor, 0.0f);
	DisplayFloor();

	glLoadIdentity();

	DisplayWindow(alphaWindow);
	
	Draw_Door(alphaDoor);

	DrawTeachingBoard();

	glLoadIdentity();

	//glTranslatef(0.0f, -0.4f, 0.0f);
	glScalef(1.0f, scaleCarpet, 1.0f);
	DisplayChairCarpet(1.0f);
	
	glScalef(0.35f, 0.55f, 0.5f);
	DisplayChair(alphaChair);
  
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
	static int state = 0;

	switch (state)
	{
		/* ceiling */
		case 0:
			if (yOffset > 0.0f)
			{
				yOffset -= 0.01f;
			}
			else
			{
				yOffset = 0.0f;
				state++;
			}
		break;

		/* back wall */
		case 1:
			if (scaleBackWall < 1.0f)
				scaleBackWall += 0.01f;
			else
			{
				scaleBackWall = 1.0f;
				state++;
			}
		break;

		/* side walls */
		case 2:
			if (xOffsetWall > 0.0f)
				xOffsetWall -= 0.01f;
			else
			{
				xOffsetWall = 0.0f;
				state++;
			}
		break;

		/* floor */
		case 3:
			if (yOffsetFloor > 0.0f)
				yOffsetFloor -= 0.01f;
			else
			{
				yOffsetFloor = 0.0f;
				state++;
			}
		break;

		/* window */
		case 4:
			if (alphaWindow < 1.0f)
				alphaWindow += 0.01f;
			else
			{
				alphaWindow = 1.0f;
				state++;
			}
		break;

		/* doors */
		case 5:
			if (alphaDoor < 1.0f)
				alphaDoor += 0.01f;
			else
			{
				alphaDoor = 1.0f;
				state++;
			}
		break;

		/* board */
		case 6:
			if (AnimateBoard() == TRUE)
				state++;
		break;

		/* main carpet */
		case 7:
			state++;

		break;

		/* carpet under chair */
		case 8:
			if (scaleCarpet < 1.0f)
				scaleCarpet += 0.01f;
			else
			{
				scaleCarpet = 1.0f;
				state++;
			}
		break;

		/* chair */
		case 9:
			if (alphaChair < 1.0f)
				alphaChair += 0.01f;
			else
			{
				alphaChair = 1.0f;
				state++;
			}
		break;
	}






	




	glutPostRedisplay();
	glutTimerFunc(15, timerFunc, 1);
}
