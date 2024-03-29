#include<stdio.h>
#include<GL/glut.h>

typedef float point[3];

point v[]={{0,0,1},{0,0.9,-0.3},{-0.8,-0.4,-0.3},{0.8,-0.4,-0.9}};

void drawTriangle(point a,point b,point c)
{
 glBegin(GL_POLYGON);
  glNormal3fv(a);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
 glEnd();
}
int n;
void divideTriangle(point a,point b,point c,int m)
{
point v1,v2,v3;
int j;
 if(m>0)
  {
   for(j=0;j<3;j++)
    {
      v1[j]=(a[j]+b[j])/2;
	v2[j]=(a[j]+c[j])/2;
	v3[j]=(b[j]+c[j])/2;
     }
   divideTriangle(a,v1,v2,m-1);
   divideTriangle(c,v2,v3,m-1);
   divideTriangle(b,v3,v1,m-1);
  }
  else
    drawTriangle(a,b,c);
}

void drawTetrahedron(int m)
{
 glClearColor(1,1,1,1);
  glColor3f(1,0,0);
  divideTriangle(v[0],v[1],v[2],m);

 glColor3f(0,1,0);
  divideTriangle(v[0],v[1],v[3],m);
 glColor3f(0,0,1);
  divideTriangle(v[0],v[2],v[3],m);
 glColor3f(1,0,1);
  divideTriangle(v[1],v[2],v[3],m);
}

void display()
{
glClearColor(1,1,1,1); 
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 drawTetrahedron(n);
  glFlush();
 //drawTriangle(v[0],v[1],v[2]);
}
void Reshape(int w,int h)
{
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if(w<=h)
        glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
   else
         glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
/*if(w >= h) {
        glOrtho(-2.0, 2.0,
            -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w,
            -10.0, 10.0
        );
    } else {
        glOrtho(
            -2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h,
            -2.0, 2.0, -10.0, 10.0
        );
    }*/
 glMatrixMode(GL_MODELVIEW);
glutPostRedisplay();
}

int main(int argc,char **argv)
 {
   printf("Enter the number of divisions=");
   scanf("%d",&n);
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
   glutInitWindowSize(500,500);
   glutCreateWindow("3D gasket");
   glutDisplayFunc(display);
   glutReshapeFunc(Reshape);
   glEnable(GL_DEPTH_TEST);
printf("Hello world");
   glClearColor(1,1,1,1);
   glutMainLoop();
return 0;
}
        
  
