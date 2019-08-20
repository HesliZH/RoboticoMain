#include <LiquidCrystal.h>
#include <Keypad.h>

const byte Filas = 4; 
const byte Colunas = 4; 
char tecla[Filas][Colunas] = {
  {'1','2','3','A'},
  {'4','5','6','+'},
  {'7','8','9','-'},
  {'*','0','=','/'}
};

byte pinFilas[Filas] = {13, 12, 11, 10}; 
byte pinColunas[Colunas] = {9, 8, 7, 6}; 

Keypad keypad = Keypad(makeKeymap(tecla), pinFilas, pinColunas, Filas, Colunas);
LiquidCrystal lcd(1,0,5,4,3,2); 
String LeituraTeclado1,LeituraTeclado2;
byte cuenta=0;
char a;
long numero1,numero2,resultado1;
double numero3,numero4,resultado2;

void setup(){
    lcd.begin(16,2); 
}

void loop(){
  char key = keypad.getKey();
  if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
    
      if(cuenta==0){
        lcd.print(key);
        LeituraTeclado1+=key;
        numero1=LeituraTeclado1.toInt();
      }
      
      else if(cuenta==1){
        lcd.print(key);
        LeituraTeclado2+=key;
        numero2=LeituraTeclado2.toInt();
      }
   
  }

  if(key=='A'){
      LeituraTeclado2="";
      LeituraTeclado1="";
      numero1=0;
      numero2=0;
      numero3=0;
      numero4=0;
      cuenta=0;
      resultado1=0;
      resultado2=0;
      lcd.clear();
  }
  else if(key=='='&&a=='+'){
    cuenta++;
    lcd.setCursor(0,2);
    resultado1=numero1+numero2;
    lcd.print("Resultado=");
    lcd.print(resultado1);
  }

  else if(key=='='&&a=='-'){
    cuenta++;
    lcd.setCursor(0,2);
    resultado1=numero1-numero2;
    lcd.print("Resultado=");
    lcd.print(resultado1);
  }
  else if(key=='='&&a=='*'){
    cuenta++;
    lcd.setCursor(0,2);
    resultado1=numero1*numero2;
    lcd.print("Resultado=");
    lcd.print(resultado1);
  }
  else if(key=='='&&a=='/'){
    cuenta++;
    lcd.setCursor(0,2);
    numero3=numero1;
    numero4=numero2;
    lcd.print("Resultado=");
    resultado2=(numero3/numero4);
    lcd.print(resultado2);
  }

  
  else if((key=='+'||key=='-'||key=='*'||key=='/')&&(cuenta==0)){
    cuenta++;
    a=key;
    lcd.print(a);
  }
}
