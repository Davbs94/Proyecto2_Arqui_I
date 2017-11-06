int a = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print( "Hola" + String(a) + "\n");
  delay(1000);
  if (Serial.available()){
    Serial.print(Serial.read()+ "\n");
  }
    
  a++;
}
