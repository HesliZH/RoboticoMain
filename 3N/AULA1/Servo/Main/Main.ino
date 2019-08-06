#include <Servo.h>
Servo motor;

void setup() {
  motor.attach(7);

}

void loop() {
  motor.write(0);
  delay(250);
  motor.write(50);
  delay(250);

}
