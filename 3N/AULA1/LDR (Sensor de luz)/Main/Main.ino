#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);

float luz;
void setup() {
   //pinMode(A0, INPUT);
   Serial.begin(9600);
}

void loop() {
    luz = analogRead(A0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Luz de: ");
    //lcd.setCursor(2, 1);
    lcd.print(luz); 
    delay(500);
}
