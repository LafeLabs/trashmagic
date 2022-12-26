#include <Adafruit_CircuitPlayground.h>
#include <math.h>

float X, Y, Z;

//P = Cos[omega*t]
float P[] = {1.00,0.92,0.71,0.38,0.00,-0.38,-0.71,-0.92,-1.00,-0.92,-0.71,-0.38,0.00,0.38,0.71,0.92};
//Q = Sin[omega*t]*Exp[t/tau]
float Q[] = {0.00,0.38,0.71,0.92,1.00,0.92,0.71,0.38,0.00,-0.38,-0.71,-0.92,-1.00,-0.92,-0.71,-0.38};
      
float p=0.0;  //integrated sin power
float q=0.0;  //integrated cos power
//x = input variable array
float x[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
float xmean = 0.0;
//y = input variable array
float y[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
float ymean = 0.0;

int m=0;
float F = 0.0;
float Fmax = 1023.0;
float Gamma = 7.0;
float vold = 0.0;
float vnew = 0.0;
int deltat = 30;  //3 Hz/8
float v=0.0;
float vmax = 255.0;
float vmin = 20.0;

float k = 20.0;
float n = 0.0;
int tau = 500;
int i = 0;
int red = 0;
int green = 0;
int blue = 0;
float z = 0.0;
float H = 0.0;


int motorpin = 6;

int motorspeed = 0;


void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(motorpin,OUTPUT);
  n = tau/deltat;
  analogWrite(motorpin,0);

}

void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

//  Serial.print(X);
 // Serial.print(",");
 // Serial.print(Y);
//  Serial.print(",");
 // Serial.println(Z);

  for (m = 15; m > 0; m--){
   x[m] = x[m-1]; 
   y[m] = y[m-1];
  }

  i++;
  if(i>15){
    i = 0;
  }

  
  x[0] = X;
  y[0] = Y;

  p=0.0;
  q=0.0;
  for (m = 0; m < 16;m++){
     p = p + P[m]*x[m];
     q = q + Q[m]*x[m];
  }
  F = k*sqrt(p*p + q*q)/16;

//add the second axis, repeating all math to get a force, then adding it to the main force, and dividing by 2 to normalize
  p=0.0;
  q=0.0;
  for (m = 0; m < 16;m++){
     p = p + P[m]*y[m];
     q = q + Q[m]*y[m];
  }
  F += k*sqrt(p*p + q*q)/16;

  F /= 2;

  if (F > Fmax){
    F = Fmax;
  }  
  vnew = vold + ((F*Gamma - vold)/n);
  
  vold = vnew;


  motorspeed = vnew;  
  if (vnew > vmax)
  {
    motorspeed = vmax;
  }  
  if (vnew < vmin){
    motorspeed = 0;
  }

  
  analogWrite(motorpin,motorspeed);
  
  //Serial.println(motorspeed);
  //Serial.println(Y);

  Serial.println(motorspeed);
  //we are turning a range from 0 to 1 into a hue, which is an angle around the color wheel
  //https://www.had2know.org/technology/hsv-rgb-conversion-formula-calculator.html
  //https://en.wikipedia.org/wiki/Hue
  
  H = motorspeed*360/255;//H is hue in degrees and ranges from 0 to 360.
  z = 255*(1 - abs(remainder((H/60.0),2) - 1));
  /*note that c and its derivatives won't let us take a modulo on a non integer
   * so we have to use remainder to get modulo, which is from math.h
   */
  if(H < 60){
     red = 255;
     green = round(z);
     blue = 0;
  }
  if(H >= 60 && H < 120){
    red = round(z);
    green = 255;
    blue = 0;
  }
  if(H >= 120 && H < 180){
      red = 0;
      green = 255;
      blue = round(z);
  }
  if(H >= 180 && H < 240){
      red = 0;    
      green = round(z);
      blue = 255;
  }
  if(H >= 240 && H < 300){
      red = round(z);    
      green = 0;
      blue = 255;
  }
  if(H >= 300 && H < 360){
      red = 255;    
      green = 0;
      blue = round(z);
  } 

     
  for(int ledpin = 0; ledpin < 10; ledpin++){
      CircuitPlayground.setPixelColor(ledpin, red, green, blue);  
      CircuitPlayground.setBrightness(motorspeed);
  }
  

//  Serial.print(",");
 // Serial.print(P[i]);
 // Serial.print(",");  
 // Serial.println(x[0]);
  
  //  Serial.print(","); Serial.print(event.acceleration.y); 
  //Serial.print(","); Serial.println(event.acceleration.z); 

  //Serial.println();
   

  delay(deltat); 

}
