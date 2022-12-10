int outpin = 12;
int x0 = 0;//value of analog pin A0
int vmin = 250;//upper voltage trigger to toggle digital LOW
int vmax = 750;//lower voltage trigger to toggle digital HIGH

void setup() {

    pinMode(outpin,OUTPUT);
    digitalWrite(outpin,LOW);
    Serial.begin(115200);

}

void loop() {
  x0 = analogRead(A0);
  if(x0 > vmax){
    digitalWrite(outpin,LOW);  
  }
  if(x0 < vmin){
    digitalWrite(outpin,HIGH);
  }
  Serial.println(x0);

}
