
int knob = 0;

int button1pin = 3;
int button2pin = 2;

int AIN1 = 7;
int AIN2 = 8;
int PWMA = 9;
int PWMB = 10;
int BIN1 = 11;
int BIN2 = 12;

boolean button1 = false;
boolean button2 = false;

int x = 0;

void setup() {
    pinMode(button1pin,INPUT_PULLUP); 
    pinMode(button2pin,INPUT_PULLUP); 
    pinMode(AIN1,OUTPUT);
    pinMode(AIN2,OUTPUT);
    pinMode(PWMA,OUTPUT);
    pinMode(BIN1,OUTPUT);
    pinMode(BIN2,OUTPUT);
    pinMode(PWMB,OUTPUT);
    
    analogWrite(PWMA,0);
    analogWrite(PWMB,0);
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,LOW);
    digitalWrite(BIN1,LOW);
    digitalWrite(BIN2,LOW);

    knob = analogRead(A2);
    Serial.begin(9600);

}

void loop() {

  button1 = digitalRead(button1pin);  
  button2 = digitalRead(button2pin);  
  knob = analogRead(A2);
  if(knob < 512){
     x = 0.5*(512 - knob);
  }
  else{
     x = 0.5*(knob - 512);
  }
  Serial.println(x); 
  
  if(!button1 && button2){
      digitalWrite(BIN1,LOW);
      digitalWrite(BIN2,LOW);
      analogWrite(PWMB,0);
      if(knob < 512){
         digitalWrite(AIN2,LOW);
         digitalWrite(AIN1,HIGH);
      }
      else{
         digitalWrite(AIN1,LOW);
         digitalWrite(AIN2,HIGH);
      }
      analogWrite(PWMA,x);
  }  
  if(!button2 && button1){
      digitalWrite(AIN1,LOW);
      digitalWrite(AIN2,LOW);
      analogWrite(PWMA,0);
      if(knob < 512){
         digitalWrite(BIN2,LOW);
         digitalWrite(BIN1,HIGH);
      }
      else{
         digitalWrite(BIN1,LOW);
         digitalWrite(BIN2,HIGH);
      }
      analogWrite(PWMB,x);

  }
  if(button2 && button1){
    
  }
  if(!button2 && !button1){
  }


}
