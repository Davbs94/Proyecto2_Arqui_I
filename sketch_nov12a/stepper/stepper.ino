
int currentpos = 0;
 
void setup(){
  /*Sets all pin to output; the microcontroller will send them(the pins) bits, it will not expect to receive any bits from thiese pins.*/
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(4, HIGH); 
  Serial.begin(9600);
}
 
void loop(){

  delay(5000);
  for (int i = 0; i<8; i++){
    
    moveright();
    delay(2000);
  }

}


void moveright(){
    digitalWrite(5, LOW); 
    digitalWrite(4, LOW);
    for (int i = 0; i<400; i++){
      digitalWrite(3, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(3, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(150);
    } 
    digitalWrite(5,HIGH); 
}


void moveleft(){
    digitalWrite(4, LOW); 
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(2, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    delayMicroseconds(1000); 
    digitalWrite(4,HIGH); 
}



