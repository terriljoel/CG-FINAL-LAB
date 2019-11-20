#include<stdio.h>
#include<GL/glut.h>

float r,h,k;
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
 double d=5.0/4.0-r;
 int x=0,y=r;
writepixel(x+h,y+k);
 while(x<y)
{
 if(d<0)
 {
   d+=2*x+3.0;
 }
 else
  {
   d+=2*(x-y)+5.0;
   y--;
  } 
  x++;
 
writepixel(x+h,y+k);
writepixel(y+h,x+k);
writepixel(-x+h,y+k);
writepixel(-y+h,x+k);
writepixel(-x+h,-y+k);
writepixel(-y+h,-x+k);
writepixel(x+h,-y+k);
 writepixel(y+h,-x+k);
}
}
int main(int argc,char** argv)
{
 printf("Enter the radius of the circle-");
  scanf("%f",&r);
 printf("\nEnter the co-ordinates for the center of the circle\n");
 scanf("%f",&h);
 scanf("%f",&k);
 glutInit(&argc,argv);
 glutInitWindowSize(1000,1000);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Midpoint circle");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
return 0;
 }
