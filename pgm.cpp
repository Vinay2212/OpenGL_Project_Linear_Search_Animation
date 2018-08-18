<!DOCTYPE html>
#include<gl/glut.h>
#include<stdio.h>
int n = 4, arr[10] = { 25,4,7 };
void search();
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void display(void)
{
	int i, j = 0, k = 0;
	char a[10][3];
	GLint x = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	for (i = 0; i < n; i++) {
		glTranslated(0+x, 0, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2i(100, 175);
		glVertex2i(125, 175);
		glVertex2i(125, 150);
		glVertex2i(100, 150);
		glEnd();
		glRasterPos3f(100,150 , 0);
		_itoa_s(arr[i], a[i], 10);
		for (j = 0; j <strlen(a[i]) ; j++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i][j]);
		}
		x += i==0 ? 50:0.01;
	}
	search();
	glFlush();
}
void search()
{
	int key = 4,i,j,x=0;
	char a[10];
	glLoadIdentity();
	for (i = 0; i < n; i++)
	{
		glTranslated(0 + x, 0, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2i(100, 175);
		glVertex2i(125, 175);
		glVertex2i(125, 150);
		glVertex2i(100, 150);
	
		glRasterPos3f(100, 150, 0);
		_itoa_s(key, a, 10);
		for (j = 0; j < strlen(a); j++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[j]);
		}
		x += i == 0 ? 50 : 0.01;
		if (key == arr[i])
		{
			glBegin(GL_POLYGON);
			glColor3f(1.0, 0.7, 0.9);
			glVertex2i(100, 125);
			glVertex2i(125, 125);
			glVertex2i(125, 100);
			glVertex2i(100, 100);
			glEnd();
			break;
		}
		else
		{
			glFlush();
		}

		glEnd();
	}

}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("My First Attempt");
	glutDisplayFunc(display);
	myInit();
	glutPostRedisplay();
	glutSwapBuffers();
	glutMainLoop();
}


