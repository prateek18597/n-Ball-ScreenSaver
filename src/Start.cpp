#include<iostream>
using namespace std;
#include <algorithm>
#include<pthread.h>
#include "Start.h"
#include "Threads.h"

int n;
int t_check;

float terr_x;

int selectedBall;
int pauseCount;
int pauseEnter;

bool collision[100][100];

Ball b[100];

pthread_mutex_t myMutex;
pthread_t tid;

int rotateY;
int rotateZ;

float terrainCoor[10][3];

void getValueofN(int num)
{
	n=num;
}



void InputTerrain()
{
 	terrainCoor[0][0]=0.0;	//Initializing x coordinates of Terrain Objects
	terrainCoor[1][0]=1.0;
	terrainCoor[2][0]=2.0;
	terrainCoor[3][0]=-3.0;
	terrainCoor[4][0]=3.0;
	terrainCoor[5][0]=7.0;
	terrainCoor[6][0]=-4.0;
	terrainCoor[7][0]=6.5;
	terrainCoor[8][0]=-3.0;
	terrainCoor[9][0]=7.5;

    terrainCoor[0][1]=-2.25;	//Initializing y coordinates of Terrain Objects
    terrainCoor[1][1]=2.25;
    terrainCoor[2][1]=0.0;
    terrainCoor[3][1]=-2.25;
    terrainCoor[4][1]=0.0;
    terrainCoor[5][1]=-2.25;
    terrainCoor[6][1]=-2.25;
    terrainCoor[7][1]=1.2;
    terrainCoor[8][1]=1.25;
    terrainCoor[9][1]=1.72;

    terrainCoor[0][2]=2.0;		//Initializing z coordinates of Terrain Objects
    terrainCoor[1][2]=-1.0;
    terrainCoor[2][2]=3.0;
    terrainCoor[3][2]=0.0;
    terrainCoor[4][2]=-3.0;
    terrainCoor[5][2]=-1.5;
    terrainCoor[6][2]=2.0;
    terrainCoor[7][2]=-3.0;
    terrainCoor[8][2]=-3.0;
    terrainCoor[9][2]=3.0;   
}


void GenerateBalls()
{
	t_check=1;
	terr_x=-9.0f;
	
	pauseCount=0;
	pauseEnter=0;
	
	selectedBall=0;
	
	rotateY=0;
	rotateZ=0;
	
	std::random_device rnd;
    std::mt19937 gen(rnd());

    std::uniform_real_distribution<> disr(0.2,0.5);		//Random Distribution of Velocity and positions of Balls.
    std::uniform_real_distribution<> disy(-2.25+0.5,2.25-0.5);
    std::uniform_real_distribution<> disx(-6,6);
    std::uniform_real_distribution<> disz(-2.5,2.5);
    std::uniform_real_distribution<> disv(-0.07,0.07);
    
    for(int i=1;i<=n;i++)
    {    
        b[i].set_x(disx(gen));
        b[i].set_y(disy(gen));
        b[i].set_z(disz(gen));
        b[i].set_v(disv(gen),disv(gen),disv(gen));
        b[i].set_radius(disr(gen));
    }

    InputTerrain();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            collision[i][j]=false;
        }   
    }

    pthread_mutex_init(&myMutex,0);

    for(long int j=1;j<=n;j++)
    {
        pthread_create(&tid,NULL,initThreads,(void *)j);
    }
}
