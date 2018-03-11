#include<iostream>
using namespace std;	
#include<GL/glut.h>
#include <algorithm>
#include<math.h>
#include <time.h>
#include <ctime>
#include <pthread.h>
#include "Controls.h"
#include "Start.h"

float temp_v[100][3]; //Temporary storage of velocity of balls
float temp_x[100];		//Temporary storage of x coor of balls
float temp_y[100];		//Temporary storage of y coor of balls
float temp_z[100];		//Temporary storage of z coor of balls

int ryCount=0;
int rzCount=0;

void specialKeys(int key, int xx, int yy) //Keyboard Function for Arrow Keys and Function keys.
{
    switch (key) {
        case GLUT_KEY_LEFT :
                
                if(selectedBall==0)
                {
                
	                for(int i=1;i<=n;i++)
	                {
	                    if(abs(b[i].get_vx())>0.001)
	                    {
	                        b[i].set_vx(b[i].get_vx()*0.97);   
	                    }
	                    if(abs(b[i].get_vy())>0.001)
	                    {
	                        b[i].set_vy(b[i].get_vy()*0.97);   
	                    }
	                    if(abs(b[i].get_vz())>0.001)
	                    {
	                        b[i].set_vz(b[i].get_vz()*0.97);   
	                    }
	      		    }   
         		}
                else
                {
                    if(abs(b[selectedBall].get_vx())>0.001)
                    {
                        b[selectedBall].set_vx(b[selectedBall].get_vx()*0.97);   
                    }
                    if(abs(b[selectedBall].get_vy())>0.001)
                    {
                        b[selectedBall].set_vy(b[selectedBall].get_vy()*0.97);   
                    }
                    if(abs(b[selectedBall].get_vz())>0.001)
                    {
                        b[selectedBall].set_vz(b[selectedBall].get_vz()*0.97);   
                    }
                }
            
            	break;
        case GLUT_KEY_RIGHT :
            
            	if(selectedBall==0)
            	{
	                for(int i=1;i<=n;i++)
	                {
	                    if(abs(b[i].get_vx())<0.08)
	                    {
	                        b[i].set_vx(b[i].get_vx()*1.03);   
	                    }
	                    if(abs(b[i].get_vy())<0.08)
	                    {
	                        b[i].set_vy(b[i].get_vy()*1.03);   
	                    }
	                    if(abs(b[i].get_vz())<0.08)
	                    {
	                        b[i].set_vz(b[i].get_vz()*1.03);   
	                    }
	                }
	            }
                else
                {
                    if(abs(b[selectedBall].get_vx())<0.08)
                    {
                        b[selectedBall].set_vx(b[selectedBall].get_vx()*1.03);   
                    }
                    if(abs(b[selectedBall].get_vy())<0.08)
                    {
                        b[selectedBall].set_vy(b[selectedBall].get_vy()*1.03);   
                    }
                    if(abs(b[selectedBall].get_vz())<0.08)
                    {
                        b[selectedBall].set_vz(b[selectedBall].get_vz()*1.03);   
                    }
                }
            	break;
        
        case GLUT_KEY_UP :
            
            if(selectedBall==0)
            {
                for(int i=1;i<=n;i++)
                {
                    if(b[i].get_radius()<0.5)
                    {
                        b[i].set_radius(b[i].get_radius()+0.01);   
                    }
                }
            }
            else
            {	
            	if(b[selectedBall].get_radius()<0.5)
                b[selectedBall].set_radius(b[selectedBall].get_radius()+0.01);
            }
            break;

        case GLUT_KEY_DOWN :
            if(selectedBall==0)
            {
	            for(int i=1;i<=n;i++)
	            {
	                if(b[i].get_radius()>0.2)
	                {
	                    b[i].set_radius(b[i].get_radius()-0.01);   
	                }
	            }
	        }
            else
            {
            	if(b[selectedBall].get_radius()>0.2)
                b[selectedBall].set_radius(b[selectedBall].get_radius()-0.01);
            }
            break;
 		
 		case GLUT_KEY_F1:
 				
 				ryCount++;
 				if(ryCount%2==1)
 					rotateY=1;
 				else
 					rotateY=0;

 			break;
 		case GLUT_KEY_F2:
 			
 				rzCount++;
 				if(rzCount%2==1)
 					rotateZ=1;
 				else
 					rotateZ=0;

 			break;
 		
 		case GLUT_KEY_F3:
 		
 				if(selectedBall>=2)
 					selectedBall=selectedBall-1;
 				else
 					selectedBall=n;
 			break;
 		
 		case GLUT_KEY_F4:
    	
    			selectedBall+=1;
    	
    			if(selectedBall>n)
    			{
    				selectedBall=1;
    			}
    		break;
    }
}

int prev_tcheck;

void normalKeys(unsigned char key, int x, int y) //Keyboard Function for Normal Keys with ascii value.
{

    if (key == 27)
    {    
    	cout<<"Good Bye !!!"<<endl;
        exit(0);
    }

    if (key == 32)
    {
        if(pauseCount%2==0)
        {
            for(int i=1;i<=n;i++)
            {
                temp_v[i][0]=b[i].get_vx();
                temp_v[i][1]=b[i].get_vy();
                temp_v[i][2]=b[i].get_vz();
                b[i].set_vx(0.0);
                b[i].set_vy(0.0);
                b[i].set_vz(0.0);
                temp_x[i]=b[i].get_x();
                temp_y[i]=b[i].get_y();
                temp_z[i]=b[i].get_z();
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
            	b[i].set_vx(temp_v[i][0]);
                b[i].set_vy(temp_v[i][1]);
                b[i].set_vz(temp_v[i][2]);
            }
        }
        pauseCount++;
    }
    
    if(key>=97 || key<=122)
    {
        selectedBall=key%96;
    }

    if(key==127)
    {
        selectedBall=0;
    }
    
    if(key==13)
    {
    	if(pauseEnter%2==0)
        {
            prev_tcheck=t_check;
            t_check=0;
        }
        else
        {
            t_check=prev_tcheck;
        }  
        pauseEnter++;
    }	
}

void mouseController(int button, int state, int x, int y) // Mouse Controller
{

    if (button == GLUT_LEFT_BUTTON) {
       if (state == GLUT_UP) {
             terr_x=-9.0f;
            t_check=1;
        }
    }
    else
        if(button == GLUT_RIGHT_BUTTON)
        {
            terr_x=9.0f;
            t_check=-1;
        }
}
