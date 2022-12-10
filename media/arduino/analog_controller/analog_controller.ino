int controller = 0;
int delta = 16;



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



void setup() {
  // put your setup code here, to run once:
  controller = analogRead(A0);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  controller = analogRead(A0);

  if(controller > value1 - delta && controller < value1 + delta){
    delay(1);
    controller = analogRead(A0);
      if(controller > value1 - delta && controller < value1 + delta){
        button = 1;   
      }
   }

  if(controller > value2 - delta && controller < value2 + delta){
    delay(1);
    controller = analogRead(A0);
      if(controller > value2 - delta && controller < value2 + delta){
        button = 2;   
      }
   }

  if(controller > value3 - delta && controller < value3 + delta){
    delay(1);
    controller = analogRead(A0);
      if(controller > value3 - delta && controller < value3 + delta){
        button = 3;   
      }
   }

  if(controller > value4 - delta && controller < value4 + delta){
    delay(1);
    controller = analogRead(A0);
      if(controller > value4 - delta && controller < value4 + delta){
        button = 4;   
      }
   }

  if(controller > value5 - delta && controller < value5 + delta){
    delay(1);
    controller = analogRead(A0);
      if(controller > value5 - delta && controller < value5 + delta){
        button = 5;   
      }
   }

  if(controller > value6 - delta && controller < value6 + delta){
    delay(1);
    controller = analogRead(A0);
      if(controller > value6 - delta && controller < value6 + delta){
        button = 6;   
      }
   }

  if(controller > value7 - delta && controller < value7 + delta){
    delay(1);
    controller = analogRead(A0);
      if(controller > value7 - delta && controller < value7 + delta){
        button = 7;   
      }
   }

  if(controller > value8 - delta && controller < value8 + delta){
    delay(1);
    controller = analogRead(A0);
      if(controller > value8 - delta && controller < value8 + delta){
        button = 8;   
      }
   }


  if(controller < 50){
    delay(1);
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
   }
   if(button == 4){
    Serial.println("back");
   }
   if(button == 5){
    Serial.println("forward");
   }
   if(button == 6){
    Serial.println("right");
   }
   if(button == 7){
    Serial.println("down");
   }
    if(button == 8){
    Serial.println("up");
   }

//   Serial.println(button); 

}
