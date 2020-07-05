#include<GL\freeglut.h>

void DisplayFlower(float alpha)
{  
    glLineWidth(1.5);
    
    float length = 0.10f;    

    int i = 0, noOfEdges = 4;
    float xChange=0;
    float yChange=0;

    float lineStartX, lineStartY, lineEndX, lineEndY;


    float x = -0.60f;
    float y = -0.60f;
    
    glBegin(GL_LINES);
	    glColor4f(0.9215f, 0.8784f, 0.0549f, alpha);
     

         glVertex2f(x + 0.0, y + 0.20f);
         glVertex2f(x + 0.0, y + (-0.20f) );     

         glVertex2f(x + 0.075f, y + 0.18f);
         glVertex2f(x + (-0.075), y + (-0.18));  

         glVertex2f(x+0.15, y+0.15);
         glVertex2f(x+-0.15,y+ -0.15);    

         glVertex2f(x+0.25, y+0.10);
         glVertex2f(x+-0.25,y+ -0.10);    

         glVertex2f(x+0.25,  y+0.0);
         glVertex2f(x+-0.25, y+ 0.0);  

         glVertex2f(x+-0.23,y+ 0.058);
         glVertex2f(x+0.23, y+-0.058);  
         
         glVertex2f(x+-0.075,y+ 0.18);
         glVertex2f(x+0.075, y+-0.18);
         
         glVertex2f(x+-0.15,y+ 0.15);
         glVertex2f(x+0.15, y+-0.15);
    glEnd();

    x = 0.0f;
    y = -0.90f;
    
    glBegin(GL_LINES);
	    glColor4f(0.9215f, 0.8784f, 0.0549f, alpha);
     

         glVertex2f(x + 0.0, y + 0.20f);
         glVertex2f(x + 0.0, y + (-0.20f) );     

         glVertex2f(x + 0.075f, y + 0.18f);
         glVertex2f(x + (-0.075), y + (-0.18));  

         glVertex2f(x+0.15, y+0.15);
         glVertex2f(x+-0.15,y+ -0.15);    

         glVertex2f(x+0.25, y+0.10);
         glVertex2f(x+-0.25,y+ -0.10);    

         glVertex2f(x+0.25,  y+0.0);
         glVertex2f(x+-0.25, y+ 0.0);  

         glVertex2f(x+-0.23,y+ 0.058);
         glVertex2f(x+0.23, y+-0.058);  
         
         glVertex2f(x+-0.075,y+ 0.18);
         glVertex2f(x+0.075, y+-0.18);
         
         glVertex2f(x+-0.15,y+ 0.15);
         glVertex2f(x+0.15, y+-0.15);
    glEnd();


    x = 0.60f;
    y = -0.60f;
    
    glBegin(GL_LINES);
	    glColor4f(0.9215f, 0.8784f, 0.0549f, alpha);
     

         glVertex2f(x + 0.0, y + 0.20f);
         glVertex2f(x + 0.0, y + (-0.20f) );     

         glVertex2f(x + 0.075f, y + 0.18f);
         glVertex2f(x + (-0.075), y + (-0.18));  

         glVertex2f(x+0.15, y+0.15);
         glVertex2f(x+-0.15,y+ -0.15);    

         glVertex2f(x+0.25, y+0.10);
         glVertex2f(x+-0.25,y+ -0.10);    

         glVertex2f(x+0.25,  y+0.0);
         glVertex2f(x+-0.25, y+ 0.0);  

         glVertex2f(x+-0.23,y+ 0.058);
         glVertex2f(x+0.23, y+-0.058);  
         
         glVertex2f(x+-0.075,y+ 0.18);
         glVertex2f(x+0.075, y+-0.18);
         
         glVertex2f(x+-0.15,y+ 0.15);
         glVertex2f(x+0.15, y+-0.15);
    glEnd();
}