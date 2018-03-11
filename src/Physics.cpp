#include<iostream>
using namespace std;
#include<GL/glut.h>
#include <algorithm>
#include<math.h>
#include <time.h>
#include <ctime>
#include <pthread.h>

#include "Start.h"

bool overlapBallTerrain(int i,int j)
{
	float e1=b[i].get_x();
	float e2=b[i].get_y();
	float e3=b[i].get_z();
	float r=b[i].get_radius();

	float x1=terrainCoor[j][0];
	float y1=terrainCoor[j][1];
	float z1=terrainCoor[j][2];	

	float dis=sqrt( (e1-x1)*(e1-x1)+(e2-y1)*(e2-y1)+(e3-z1)*(e3-z1) );

	if(dis<=r+0.5)
	return true;
	
	return false;	
}
void BalltoWall(int i)
{

    float tempx = b[i].get_x();
    float tempy = b[i].get_y();
    float tempz = b[i].get_z();

    float vmx   = b[i].get_vx();
    float vmy   = b[i].get_vy();
    float vmz   = b[i].get_vz();

    float radii = b[i].get_radius();

    if( tempx>=9.0f-radii || tempx<=terr_x+radii+1.0)    
    {   
       	if(tempx>=9.0f-radii)
    	{
    		b[i].set_x(9.0f-radii);
    	}    
        else
        {
            b[i].set_x(terr_x+radii+1.0);    
        }
        
        b[i].set_vx(-1*vmx);
        vmx=-1*vmx;
    }    
    
    if( tempy>=2.25f-radii || tempy<=-2.25f+radii)    
    {   
        if(tempy>=2.25f-radii)
        {
        	b[i].set_y(2.25f-radii);
        }
        else
        {
        	b[i].set_y(-2.25f+radii);    
        }
        
        b[i].set_vy(-1*vmy);    
        vmy=-1*vmy;
    }
    
    if( tempz>=3.0f-radii || tempz<=-3.0f+radii)    
    {   
        if(tempz>=3.0f-radii)
        	b[i].set_z(3.0f-radii);
        else
        	b[i].set_z(-3.0f+radii);    

        b[i].set_vz(-1*vmz);
        vmz=-1*vmz;
    }

	tempx = b[i].get_x();
    tempy = b[i].get_y();
    tempz = b[i].get_z();

    b[i].set_x(tempx+vmx*0.1);
    b[i].set_y(tempy+vmy*0.1);
    b[i].set_z(tempz+vmz*0.1);    
    
    tempx = b[i].get_x();
    tempy = b[i].get_y();
    tempz = b[i].get_z();

    vmx   = b[i].get_vx();
    vmy   = b[i].get_vy();
    vmz   = b[i].get_vz();

    radii = b[i].get_radius();

    float ux,uy,uz;
    float mod;

    for(int j=0;j<10;j++)
    {
    	if(overlapBallTerrain(i,j))
    	{	
    		float x2=terrainCoor[j][0],y2=terrainCoor[j][1],z2=terrainCoor[j][2];

    		ux=tempx-x2;
    		uy=tempy-y2;
    		uz=tempz-z2;

	    	mod=sqrt(ux*ux+uy*uy+uz*uz);
	    	    		
     		ux=ux/mod;
     		uy=uy/mod;     
     		uz=uz/mod;

     	    float v1dotu = vmx*ux + vmy*uy + vmz*uz;

		    float vx1f =  vmx - 2*(v1dotu)*ux;
     		float vy1f =  vmy - 2*(v1dotu)*uy;
     		float vz1f =  vmz - 2*(v1dotu)*uz;

     		float av=tempx,bv=tempy,cv=tempz;
	     	if(mod <=radii+0.5 && v1dotu!=0)
    		{   
        		float diff=radii+0.5-mod;
        		float t= (float) diff/(float)v1dotu ;

        		float posi=abs(v1dotu*t);
        		av=tempx-posi;
        		bv=tempy-posi;
        		cv=tempz-posi;
       
	        	float q2=(av-x2)*(av-x2);
    	    	float w2=(bv-y2)*(bv-y2);
        		float e2=(cv-z2)*(cv-z2);

        		float mod2=sqrt(q2+w2+e2);
        
        		if(mod2<mod)
        		{   
            		av=tempx+posi;
            		bv=tempy+posi;
            		cv=tempz+posi;

            		av=av+0.01;
            		bv=bv+0.01;
            		cv=cv+0.01;    
        		}
		        else
        		{
            		av=av-0.01;
            		bv=bv-0.01;
            		cv=cv-0.01;    
        		}    

    		}

    		b[i].set_x(av);
			b[i].set_y(bv);
     		b[i].set_z(cv);


	     	b[i].set_x(av+vx1f*0.1);
			b[i].set_y(bv+vy1f*0.1);
	     	b[i].set_z(cv+vz1f*0.1);
	     	b[i].set_v(vx1f,vy1f,vz1f);
	     	break;

		}	
	}	


}

