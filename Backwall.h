#include <GL\freeglut.h>

void DisplayBackWall()
{
    /*float left = leftPercentage/100.00f;
    float right = rightPeercentage/100.00f;
    float top = topPercentage/100.00f;
    float bottom = bottomPercentage/100.00f;*/

    //glClear (GL_COLOR_BUFFER_BIT);
    
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
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (-0.20, 0.65, 0.00);
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (-0.20, 0.75, 0.00);
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (0.20, 0.75, 0.00);    
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (0.20, 0.65, 0.00);       
    glEnd();
}

void DisplayWindowShutters()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (-0.18, 0.68, 0.1);
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (-0.18, 0.73, 0.1);
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (0.08, 0.73, 0.1);    
        
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex3f (0.08, 0.68, 0.1);       
    glEnd();
}