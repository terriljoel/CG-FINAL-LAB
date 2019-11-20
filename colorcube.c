#include<stdio.h>
#include<GL/glut.h>

GLfloat vertex[][3]={ {-1.0,-1.0,-1.0}, {1.0,-1.0,-1.0}, {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0}, {1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};
GLfloat normal[][3]={ {-1.0,-1.0,-1.0}, {1.0,-1.0,1.0}, {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0}, {1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};
/*GLfloat color[][3]={{0.0,0.0,0.0},{0.0,0.0,1.0},{0.0,1.0,0.0},{0.0,1.0,1.0},{1.0,0.0,0.0},{1.0,0.0,1.0},{1.0,1.0,0.0},{1.0,1.0,1.0}};*/
GLfloat color[][3]={{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};
void drawCube(int a,int b,int c,int d)
{
 glBegin(GL_POLYGON);
 glColor3fv(color[a]);
 glNormal3fv(normal[a]);
 glVertex3fv(vertex[a]);
 glColor3fv(color[b]);
 glNormal3fv(normal[b]);
 glVertex3fv(vertex[b]);
 glColor3fv(color[c]);
 glNormal3fv(normal[c]);
 glVertex3fv(vertex[c]);
glColor3fv(color[d]);
 glNormal3fv(normal[d]);
 glVertex3fv(vertex[d]);
  glEnd();
}

void colorcube()
{
  drawCube(0,3,2,1);
  drawCube(2,3,7,6);
  drawCube(0,3,7,4);
  drawCube(0,4,5,1);
  drawCube(4,5,6,7);
  drawCube(1,2,6,5);
/*polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,7,6);
	polygon(4,5,6,7);
	polygon(0,1,5,4);*/
}

static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;

void display()
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glRotatef(theta[0],1.0,0.0,0.0);
glRotatef(theta[1],0.0,1.0,0.0);
glRotatef(theta[2],0.0,0.0,1.0);
  colorcube();
glFlush();
 glutSwapBuffers();
}

void spincube()
{
 theta[axis]+=0.1;
 if(theta[axis]>360) theta[axis]-=360;
 glutPostRedisplay();
}
void mouseevent(int btn,int state,int x,int y)
{
 if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) axis=0;
 if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN) axis=1;
 if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) axis=2;
}
void reshape(int w,int h)
{
 glViewport(0,0,w,h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 if(w<=h)
glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
     
  else
	 glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize(500,500);   
 glutCreateWindow("Color cube rotation");
glutMouseFunc(mouseevent); 
glutDisplayFunc(display);
  glutIdleFunc(spincube);
  glutReshapeFunc(reshape); 
  
  //glEnable(GL_DEPTH_TEST);
  glutMainLoop();
}
