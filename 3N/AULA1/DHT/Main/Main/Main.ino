#include "DHT.h"
#include <LiquidCrystal.h>

DHT dht(A0, DHT11);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  dht.begin();
  Serial.begin(9600);
  pinMode(A2, OUTPUT);
  
}

void loop() {
    analogWrite(A2, 950);
    float umidade = dht.readHumidity();
    float temperatura = dht.readTemperature();

    if(isnan(temperatura) || isnan(umidade)){
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Deu ruim");
      }else{
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Humildade: ");
            lcd.print(umidade);

            
            delay(1000);
            /*Serial.print("Umidade :");
            Serial.print(umidade);
            Serial.print(" % e Temperatura:");
            Serial.println(temperatura);*/
        }

}
