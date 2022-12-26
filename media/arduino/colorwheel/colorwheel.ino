#include <Adafruit_CircuitPlayground.h>
#include <math.h>


int red = 0;
int green = 0;
int blue = 0;
float z = 0.0;
float H = 0.0;

int deltat = 10;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {


  //we are turning a range from 0 to 1 into a hue, which is an angle around the color wheel
  //https://www.had2know.org/technology/hsv-rgb-conversion-formula-calculator.html
  //https://en.wikipedia.org/wiki/Hue
  
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
      CircuitPlayground.setBrightness(200);
  }

  H += 1.0;
  if(H>360){
    H = 0.0;
  }

  Serial.print(red);
  Serial.print(",");
  Serial.print(green);
  Serial.print(",");
  Serial.println(blue);
  delay(deltat); 

}
