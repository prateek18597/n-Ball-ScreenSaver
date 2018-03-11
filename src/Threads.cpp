#include<iostream>
using namespace std;
#include <algorithm>
#include<math.h>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <pthread.h>
#include "Physics.h"
#include "Threads.h"
#include "Start.h"

void* initThreads(void* x) 
{
    
    int j=(long int) x;
    
    float tx,ty,tz;
    
    while(true)
    {
    
    BalltoWall(j);
    
    tx=b[j].get_x();
    ty=b[j].get_y();
    tz=b[j].get_z();

    tx = tx +  b[j].get_vx()*0.1 ;
    ty = ty +  b[j].get_vy()*0.1 ;
    tz = tz +  b[j].get_vz()*0.1 ;
    
    b[j].set_x(tx);
    b[j].set_y(ty);
    b[j].set_z(tz);

    pthread_mutex_lock(&myMutex);   
    
    for(int i=j+1;i<=n;i++)
    {
       if(overlapBallBall(i,j) && !collision[i][j] && !collision[j][i] )        
       {    
                  
            collision[i][j]=true;
            collision[j][i]=true;

            BalltoBall(i,j);
            
            hack();   
       }
             
    }   
    
    pthread_mutex_unlock(&myMutex);
     
    colrenew();

    usleep(2000);

    }

}
