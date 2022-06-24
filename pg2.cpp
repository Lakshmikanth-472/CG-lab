#include<stdio.h>
#include<GL/glut.h>
int x,y;
int rflag=0;
void draw_pixel(float x,float y)
{
glColor3f(0.0,0.0,1.0);
glPointSize(5.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}
void triangle(){
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,100);
glVertex2f(250,400);
glVertex2f(400,100);
glEnd();
}
float th=0.0;
float trX=0.0,trY=0.0;
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
if(rflag==1)
{
trX=0.0;
trY=0.0;
th+=0.1;
draw_pixel(0.0,0.0);
}
if(rflag==2)
{
trX=x;
trY=y;
th+=0.0;
draw_pixel(0.0,0.0);
}
glPushMatrix();
glTranslatef(trX,trY,0.0);
glRotatef(th,0.0,0.0,1.0);
glTranslatef(-trX,-trY,0.0);
triangle();
glPopMatrix();
glutPostRedisplay();
glutSwapBuffers();
}
void myinit()
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500.0,500.0,-500.0,500.0);
glMatrixMode(GL_MODELVIEW);
}
void rotateMenu(int option)
{
if(option==1)
	rflag=1;
	if(option==2)
		rflag=2;
	if(option==3)
		rflag=3;
	}
	int main(int argc,char**argv)
	{
	printf("enter the fixed points(x,y) for rotation\n");
	scanf("%d%d",&x,&y);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("rotate triangle");
	myinit();
	glutDisplayFunc(display);
	glutCreateMenu(rotateMenu);
	glutAddMenuEntry("rotate about origin",1);
	glutAddMenuEntry("rotate around fixed",2);
	glutAddMenuEntry("stop rotation",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}	
	




