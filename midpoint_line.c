#include<stdio.h>
#include<GL/glut.h>

int x0,y0,x1,y1;

void init()
{
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500,500,-500,500);
}
void writepixel(int x,int y)
{
glBegin(GL_POINTS);
glColor3f(0,0,0);
glVertex2d(x,y);
glEnd();
glFlush();
}
void display()
{
float dy=y1-y0;
float dx=x1-x0;
float d=2*dy-dx;
float incrE=dy,incrNE=dy-dx;
int x=x0,y=y0;
writepixel(x,y);
if(1>=abs(dy/dx))
{
  while(x<x1)
   {
    x=x+1;
     if(d<=0)
       {
          d=d+2*incrE;
       }
     else
       {
         d=d+2*incrNE;
        y=y+1;
       }
   writepixel(x,y);
     }
 }
 else
   {
     d=2*dx-dy;
     incrE=dx;
incrNE=dx-dy;
while(y<y1)
 {
   y=y+1;
  if(d<=0)
   {
     d=d+2*incrE;
   } 
   else
      {
       d=d+2*incrNE;
       x=x+1;
      }
 writepixel(x,y);
   }
}

}

int main(int argc,char** argv)
{
 printf("Enter the co-ordinates for the line:\n");
 printf("x0="); scanf("%d",&x0);
 printf("\ny0="); scanf("%d",&y0);
 printf("\nx1="); scanf("%d",&x1);
 printf("\ny1="); scanf("%d",&y1);
 glutInit(&argc,argv);
glutInitWindowSize(500,500);
glutCreateWindow("Midpoint Line");
init();
glutDisplayFunc(display);
glutMainLoop();
 return 0;
}



