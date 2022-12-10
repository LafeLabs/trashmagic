
int x = 0;


void setup() {
  // put your setup code here, to run once:
  x = analogRead(A5);
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
  Serial.begin(9600);
}

void loop() {
  x = analogRead(A5);
  if(x > 750){
    digitalWrite(5,LOW);  
  }
  if(x < 250){
    digitalWrite(5,HIGH);
  }

  Serial.println(x);
}
