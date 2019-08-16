void setup() {
    pinMode(2, OUTPUT);
    pinMode(A0, INPUT);
    pinMode(6, INPUT);
    pinMode(A5, INPUT);
    Serial.begin(9600);
}

void loop() {
    float luz = analogRead(A0);
    float gas = analogRead(A5);
    //Serial.println(luz);
    if(luz > 500){
        tone(2, 300, 1000);
      }

    Serial.print("Pino A0: ");
    Serial.println(gas);
}
