#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 20.0                  //speed of traffic
float i=0.0;                        //movement of car
float m=0.0;                        //movement of clouds
float n=0.0;                        //movement of plane along x-axis
float o=0.0;                        //  and y-axis
float c=0.0;                        //movement of comet	SS
int light=1;                        //1 for green-light, 0 for red-light
int day=1;                          //1 for day ,0 for night
void draw_pixel(GLint cx, GLint cy)
{
	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}
void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}
void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}
void draw_object()
{
int l;
if(day==1)
{
                                    //sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
    glVertex2f(0,450);
    glVertex2f(0,700);
    glVertex2f(1100,700);
    glVertex2f(1100,450);
glEnd();
                                    //sun
	for(l=0;l<=30;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(120,625,l);
}
                                    //plane

                                    //grass
glColor3f(0.0,0.9,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();

}



else
{                                    //sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();
                    //moon
int l;
	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(100,625,l);
	}
                                    //grass
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();

}
                                //road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();

                                    //signal
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();
	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}
                                    //car 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(25+i,50);
glVertex2f(25+i,125);
glVertex2f(75+i,200);
glVertex2f(175+i,200);
glVertex2f(200+i,125);
glVertex2f(250+i,115);
glVertex2f(250+i,50);
glEnd();
                                    //windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(35+i,125);
glVertex2f(80+i,190);
glVertex2f(115+i,190);
glVertex2f(115+i,125);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(125+i,125);
glVertex2f(125+i,190);
glVertex2f(170+i,190);
glVertex2f(190+i,125);
glEnd();
for(l=0;l<20;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(75+i,50,l);
	draw_circle(175+i,50,l);
   }
                                    //car2
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-470+i,50);
glVertex2f(-470+i,112);
glVertex2f(-400+i,125);
glVertex2f(-372+i,210);
glVertex2f(-210+i,210);
glVertex2f(-180+i,125);
glVertex2f(-135+i,125);
glVertex2f(-110+i,50);
glEnd();
                                    //windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(-410+i,125);
glVertex2f(-364+i,200);
glVertex2f(-300+i,200);
glVertex2f(-300+i,125);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
    glVertex2f(-290+i,125);
    glVertex2f(-290+i,200);
    glVertex2f(-217+i,200);
    glVertex2f(-192+i,125);
glEnd();
for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-350+i,50,l);
	draw_circle(-200+i,50,l);
   }
glColor3f(0.7,0.0,0.9);
glBegin(GL_POLYGON);
glVertex2f(350+i,50);
glVertex2f(350+i,275);
glVertex2f(722+i,275);
glVertex2f(750+i,175);
glVertex2f(750+i,50);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(650+i,175);
glVertex2f(650+i,260);
glVertex2f(720+i,260);
glVertex2f(745+i,175);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(550+i,175);
glVertex2f(550+i,260);
glVertex2f(625+i,260);
glVertex2f(625+i,175);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(450+i,175);
glVertex2f(450+i,260);
glVertex2f(525+i,260);
glVertex2f(525+i,175);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(375+i,175);
glVertex2f(375+i,260);
glVertex2f(425+i,260);
glVertex2f(425+i,175);
glEnd();
for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(450+i,50,l);
	draw_circle(625+i,50,l);
   }
glFlush();
}
void traffic_light()
{
	int l;
if(light==1)
	  {
for(l=0;l<=20;l++)
		{
  glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
	glColor3f(0.0,0.7,0.0);
		draw_circle(1065,375,l);
		}
	  }
	else
	  {
for(l=0;l<=20;l++)
		{
		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,475,l);
	                                   // glColor3f(0.0,0.0,0.0);
                                    //draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
		}
	  }
}
void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
if(light==0 && (i>=330 && i<=750))  //value of i when first vehicle is near the traffic-signal
 {
	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(light==0 && (i>=830 && i<=1100)) //value of i when second vehicle is near the traffic-signal
 {
	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(light==0 && (i>=1200 && i<=1620))// value of i when third vehicle is near the traffic signal
 {
	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(light==0)
 {
	 i=i;
	 ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
else
 {
     i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>1630)
	 i=0.0;
if(m>1100)
	 m=0.0;
glutPostRedisplay();
}
void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'g':
case 'G':
light=1;
break;
	case 'r':
	case 'R':
		light=0;
		break;
case 'd':
	case 'D':
		day=1;
		break;
	case 'n':
case 'N':
		day=0;
		break;
    };
}
void main_menu(int index)
{
	switch(index)
	{

	case 1:
        if(index==1)
        {
            exit(0);
        }
    break;
	}
}
void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object();
traffic_light();
glFlush();
}
int main(int argc,char*argv[])
{
int c_menu;
    printf("\n");
    printf(" |===========================================================|\n");
    printf(" |     Graphics Project:-'Simulation of Traffic Control'     |\n");
    printf(" |===========================================================|\n");
    printf(" |                                                           |\n");
    printf(" #--------------- Help Center (How to Operate ?) ------------#\n");
	printf(" |  ->Press 'r' or 'R' to change the signal light to Red     |\n");
	printf(" |  ->Press 'g' or 'G' to change the signal light to Green   |\n");
	printf(" |  ->Press 'd' or 'D' to make it Day Time                   |\n");
	printf(" |  ->Press 'n' or 'N' to make it Night Time                 |\n");
	printf(" |                                                           |\n");
	printf(" |-----------------------------------------------------------|\n");

     glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(250,0);
	glutCreateWindow("Traffic Control");
	myinit();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	c_menu=glutCreateMenu(main_menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
