#include<stdio.h>
#include<GL/glut.h>

int TOP=8,BOTTOM=4,RIGHT=2,LEFT=1;
float xmin,xmax,ymin,ymax,lx0,lx1,ly0,ly1;
void display();
void init()
{
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500,500,-500,500);
}

int getOutcode(float x,float y)
{
 int c=0;
 if(y>ymax)
  c=TOP;
 if(y<ymin)
  c=BOTTOM;
  if(x>xmax)
   c=c|RIGHT;
  if(x<xmin)
    c=c|LEFT;

return c;
}

void lineclip(float x1,float y1,float x2,float y2)
{
 int outcode1=getOutcode(x1,y1);
  int outcode2=getOutcode(x2,y2);
  float m=(y2-y1)/(x2-x1);
 while((outcode1|outcode2)!=0)
 {
    if((outcode1&outcode2)!=0)
    {
       lx0=lx1=ly0=ly1=0;
        break;
     }
   float xi=x1,yi=y1,x,y;
   int c=outcode1;
   if(c==0){
  xi=x2;
   yi=y2;
  c=outcode2;
  }
   if((c&TOP)!=0)
     {
     x=xi+1.0/m*(ymax-yi);
     y=ymax;
    }
   else if((c&BOTTOM)!=0)
     {
     x=xi+1.0/m*(ymin-yi);
     y=ymin;
    }
 else if((c&LEFT)!=0)
     {
    y=yi+m*(xmin-xi);
     x=xmin;
    }
  else if((c&RIGHT)!=0)
     {
     y=yi+m*(xmax-xi);
     x=xmax;
    }
  if(c==outcode1)
   {
   lx0=x;
   ly0=y;
   outcode1=getOutcode(x,y);
  }
  if(c==outcode2)
   {
    lx1=x;
     ly1=y;
    outcode2=getOutcode(x,y);
  }
 }
display();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glColor3f(1,0,0);
  glVertex2f(xmin,ymin);
 glVertex2f(xmin,ymax);
glVertex2f(xmax,ymax);
glVertex2f(xmax,ymin);
glEnd();
glBegin(GL_LINES);
 glVertex2f(lx0,ly0);
 glVertex2f(lx1,ly1);
glEnd();
glFlush();
}
void keypress(unsigned char key,int x,int y)
{
 if(key=='c')
  {
   lineclip(lx0,ly0,lx1,ly1);
  printf("Line clipped"); 
glFlush(); 
 }
 }
int main(int argc,char **argv)
{
 printf("Enter the window co-ordinates\n");
 printf("Xmin="); scanf("%f",&xmin);
 printf("\nYmin="); scanf("%f",&ymin);
 printf("\nXmax="); scanf("%f",&xmax);
 printf("\nymax="); scanf("%f",&ymax);
 printf("\nEnter the line co-ordinates\n");
 scanf("%f%f%f%f",&lx0,&ly0,&lx1,&ly1);
 glutInit(&argc,argv);
 glutInitWindowSize(700,500);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Cohen sutherland line clipping");
 init();
 glutDisplayFunc(display);
 glutKeyboardFunc(keypress);

 glutMainLoop();

return 0;
 }  
  

 
