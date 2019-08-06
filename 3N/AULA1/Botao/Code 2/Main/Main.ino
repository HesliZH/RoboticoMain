int contador = 0;
int c;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(7, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //Serial.println(digitalRead(2));

  if(digitalRead(2) == HIGH){
    contador = random(1, 6);
    Serial.println(contador);
    for(c=0; c < contador; c++){
        digitalWrite(7, HIGH);
        delay(1000);
        digitalWrite(7, LOW);
        delay(1000);
      }

      Serial.println(contador);
  }
    

}
