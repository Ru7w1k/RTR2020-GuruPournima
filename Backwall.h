#include <GL\freeglut.h>
#include<math.h>

void DisplayBackWall()
{    
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.8f);
        glVertex3f (-0.80, -0.15, 0.0);
        
        glColor3f(1.0f, 1.0f, 0.8f);
        glVertex3f (-0.80, 0.85, 0.0);
        
        glColor3f(1.0f, 1.0f, 0.8f);
        glVertex3f (0.80, 0.85, 0.0);    
        
        glColor3f(1.0f, 1.0f, 0.8f);
        glVertex3f (0.80, -0.15, 0.0);       
    glEnd();
 
}

void DisplayWindow()
{
    void DisplayWindowShutters(float x, float y, float length, float height);    
    void DiplayWindowSubsection();
    void DisplayArch();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (-0.20, 0.65, 0.00);
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (-0.20, 0.75, 0.00);
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (0.215, 0.75, 0.00);    
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (0.215, 0.65, 0.00);       
    glEnd();

    DisplayWindowShutters(-0.19, 0.66, 0.075, 0.08);
    DisplayWindowShutters(-0.11, 0.66, 0.075, 0.08);
    DisplayWindowShutters(-0.03, 0.66, 0.075, 0.08);
    DisplayWindowShutters(0.05, 0.66, 0.075, 0.08);
    DisplayWindowShutters(0.13, 0.66, 0.075, 0.08);    

    DiplayWindowSubsection();
    DisplayArch();
 
}

void DisplayWindowShutters(float x, float y, float length, float height)
{    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.3f, 1.0f);
        glVertex3f (x, y, 0.0);
        
        glColor3f(0.0f, 0.3f, 1.0f);
        glVertex3f (x, y + height, 0.0);
        
        glColor3f(0.0f, 0.3f, 1.0f);
        glVertex3f (x + length, y + height, 0.0);    
        
        glColor3f(0.0f, 0.3f, 1.0f);
        glVertex3f (x + length, y, 0.0);       
    glEnd();
 
}

void DiplayWindowSubsection()
{
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0.5f, 0.2f, 0.0f);
        glVertex3f (-0.198, -0.15, 0.0);
        glVertex3f (-0.198, 0.65, 0.0);
    glEnd();

     glBegin(GL_LINES);
        glColor3f(0.5f, 0.2f, 0.0f);
        glVertex3f (0.21, -0.15, 0.0);
        glVertex3f (0.21, 0.65, 0.0);
    glEnd();
   
}

void DisplayArch()
{
    
 
}