bool overlapBallBall(int i,int j)
{   
    float tempx1 = b[i].get_x();
    float tempy1 = b[i].get_y();
    float tempz1 = b[i].get_z();

    float tempx2 = b[j].get_x();
    float tempy2 = b[j].get_y();
    float tempz2 = b[j].get_z();

    float distancesqr=pow((tempx2-tempx1),2) + pow((tempy2-tempy1),2) + pow((tempz2-tempz1),2);
   
    float r1 = b[i].get_radius();
    float r2 = b[j].get_radius();

    float var=pow((r1+r2),2);
    
    return (distancesqr<=var);

}

void hack()
{
    return ;
}


void colrenew()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            collision[i][j]=false;
        }   
    }
}

void BalltoBall(int i,int j)
{

    float vx1=b[i].get_vx();
    float vy1=b[i].get_vy();
    float vz1=b[i].get_vz();

    float vx2=b[j].get_vx();
    float vy2=b[j].get_vy();
    float vz2=b[j].get_vz();

    float xx1=b[i].get_x();
    float yy1=b[i].get_y();
    float zz1=b[i].get_z();

    float x2=b[j].get_x();
    float y2=b[j].get_y();
    float z2=b[j].get_z();

    float ux=(x2-xx1);
    float uy=(y2-yy1);
    float uz=(z2-zz1);

    float r1=b[i].get_radius();
    float r2=b[j].get_radius(); 

    float mod=sqrt(ux*ux+uy*uy+uz*uz);


    ux=ux/mod;
    uy=uy/mod;
    uz=uz/mod;



    float v2dotu = vx2*ux + vy2*uy + vz2*uz;
    float v1dotu = vx1*ux + vy1*uy + vz1*uz;

    float vx1f =  v2dotu*ux + vx1 - (v1dotu)*ux;
    float vy1f =  v2dotu*uy + vy1 - (v1dotu)*uy;
    float vz1f =  v2dotu*uz + vz1 - (v1dotu)*uz;

    float vx2f =  v1dotu*ux + vx2 - (v2dotu)*ux;
    float vy2f =  v1dotu*uy + vy2 - (v2dotu)*uy; 
    float vz2f =  v1dotu*uz + vz2 - (v2dotu)*uz;

    float av=xx1,bv=yy1,cv=zz1;

    if(mod <r1+r2 && v1dotu!=0)
    {   
        float diff=r1+r2-mod;

        float t= (float) diff/(float)v1dotu ;

        float posi=abs(v1dotu*t);

        av=xx1-posi;
        bv=yy1-posi;
        cv=zz1-posi;
    
        float q2=(av-x2)*(av-x2);
        float w2=(bv-y2)*(bv-y2);
        float e2=(cv-z2)*(cv-z2);

        float mod2=sqrt(q2+w2+e2);

        if(mod2<mod)
        {   
            av=xx1+posi;
            bv=yy1+posi;
            cv=zz1+posi;

            av=av+0.01;
            bv=bv+0.01;
            cv=cv+0.01;    
        }
        else
        {
            av=av-0.01;
            bv=bv-0.01;
            cv=cv-0.01;    
        }    

    }        
    
    b[i].set_x(av);
    b[i].set_y(bv);             
    b[i].set_z(cv);

    b[i].set_v(vx1f,vy1f,vz1f);
    b[j].set_v(vx2f,vy2f,vz2f);

    b[i].set_x(av+vx1f*0.1);
    b[i].set_y(bv+vy1f*0.1);
    b[i].set_z(cv+vz1f*0.1);

    b[j].set_x(x2+vx2f*0.1);
    b[j].set_y(y2+vy2f*0.1);
    b[j].set_z(z2+vz2f*0.1);

}
