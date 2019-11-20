#include<stdio.h>
#include<GL/glut.h>

float t1=0,t2=1;
float x1,y1,x2,y2,x3,y3,x4,y4;
float p[4],q[4];
float xmin,ymin,xmax,ymax;

void init()
{
 glClearColor(0,0,0,0);
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-500,500,-500,500);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
glColor3f(1,0,0);
glVertex2d(xmin,ymin);
glVertex2d(xmin,ymax);
glVertex2d(xmax,ymax);
glVertex2d(xmax,ymin);
glEnd();
glBegin(GL_LINES);
glColor3f(1,0,0);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glEnd();
glFlush();
}

void lineclip(float x1,float y1,float x2,float y2)
{
float dx=x2-x1;
float dy=y2-y1;

float t;
p[0]=-dx;
p[1]=dx;
p[2]=-dy;
p[3]=dy;
q[0]=x1-xmin;
q[1]=xmax-x1;
q[2]=y1-ymin;
q[3]=ymax-y1;

int i;
for(i=0;i<4;i++)
{
 if(p[i]==0)
 {
    if(q[i]<0)
       return;
  }
 if(p[i]<0)
  {
     t=q[i]/p[i];
    if(t>t1 && t<t2)
      t1=t;
  }
 else if(p[i]>0)
  {
     t=q[i]/p[i];
    if(t>t1 && t<t2)
      t2=t;
  }
 }
if(t1<t2)
{
 x3=x1+t1*(x2-x1);
 x4=x1+t2*(x2-x1);
 y3=y1+t1*(y2-y1);
y4=y1+t2*(y2-y1);
if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax){
if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax){
glBegin(GL_LINES);
glVertex2f(x3,y3);
glVertex2f(x4,y4);
glEnd();
glFlush();
}
}
}
}

void keypress(unsigned char key,int x,int y)
{
 if(key=='c')
 {
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_LINE_LOOP);
   glVertex2d(xmin,ymin);
glVertex2d(xmin,ymax);
glVertex2d(xmax,ymax);
glVertex2d(xmax,ymin);
glEnd();
 lineclip(x1,y1,x2,y2);
 printf("Line clipped");
 }
}
int main(int argc,char** argv)
{
 printf("Enter the window co-ordinates\n");
 printf("Xmin="); scanf("%f",&xmin);
 printf("\nYmin="); scanf("%f",&ymin);
 printf("\nXmax="); scanf("%f",&xmax);
 printf("\nymax="); scanf("%f",&ymax);
 printf("\nEnter the line co-ordinates\n");
 scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
 glutInit(&argc,argv);
 glutInitWindowSize(700,500);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Liang Barsky line clipping");
 init();
 glutDisplayFunc(display);
 glutKeyboardFunc(keypress);

 glutMainLoop();

return 0;
}
  


