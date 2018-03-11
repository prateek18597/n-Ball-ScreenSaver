class Ball
{

     private:
     
        float x,y,z;

        float vx,vy,vz;
         
        float r,g,b;
        
        float radius;
     
     public:    

        float get_radius()
        {
            return radius;
        }

        void increment_radius()
        {
            radius+=0.1;    
        }
     
        float get_x()
        {
            return x;
        }
     
        void set_x(float val)
        {
            x=val;
        }
     
        void set_y(float val)
        {
            y=val;
        }
    
        void set_z(float val)
        {
            z=val;
        }
        
        float get_y()
        {
            return y;
        }
        
        float get_z()
        {
            return z;
        }

        float get_vx()
        {
            return vx;
        }
        
        float get_vy()
        {
            return vy;
        }

        float get_vz()
        {
            return vz;
        }

        float get_r()
        {
            return r;
        }        

        float get_g()
        {
            return g;
        }
     
        float get_b()
        {
            return b;
        }

        void set_vx(float val)
        {
            vx=val;
        }
        
        void set_vy(float val)
        {
            vy=val;
        }
        
        void set_vz(float val)
        {
           vz=val;
        }

        void set_v(float v1,float v2,float v3)
        {
            vx=v1;
            vy=v2;
            vz=v3;
        }

        void set_r(float val)
        {
            r=val;
        }        

        void set_g(float val)
        {
            g=val;
        }

        void set_b(float val)
        {
            b=val;
        }

        void set_radius(float val)
        {
            radius=val;
        }
};
