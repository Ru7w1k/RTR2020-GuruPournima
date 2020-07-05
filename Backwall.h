#include <GL\freeglut.h>
#include<math.h>

void DisplayBackWall()
{    
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.8f);
        glVertex3f (-0.60, -0.20, 0.0);
        
        glColor3f(1.0f, 1.0f, 0.8f);
        glVertex3f (-0.60, 0.85, 0.0);
        
        glColor3f(1.0f, 1.0f, 0.8f);
        glVertex3f (0.60, 0.85, 0.0);    
        
        glColor3f(1.0f, 1.0f, 0.8f);
        glVertex3f (0.60, -0.20, 0.0);       
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
        glVertex3f (-0.20, 0.55, 0.00);
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (-0.20, 0.65, 0.00);
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (0.215, 0.65, 0.00);    
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (0.215, 0.55, 0.00);       
    glEnd();

    DisplayWindowShutters(-0.19, 0.56, 0.075, 0.08);
    DisplayWindowShutters(-0.11, 0.56, 0.075, 0.08);
    DisplayWindowShutters(-0.03, 0.56, 0.075, 0.08);
    DisplayWindowShutters(0.05, 0.56, 0.075, 0.08);
    DisplayWindowShutters(0.13, 0.56, 0.075, 0.08);    

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
        glVertex3f (-0.198, -0.20, 0.0);
        glVertex3f (-0.198, 0.55, 0.0);
    glEnd();

     glBegin(GL_LINES);
        glColor3f(0.5f, 0.2f, 0.0f);
        glVertex3f (0.21, -0.20, 0.0);
        glVertex3f (0.21, 0.55, 0.0);
    glEnd();
   
}

void DisplayArch()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glBegin(GL_LINE_STRIP);  
    int i = 0;
    double theta = 0.00;
    double radius = 0.30;

    for(i = 47; i < 135; i++)
    {
        theta = i*3.142/180;
        glVertex2f(0.008 + radius * cos(theta), (0.75 - 0.323) + radius * sin(theta));

    }
   glEnd();
 
}