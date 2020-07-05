void DisplayChair(float alpha)
{
	glLineWidth(5.5);

	glBegin(GL_LINES);
	glColor4f(0.278f,0.157f,0.043f, alpha);
    glVertex2f(-0.24,-0.40);
    glVertex2f(-0.24,-0.75);
    glVertex2f(0.24,-0.40);
    glVertex2f(0.24,-0.75);
    glVertex2f(-0.19,-0.20);
    glVertex2f(-0.19,-0.60);
    glVertex2f(0.19,-0.20);
    glVertex2f(0.19,-0.60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(0.278f,0.157f,0.043f, alpha);
	glVertex3f(-0.20,0.20, 0.0);
	glVertex3f(0.20,0.20, 0.0);
	glVertex3f(0.20,-0.20, 0.0);
	glVertex3f(-0.20,-0.20, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(0.595f,0.271f,0.0745f, alpha);
	glVertex3f(-0.20,-0.20, 0.0);
	glVertex3f(-0.25,-0.40, 0.0);
	glVertex3f(0.25,-0.40, 0.0);
	glVertex3f(0.20,-0.20, 0.0);
	glEnd();

}