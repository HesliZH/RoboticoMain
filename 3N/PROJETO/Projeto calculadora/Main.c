/*Scripted By Hesli Azevedo
    usado como base o código fonte disponível em
        https://www.tinkercad.com/things/1Br1z9Q2fmT-copy-of-calculadora-con-arduino-uno-y-lcd-16x2/editel?tenant=circuits
    código modificado para a disciplina de robótica do curso de sistemas de informação 

*/ 

//Bibliotecas obrigatórias
#include <LiquidCrystal.h>
#include <Keypad.h>

//Constantes com total de colunas e linhas do teclado
const byte Filas = 4; 
const byte Colunas = 4; 

//Matriz com o posicionamento da teclas
char tecla[Filas][Colunas] = {
  {'1','2','3','A'},
  {'4','5','6','+'},
  {'7','8','9','-'},
  {'*','0','=','/'}
};

//Definição da pinagem do teclado ligado ao arduino(Consulte o circuito)
byte pinFilas[Filas] = {13, 12, 11, 10}; 
byte pinColunas[Colunas] = {9, 8, 7, 6}; 

//Cria um objeto da classe Keypad presente na biblioteca adicionada acima
Keypad keypad = Keypad(makeKeymap(tecla), pinFilas, pinColunas, Filas, Colunas);
//Cria um objeto do tipo lcd
LiquidCrystal lcd(1,0,5,4,3,2);
//Cria váriaveis onde serão momentaneamente armazenados os valores 
String LeituraTeclado1,LeituraTeclado2;
//Conta? Variável de controle para o calculo
byte Conta=0;
//Variável de exibição do resultado
char a;
//Dados inseridos no teclado
long numero1,numero2,resultado1;
double numero3,numero4,resultado2;

void setup(){
    lcd.begin(16,2); 
}

void loop(){
    /*Inicia as funções de calculo
        variavel key recebe o valor digitado no teclado
    */
    char key = keypad.getKey();
    if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
        //Mostra na tela os valores a serem calculados
        if(Conta==0){
            lcd.print(key);
            LeituraTeclado1+=key;
            numero1=LeituraTeclado1.toInt();
        }
        
        else if(Conta==1){
            lcd.print(key);
            LeituraTeclado2+=key;
            numero2=LeituraTeclado2.toInt();
        }
    
    }

    //Reinicia a tela
    if(key=='A'){
        LeituraTeclado2="";
        LeituraTeclado1="";
        numero1=0;
        numero2=0;
        numero3=0;
        numero4=0;
        Conta=0;
        resultado1=0;
        resultado2=0;
        lcd.clear();
    }
    else if(key=='='&&a=='+'){ //Formato de algoritmo para soma
        Conta++;
        lcd.setCursor(0,2);
        resultado1=numero1+numero2;
        lcd.print("Resultado=");
        lcd.print(resultado1);
    }

    else if(key=='='&&a=='-'){ //Formato de algoritmo para subtração
        Conta++;
        lcd.setCursor(0,2);
        resultado1=numero1-numero2;
        lcd.print("Resultado=");
        lcd.print(resultado1);
    }
    else if(key=='='&&a=='*'){ //Formato de algoritmo para multiplicação
        Conta++;
        lcd.setCursor(0,2);
        resultado1=numero1*numero2;
        lcd.print("Resultado=");
        lcd.print(resultado1);
    }
    else if(key=='='&&a=='/'){ //Formato de algoritmo para divisão
        Conta++;
        lcd.setCursor(0,2);
        numero3=numero1;
        numero4=numero2;
        lcd.print("Resultado=");
        resultado2=(numero3/numero4);
        lcd.print(resultado2);
    }
    else if((key=='+'||key=='-'||key=='*'||key=='/')&&(Conta==0)){
        Conta++;
        a=key;
        lcd.print(a);
    }
}
