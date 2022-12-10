// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 30

int knob = 0;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)



// XY gyrator

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

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
float vold = 0.0;
float vnew = 0.0;
int deltat = 30;  //3 Hz/8
float v=0.0;
float vmax = 255.0;
float vmin = 20.0;

//float gamma = 7.0;
//float k = 20.0;
float k = 140.0;

float n = 0.0;
int tau = 500;
int i = 0;

int motorpin = 5;

int motorspeed = 0;



// setup() function -- runs once at startup --------------------------------


void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  knob = analogRead(A2)/4;
  strip.setBrightness(x); // Set BRIGHTNESS to about 1/5 (max = 255)

  n = tau/deltat;
  pinMode(motorpin,OUTPUT);
  analogWrite(motorpin,0);

  Serial.begin(9600);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("LIS3DH test!");
  
  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1) yield();
  }
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  
  Serial.print("Range = "); Serial.print(2 << lis.getRange());  
  Serial.println("G");
  
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {

  rainbow(60);             // Flowing rainbow cycle along the whole strip  

}


// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }

    knob = analogRead(A2)/4;//0 to 255
    
    for (m = 15; m > 0; m--){
   x[m] = x[m-1]; 
   y[m] = y[m-1];
  }

  i++;
  if(i>15){
    i = 0;
  }

  
  lis.read();      // get X Y and Z data at once

  /* Or....get a new sensor event, normalized */ 
  sensors_event_t event; 
  lis.getEvent(&event);
  
  /* Display the results (acceleration is measured in m/s^2) */

  x[0] = event.acceleration.x;
  y[0] = event.acceleration.y;

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

  vnew = vold + ((F - vold)/n);  
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

  Serial.println(motorspeed);

    
    knob = motorspeed;
    strip.setBrightness(knob); // Set BRIGHTNESS to x
    strip.show(); // Update strip with new contents
    wait = 64 - knob/4;// if x is 255, wait is 64-64 = 0, fast.  if x is zero, it's 64 is slow
    delay(wait);  // Pause for a moment
  }
}
