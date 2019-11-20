#include<stdio.h>
#include<GL/glut.h>
#define dx 20
#define dy 20
int maxx,maxy;
int x[100],y[100],x0,y0;

void init()
{
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500,500,-500,500);
}

void display()
{
int i,j;
for(i=0;i<=maxx;i++)
x[i]=x0+i*dx;
for(j=0;j<=maxy;j++)
y[j]=y0+j*dy;
glColor3f(1,0,0);
for(i=0;i<maxx;i++)
for(j=0;j<maxy;j++)
{
  glBegin(GL_LINE_LOOP);
   glVertex2d(x[i],y[j]);
glVertex2d(x[i],y[j+1]);
glVertex2d(x[i+1],y[j+1]);
glVertex2d(x[i+1],y[j]);
glEnd();
  printf("\n%d-%d",x[i],y[j]);
     printf("\n%d-%d",x[i],y[j+1]);
 printf("\n%d-%d",x[i+1],y[j+1]);
 printf("\n%d-%d",x[i+1],y[j]);
}
glFlush();
}

int main(int argc,char** argv)
{
  printf("Enter the number of mesh\n");
  scanf("%d%d",&maxx,&maxy);
  printf("\nEnter the initial position\n");
 scanf("%d%d",&x0,&y0);
  glutInit(&argc,argv);
  glutInitWindowSize(1000,700);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Rectangular mesh");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
 }
