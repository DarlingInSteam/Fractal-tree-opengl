#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

#define GL_GLEXT_PROTOTYPES

void func(double x, double y, double angle, double len, int deph);

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.2f, 0.5f);
	glBegin(GL_LINES);
	func(50, 50, 1.1, 50, 12);

	glEnd();

	glFlush();
}

void func(double x, double y, double angle, double len, int deph)
{
	double angp = 0.5;
	for (int i = -1; i < 5; i += 2)
	{
		if (deph > 0)
			func(x + cos(angle + i * angp) * len / 2, y + sin(angle + i * angp) * len / 2, angle + i * angp, len / 2, deph - 1);

		glVertex2d(x, y);
		glVertex2d(x + cos(angle + i * angp) * len / 2, y + sin(angle + i * angp) * len / 2);
	}
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -100.0, 100.0);
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Fractal");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
	return 0;
}