#include<iostream>
using namespace std;

#include<GL/glut.h>
#include<math.h>
#include <pthread.h>
#include "Start.h"
#include "Graphics.h"
#include "Threads.h"
#include "Physics.h"

GLfloat black[] = {0.0, 0.0, 0.0, 1.0};
GLfloat green[] = {0.0, 1.0, 0.0, 1.0};
GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
GLfloat red[] = {1.0, 0.0, 0.0, 1.0};
GLfloat blue[] = {0.0, 0.0, 1.0, 1.0};
GLfloat orange[] = {1.0, 1.0, 0.0, 1.0};
GLfloat cyan[] = {0.0, 0.6, 0.6, 1.0};


GLfloat qaAmbientLight[]    = {0.2, 0.2, 0.2, 1.0};
GLfloat qaDiffuseLight[]    = {0.8, 0.8, 0.8, 1.0};
GLfloat qaSpecularLight[]    = {1.0, 1.0, 1.0, 1.0};
GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.01};
GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};
GLfloat qaLightPosition[]  =   {0.5, 0, -3.5, 0.5};

void initLighting()
{   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

void changeSize(int width, int height) {
    if(height == 0)
        height = 1;
    float ratio = 1.0* width / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(45,ratio,1,1000);
    glMatrixMode(GL_MODELVIEW);
}

void Terrain(float xt,float yt,float zt)
{
    glTranslatef(xt,yt,zt);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, white);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	glutSolidSphere(0.5,25,25);

    glTranslatef(-xt,-yt,-zt);    
}

void DrawCube()
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, white);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
    
    glBegin(GL_QUADS);
        
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(-9.0f, -2.25f, -3.0f);
        glVertex3f(-9.0f, -2.25f,  3.0f);
        glVertex3f( 9.0f, -2.25f,  3.0f);
        glVertex3f( 9.0f, -2.25f, -3.0f);
    
    glEnd();
    
    glBegin(GL_QUADS);
    
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(-9.0f, 2.25f, -3.0f);
        glVertex3f(-9.0f, 2.25f,  3.0f);
        glVertex3f( 9.0f, 2.25f,  3.0f);
        glVertex3f( 9.0f, 2.25f, -3.0f);
    
    glEnd();
   
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cyan);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
    


	glBegin(GL_QUADS);//vetical
    
    	glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(-9.0f, -2.25f, -3.0f);
        glVertex3f(-9.0f, -2.25f,  3.0f);
        glVertex3f( -9.0f, 2.25f,  3.0f);
        glVertex3f( -9.0f, 2.25f, -3.0f);
    
    glEnd();
    
    glBegin(GL_QUADS);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(9.0f, -2.25f, -3.0f);
        glVertex3f(9.0f, -2.25f,  3.0f);
        glVertex3f( 9.0f, 2.25f,  3.0f);
        glVertex3f( 9.0f, 2.25f, -3.0f);
    glEnd();
    
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, white);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
    
    glBegin(GL_QUADS);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(-9.0f, -2.25f, -3.0f);
        glVertex3f(9.0f, -2.25f,  -3.0f);
        glVertex3f( 9.0f, 2.25f,  -3.0f);
        glVertex3f( -9.0f, 2.25f, -3.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(-9.0f, -2.25f, 3.0f);
        glVertex3f(9.0f, -2.25f,  3.0f);
        glVertex3f( 9.0f, 2.25f,  3.0f);
        glVertex3f( -9.0f, 2.25f, 3.0f);

    glEnd();


    for(int i=0;i<10;i++)
    {
        Terrain(terrainCoor[i][0],terrainCoor[i][1],terrainCoor[i][2]);
    }

}

float rotx=0.0,roty=0.0,rotz=0.0;
int check_roty=1;
int check_rotz=1;

void display(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    initLighting();

    gluLookAt( terr_x , 0.0f, 0.0f,
            rotx, roty*rotateY,  rotz*rotateZ,
            0.0f, 1.0f,  0.0f);

    DrawCube();

    glColor3f(1.0f, 0.0f, 0.0f);
   
    float xpos,ypos,zpos,radii;

    for(int i=1;i<=n;i++)
    {   
        xpos = b[i].get_x();
        ypos = b[i].get_y();
        zpos = b[i].get_z();
        radii = b[i].get_radius();

        glTranslatef(xpos,ypos,zpos);

        switch(i%5)
        {

            case 0:
            		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green);
					glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, green);
        		break;
            
            case 1:	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, orange);
					glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, orange);
        		break;
        
            case 2:	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
			        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
        		break;
        
            case 3:	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue);
			        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blue);
        		break;
        
            case 4:	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);
			        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black);
        		break;
        }
       
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

        glutSolidSphere(radii,25,25);

        glTranslatef(-xpos,-ypos,-zpos);
    }    
    
    if(terr_x>-1.0 || terr_x<-9.0)//For movement of Camera
    {
        t_check*=-1;
    }
    
    terr_x+=0.01*t_check;

    if(roty>=8*3.14/180 ||roty<=-8*3.14/180)// For Giving EarthQuake Effect
    {
    	check_roty*=-1;	
    }
    
    roty+=check_roty*0.7*3.14/180.0;
    
    if(rotz>=5*3.14/180 ||rotz<=-5*3.14/180)//For Giving Tordado Effect
    {
    	check_rotz*=-1;	
    }
    
    rotz+=check_rotz*0.5*3.14/180.0;
    	
    glFlush();
    glutSwapBuffers();
}

void idleStateFunction(void) //This function will execute when the program reaches idle state
{
    display();
}
