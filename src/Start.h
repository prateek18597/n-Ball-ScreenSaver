#ifndef START_H
#define START_H

#include "Ball.h"

extern pthread_mutex_t myMutex;
extern int n;
extern pthread_t tid;
extern Ball b[100];
extern bool collision[100][100];
extern float terrainCoor[10][3];
extern int pauseCount;
extern int pauseEnter;
extern int rotateY;
extern int rotateZ;
extern float temp_v[100][3];
extern float temp_x[100];
extern float temp_y[100];
extern float temp_z[100];
extern int selectedBall;
extern float terr_x;
extern int t_check;

void getValueofN(int num);
void GenerateBalls();

#endif