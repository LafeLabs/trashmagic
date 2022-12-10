int controller = 0;
int delta = 16;

int AIN1 = 7;
int AIN2 = 8;
int PWMA = 9;

int dirPin1 = 2;
int stepPin1 = 3;
int enPin1 = 4;

int dirPin2 = 5;
int stepPin2 = 6;
int enPin2 = 10;


//there is a ladder of 9 10k resistors from 5v to ground, and the intermediate nodes all connect to buttons which connect to an analog pin which has a 1 megaohm pull down resistor
int value1 = 114;
int value2 = 2*114;
int value3 = 3*114;
int value4 = 4*114;
int value5 = 5*114;
int value6 = 6*114;
int value7 = 7*114;
int value8 = 8*114;

int button = 0;  //0 means no press, 1 is start, 2 is stop, 3 is left, 4 is back 5 is forward, 6 is right, 7 is down 8 is up


int delayus = 1000;//delayMicroseconds(delayus);

int z = 0;
int zdelay = 0;// microseconds 1000 ms / 512 steps = 2 ms/step

void setup() {
  // put your setup code here, to run once:
  controller = analogRead(A0);

    pinMode(AIN1,OUTPUT);
    pinMode(AIN2,OUTPUT);
    pinMode(PWMA,OUTPUT);
    
    analogWrite(PWMA,0);
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,LOW);


    pinMode(dirPin1,OUTPUT);
    pinMode(stepPin1,OUTPUT);
    pinMode(enPin1,OUTPUT);
    pinMode(dirPin2,OUTPUT);
    pinMode(stepPin2,OUTPUT);
    pinMode(enPin2,OUTPUT);

    digitalWrite(dirPin1,LOW);
    digitalWrite(stepPin1,LOW);
    digitalWrite(enPin1,HIGH);
    digitalWrite(dirPin2,LOW);
    digitalWrite(stepPin2,LOW);
    digitalWrite(enPin2,HIGH);

  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  controller = analogRead(A0);

  if(controller > value1 - delta && controller < value1 + delta){
    delayMicroseconds(10);
    controller = analogRead(A0);
      if(controller > value1 - delta && controller < value1 + delta){
        button = 1;   
      }
   }

  if(controller > value2 - delta && controller < value2 + delta){
    delayMicroseconds(10);
    controller = analogRead(A0);
      if(controller > value2 - delta && controller < value2 + delta){
        button = 2;   
      }
   }

  if(controller > value3 - delta && controller < value3 + delta){
    delayMicroseconds(10);
    controller = analogRead(A0);
      if(controller > value3 - delta && controller < value3 + delta){
        button = 3;   
      }
   }

  if(controller > value4 - delta && controller < value4 + delta){
    delayMicroseconds(10);
    controller = analogRead(A0);
      if(controller > value4 - delta && controller < value4 + delta){
        button = 4;   
      }
   }

  if(controller > value5 - delta && controller < value5 + delta){
   delayMicroseconds(10);
   controller = analogRead(A0);
      if(controller > value5 - delta && controller < value5 + delta){
        button = 5;   
      }
   }

  if(controller > value6 - delta && controller < value6 + delta){
    delayMicroseconds(10);
    controller = analogRead(A0);
      if(controller > value6 - delta && controller < value6 + delta){
        button = 6;   
      }
   }

  if(controller > value7 - delta && controller < value7 + delta){
    delayMicroseconds(10);
    controller = analogRead(A0);
      if(controller > value7 - delta && controller < value7 + delta){
        button = 7;   
      }
   }

  if(controller > value8 - delta && controller < value8 + delta){
    delayMicroseconds(10);
    controller = analogRead(A0);
      if(controller > value8 - delta && controller < value8 + delta){
        button = 8;   
      }
   }


  if(controller < 50){
    delayMicroseconds(10);
    controller = analogRead(A0);
      if(controller < 50){
        button = 0;   
      }
   }

   if(button == 1){
    Serial.println("start");  
   }
   if(button == 2){
    Serial.println("stop");
   }
   if(button == 3){
    Serial.println("left");
    moveLeft(1);
   }
   if(button == 4){
    Serial.println("back");
    moveAway(1);
   }
   if(button == 5){
      Serial.println("forward");
      moveTowards(1);
   }
   if(button == 6){
      Serial.println("right");
      moveRight(1);
   }
   if(button == 7){
      z = z - 1;
      if(z < -255){
        z = -255;
      }
      delayMicroseconds(zdelay);
//      Serial.println("down");
   }
    if(button == 8){
      //up
      z = z + 1;
      if(z > 255){
        z = 255;
      }
      delayMicroseconds(zdelay);
//      Serial.println("up");
   }

//   Serial.println(button); 


   if(z >= 0){
      digitalWrite(AIN2,LOW);
      digitalWrite(AIN1,HIGH);      
   }
   else{
      digitalWrite(AIN1,LOW);      
      digitalWrite(AIN2,HIGH);
   }      
   analogWrite(PWMA,abs(z));
   Serial.println(z);

}



void moveLeft(int nSteps){
     digitalWrite(dirPin1,LOW);
     digitalWrite(enPin1,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 

     }          
     digitalWrite(enPin1,HIGH);   
     digitalWrite(enPin2,HIGH);   
}

void moveRight(int nSteps){
     digitalWrite(dirPin1,HIGH);
     digitalWrite(enPin1,LOW);
    
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 

     }          
     digitalWrite(enPin1,HIGH);   

}


void moveAway(int nSteps){
     digitalWrite(dirPin2,LOW);
     digitalWrite(enPin2,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin2,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin2,HIGH);   
}

void moveTowards(int nSteps){
     digitalWrite(dirPin2,HIGH);
     digitalWrite(enPin2,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin2,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin2,HIGH);   
}
