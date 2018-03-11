#include<iostream>
using namespace std;
#include<GL/glut.h>
#include <algorithm>
#include<math.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <pthread.h>
#include "Graphics.h"
#include "Physics.h"
#include "Threads.h"
#include "Controls.h"
#include "Start.h"

void mouseController(int button, int state, int x, int y);
void getValueofN(int num);
void GenerateBalls();
void display(void);
void idleStateFunction(void);
void changeSize(int w, int h);
void specialKeys(int key, int xx, int yy);
void normalKeys(unsigned char key, int x, int y);

int main(int argc, char **argv)
{
	int Num_ball;
    Num_ball=atoi(argv[1]);
    
    if(!(Num_ball<=99 && Num_ball>=1))//Taking the value of num_thread
	{
		cout<<"Please Make Sure to Enter num_thread Positive and less than 100.\nEnter Number of Balls: ";
		cin>>Num_ball;
	}
	
	if((Num_ball<=99 && Num_ball>=1))
	{
		glutInit(&argc, argv); //Initializing GLUT
	    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	    glutInitWindowSize(1366,960);
	    glutInitWindowPosition(0,0);
	    glutCreateWindow("2016CSJ0049_2016CSJ0002");
	    getValueofN(Num_ball);
	    GenerateBalls();
	    glutDisplayFunc(display);
	    glutIdleFunc(idleStateFunction);
	    glutReshapeFunc(changeSize);
	    glutSpecialFunc(specialKeys);
	    glutMouseFunc(mouseController);
	    glutKeyboardFunc(normalKeys);
	    glutFullScreen();
	    glEnable(GL_DEPTH_TEST);
		glutMainLoop();
			
	}
	
	return 0;
}