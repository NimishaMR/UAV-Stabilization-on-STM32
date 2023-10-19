#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define PI 3.14159265
using namespace std;

class Torque {
    float errval1 = 0.009;
    public:
    float initTorque;
    Torque(float x) {
        initTorque= x;
    }
    float dt = 0.001;
     float amp = 1;
     float omega = 0.1;

    const float m_inertia = 0.1;

    float computey(float m_inertia, float dt, float theta, float thetaDot) {
    static float omega = 0.1F;
	static float amplitude = 1;
	static float angle = 0;
    float dt1 = 0.001;
	angle += omega * dt1;
    float theta1 = sin (angle*PI/180);
    float thetaDot1 = cos(angle*PI/180);
        float y = (m_inertia/(2*dt))*((theta1/dt) + (thetaDot1));
        return y;
    }
            float sinetheta = -0.05; //theta
        float cosinetheta = 0; //thetadot
    float computeTorque(float m_inertia, float dt, int amp,float  sinetheta, float cosinetheta) {

    static float omega = 0.1F;
	static float amplitude = 1;
	static float angle = 0;
    float dt1 = 0.001;
	angle += omega * dt;
    float sinetheta1 = sin (angle*PI/180);
    float cosinetheta1 = cos(angle*PI/180);
       float h_x = (m_inertia/2*dt)*(amp*sinetheta1/dt + amp*omega*cosinetheta1);
    //    cout<<"Testing output of h_x: "<<endl;
       return h_x;
    }

    float computeError(float m_inertia, float dt, float theta, float thetaDot,int amp,float  sinetheta, float cosinetheta) {

    
            float y = (m_inertia/2*dt)*((theta/dt) + thetaDot);
               static float omega = 0.1F;
	static float amplitude = 1;
	static float angle = 0;
    float dt1 = 0.001;
	angle += omega * dt;
    float sinetheta1 = sin(angle*PI/180);
    float cosinetheta1 = cos(angle*PI/180);
        float h_x = (m_inertia/2*dt)*(amp*sinetheta/dt + amp*omega*cosinetheta);
      // return h_x;
    float j_theta = h_x - y; 
    return j_theta;
    }
    

int rewardStep;

    float rewardFunc(float j_theta, float rewardStep) {

    while(1) {
            static float omega = 0.1F;
	static float amplitude = 1;
	static float angle = 0;
    float dt1 = 0.001;
	angle += omega * dt1;
    float theta1 = sin (angle*PI/180);
    float thetaDot1 = cos(angle*PI/180);
        float y = (m_inertia/(2*dt))*((theta1/dt) + (thetaDot1));
         if(y>0) {
            y-=rewardStep;
        }else if(y<0) {
            y+=rewardStep;
        }else {
            cout<<"IDEAL VALUE REACHED..."<<endl;
        }
        
        return y;
    }
    }
    
    float updatedComputeTorque(float j_theta) {

        while(1) {
    float y =  computey(0.1, 0.001,0.05,0.1);
    float h_x= computeTorque(0.1,0.001,1,-0.05,0.0);
        if(h_x==y) {
            cout<<"MATCH..."<<endl;
        }else if(h_x!=y) {
            computeError(2.0,2.0,0.02,0.01,1,-0.05,0.0);
        }
  return (h_x-y);        
    }
    }
    void computError(float errval) {
        
            errval1= errval1 - errval - 0.01;
        //    return errval;
           cout<<"COMPUTING ERROR..."<<endl;
           cout<<errval1<<endl;
           cout<<endl;
        
    }

};

//driver
int main() {

    Torque t1(0.0);
    cout<<"Process started"<<endl;
    cout<<"linking objects at runtime"<<endl;
    cout<<endl;

    while(1) {

  
  float resy = t1.computey(0.1, 0.001,0.000005,0.0000001);
    cout<<endl;
  cout<<"COMPUTING DESIRED TORQUE..."<<endl;
  cout<<resy<<endl;
  cout<<endl;
  
  

 
 t1.computError(0.009);
  


   float resuct =  t1.updatedComputeTorque(0.001);
     cout<<"COMPUTING UPDATED TORQUE..."<<endl;
  cout<<resuct<<endl;
  cout<<endl;
  cout<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;
    }

       float rew1 =  t1.rewardFunc(1.0,0.1);
     cout<<" Reward..."<<endl;
  cout<<rew1<<endl;
  cout<<endl;
    
    return 0;

}

