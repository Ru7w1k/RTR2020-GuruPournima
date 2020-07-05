
void DrawFadeOutRect(float);

void DrawFadeOutRect(float alpha)
{

	glBegin(GL_QUADS);

	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3f(-1.0f,  1.0f, 0.0f);
	glVertex3f( 1.0f,  1.0f, 0.0f);
	glVertex3f( 1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glEnd();

}
