
int delay_time = 30;//ms

int x = 10;
int index = 0;


//Chaos demo
//calculate chaotic driven damped pendulum trajectory using fourth order Runge-Kutta
// 
 
  float t = 0.0;
  int period = 15;
  float y[] = {0.0,0.0};
  float E;
  float f0 = 0.0;  //velocity
  float f1 = 0.0;  //accelleration
  float f[] = {0.0,0.0};
  float k1[] = {0.0,0.0};
  float k2[] = {0.0,0.0};
  float k3[] = {0.0,0.0};
  float k4[] = {0.0,0.0};
  
  float theta = 0.0;
  float thetadot = 0.0;
  float force;
      
  float pi = 3.14159;

  float yindex = 0.1;
  float ynext[] = {0.0,0.0};
 
  float gamma = 0.4; 
  float omega0 = 0.65;
  float h = 0.02; //time step in fractions of natural period 
  float A = 1.3;  

 
  int motorpin = 5;
  int motorspeed = 0;


 
void setup() {
   Serial.begin(9600);
}


void loop() {

  force = 0;
  
  k1[0] = getf0(t,y,gamma,omega0,A,force);
  k1[1] = getf1(t,y,gamma,omega0,A,force);

  ynext[0] = y[0] + 0.5*h*k1[0];
  ynext[1] = y[1] + 0.5*h*k1[1];
  
  k2[0] = getf0(t+0.5*h,ynext,gamma,omega0,A,force);
  k2[1] = getf1(t+0.5*h,ynext,gamma,omega0,A,force);

  ynext[0] = y[0] + 0.5*h*k2[0];
  ynext[1] = y[1] + 0.5*h*k2[1];
  
  k3[0] = getf0(t+0.5*h,ynext,gamma,omega0,A,force);
  k3[1] = getf1(t+0.5*h,ynext,gamma,omega0,A,force);

  ynext[0] = y[0] + h*k3[0];
  ynext[1] = y[1] + h*k3[1];

  k4[0] = getf0(t+h,ynext,gamma,omega0,A,force);
  k4[1] = getf1(t+h,ynext,gamma,omega0,A,force);
  
  
  ynext[0] = y[0] + 0.1667*h*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
  ynext[1] = y[1] + 0.1667*h*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);  


  theta = 255.0*abs(y[0])/pi;
  thetadot = 255.0*abs(y[1])/pi;

  //wrap the angle around if it goes above or below pi
  if(ynext[0] >= pi){
     ynext[0] = ynext[0] - 2*pi;
  }
  if(ynext[0] <= -pi){
     ynext[0] = ynext[0] + 2*pi;
  }

  y[0] = ynext[0];
  y[1] = ynext[1];

  t = t + h;
         
  x = int(theta);
  Serial.println(thetadot);
  motorspeed = theta;
  analogWrite(motorpin,motorspeed);

  
}


float getf0(float t,float y[],float gamma, float omega0, float A,float force){
  float result;
  result = y[1];
  return result;
}
float getf1(float t,float y[],float gamma, float omega0,float A, float force){
  float result;
  result = -sin(y[0]) - gamma*y[1] + A*cos(omega0*t) + force;
  return result;
}
