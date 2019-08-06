#include <Ultrasonic.h>
//#include <Arduino.h>


/*#define TRIGGER_PIN 7;
#define ECHO_PIN 6;*/

Ultrasonic ultrasonic(6, 7);

void setup() {
   Serial.begin(9600);
}

void loop() {
  float cm;
  long tempo = ultrasonic.timing();
  
  cm = ultrasonic.convert(tempo, Ultrasonic::CM);

  Serial.println(cm);

}
