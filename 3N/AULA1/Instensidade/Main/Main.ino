void setup() {
  //pinMode(AO, INPUT);
  pinMode(3, OUTPUT);

}

void loop() {
  int intensidade;

  intensidade = analogRead(A0);

  analogWrite(3, intensidade);
  /*Serial.begin(9600);
  Serial.println(analogRead(A0));*/
  delay(1000);

}
