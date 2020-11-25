#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;
double Angle = 0;

//Функция вызываемая перед вхождением в главный цикл
void Init(void) {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void Init2(void) {
	glPointSize(10.0f);
}

//Функция вызываемая при изменении размеров окна
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

void reshape2(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0f, w / h, 1.0f, 1000.0f);
}

//Функция вызываемая каждый кадр - для его отрисовки, вычислений и т. д.
void update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void update2() {
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(100.0f, 100.0f, 100.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);
	glutWireSphere(50.0f, 10, 10);
	//glutWireTeapot(50);

	glFlush();
	glutSwapBuffers();
}

void update3() {
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(100.0f, 100.0f, 100.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);
	
	glBegin(GL_POINTS);
	glVertex3f(-50.0f, -50.0f, -50.0f);
	glVertex3f(-50.0f, -50.0f, 50.0f);
	glVertex3f(-50.0f, 50.0f, -50.0f);
	glVertex3f(-50.0f, 50.0f, 50.0f);
	glVertex3f(50.0f, -50.0f, -50.0f);
	glVertex3f(50.0f, -50.0f, 50.0f);
	glVertex3f(50.0f, 50.0f, -50.0f);
	glVertex3f(50.0f, 50.0f, 50.0f);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void update4() {
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(100.0f, 100.0f, 100.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-75.0f, 0.0f, -50.0f);
	glVertex3f(-75.0f, 0.0f, 50.0f);
	glVertex3f(75.0f, 0.0f, 50.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-75.0f, 0.0f, -50.0f);
	glVertex3f(75.0f, 0.0f, -50.0f);
	glVertex3f(75.0f, 0.0f, 50.0f);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void update5() {
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(100.0f, 100.0f, 100.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);

	GLfloat BlueCol[3] = { 0, 0, 1 };

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glColor3ub(0, 255, 0);
	glVertex3f(75.0, 0.0, 0.0);

	glColor3fv(BlueCol);
	glVertex3f(75.0, 75.0, 0.0);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

int task1(int argc, char **argv) {
	//Инициализировать сам glut
	glutInit(&argc, argv);

	//Установить параметры окна - двойная буфферизация
	// и поддержка цвета RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	// Установить размеры окна
	glutInitWindowSize(800, 600);

	// Создать окно с заголовком
	glutCreateWindow("Task 1");

	//Укажем glut функцию, которая будет вызываться при
	// изменении размера окна приложения
	glutReshapeFunc(reshape);

	//Укажем glut функцию, которая будет рисовать каждый кадр
	glutDisplayFunc(update);

	//Очень важно!Это инициализирует точки входа в драйвер OpenGL,
	//чтобы мы могли вызывать все функции в API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	Init();

	//Войти в главный цикл приложения
	glutMainLoop();
	return 0;
}

void renderRectangle()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0); 
	glVertex2f(-0.5f, -0.5f);

	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.5f, 0.5f);

	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.5f, 0.5f);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	glFlush(); glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: rotate_x += 5; break;
	case GLUT_KEY_DOWN: rotate_x -= 5; break;
	case GLUT_KEY_RIGHT: rotate_y += 5; break;
	case GLUT_KEY_LEFT: rotate_y -= 5; break;
	case GLUT_KEY_HOME: rotate_z += 5; break;
	case GLUT_KEY_END: rotate_z -= 5; break;
	}
	glutPostRedisplay();
}

void specialKeys2(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: Angle += 7; break;
	case GLUT_KEY_DOWN: Angle -= 7; break;
	}
	glutPostRedisplay();
}

int task2(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Task 2");

	glutDisplayFunc(renderRectangle);
	glutSpecialFunc(specialKeys);

	glutMainLoop();
	return 0;
}

void renderWireCube() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);

	glutWireCube(1);
	glFlush();
	glutSwapBuffers();
}

void renderWireCube2() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);

	glutSolidCube(1);
	glFlush();
	glutSwapBuffers();
}

int task3(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Task 3");

	glutDisplayFunc(renderWireCube);
	//glutDisplayFunc(renderWireCube2);
	glutSpecialFunc(specialKeys);

	glutMainLoop();
	return 0;
}

int task4(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Task 4");
	glutReshapeFunc(reshape2);

	glutDisplayFunc(update2);
	glutSpecialFunc(specialKeys2);
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	glutMainLoop();
	return 0;
}

int task5(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Task 5");
	glutReshapeFunc(reshape2);
	glutDisplayFunc(update3);
	glutSpecialFunc(specialKeys2);

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	Init2();

	glutMainLoop();
	return 0;
}

int task6(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Task 6");
	glutReshapeFunc(reshape2);
	glutDisplayFunc(update4);
	glutSpecialFunc(specialKeys2);

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	Init2();

	glutMainLoop();
	return 0;
}

int task7(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Task 7");
	glutReshapeFunc(reshape2);
	glutDisplayFunc(update5);
	glutSpecialFunc(specialKeys2);

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	Init2();

	glutMainLoop();
	return 0;
}

int main(int argc, char* argv[]) {
    task1(argc, argv);
	//task2(argc, argv);
	//task3(argc, argv);
	//task4(argc, argv);
	//task5(argc, argv);
	//task6(argc, argv);
	//task7(argc, argv);
	return 0;
}