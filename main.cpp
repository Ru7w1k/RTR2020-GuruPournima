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
#include "Carpet.h"
#include "FadeOutRect.h"
#include "Flowers.h"

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
float yOffsetCarpet = -1.0f;
float alphaFadeOut = 0.0f;
float alphaFlowers = 0.0f;
float yOffsetFlower = 0.2f;

int fadeOutDelay = 0;

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

	if (alphaDoor >= 1.0f)
		DrawTeachingBoard();

	glLoadIdentity();

	glTranslatef(0.0f, yOffsetCarpet, 0.0f);
	DisplayCarpet();

	glLoadIdentity();

	glScalef(1.0f, scaleCarpet, 1.0f);
	DisplayChairCarpet(1.0f);
	
	glScalef(0.35f, 0.55f, 0.5f);
	DisplayChair(alphaChair);

	glLoadIdentity();

	glTranslatef(0.0f, -0.325f + yOffsetFlower, 0.0f);
	glScalef(0.10f, 0.15f, 1.0f);
	DisplayFlower(alphaFlowers);

	glLoadIdentity();

	if (alphaChair >= 1.0f)
		DrawFadeOutRect(alphaFadeOut);
  
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
				yOffset -= 0.005f;
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
				scaleBackWall += 0.005f;
			else
			{
				scaleBackWall = 1.0f;
				state++;
			}
		break;

		/* side walls */
		case 2:
			if (xOffsetWall > 0.0f)
				xOffsetWall -= 0.005f;
			else
			{
				xOffsetWall = 0.0f;
				state++;
			}
		break;

		/* floor */

		case 3:
			if (yOffsetFloor > 0.0f)
				yOffsetFloor -= 0.005f;
			else
			{
				yOffsetFloor = 0.0f;
				state++;
			}
		break;

		/* window */
		case 4:
			if (alphaWindow < 1.0f)
				alphaWindow += 0.005f;
			else
			{
				alphaWindow = 1.0f;
				state++;
			}
		break;

		/* doors */
		case 5:
			if (alphaDoor < 1.0f)
				alphaDoor += 0.005f;
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
			if (yOffsetCarpet < 0.0f)
				yOffsetCarpet += 0.005f;
			else
			{
				yOffsetCarpet = 0.0f;
				state++;
			}
		break;

		/* carpet under chair */
		case 8:
			if (scaleCarpet < 1.0f)
				scaleCarpet += 0.005f;
			else
			{
				scaleCarpet = 1.0f;
				state++;
			}
		break;

		/* chair */
		case 9:
			if (alphaChair < 1.0f)
				alphaChair += 0.0075f;
			else
			{
				alphaChair = 1.0f;
				state++;
			}
		break;

		/* flowers */
		case 10:
			if (yOffsetFlower > 0.0f)
				yOffsetFlower -= 0.005;

			if (alphaFlowers < 1.0f)
				alphaFlowers += 0.0075f;
			else
			{
				alphaFlowers = 1.0f;
				state++;
			}
		break;
				
		/* fade out delay */
		case 11:
			if (fadeOutDelay < 1000)
				fadeOutDelay++;
			else
				state++;
		break;

		/* fade out */
		case 12:
			if (alphaFadeOut < 1.0f)
				alphaFadeOut += 0.005f;
			else
			{
				alphaFadeOut = 1.0f;
				state++;
			}
		break;

		/* exit! */
		case 13:
			if (fadeOutDelay < 1200)
				fadeOutDelay++;
			else
				glutLeaveMainLoop();
		break;

	}






	




	glutPostRedisplay();
	glutTimerFunc(15, timerFunc, 1);
}
