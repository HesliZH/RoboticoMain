void setup() {
  pinMode(1, INPUT);
  Serial.begin(9600);

}

void loop() {
  
  Serial.println(digitalRead(1));
}
