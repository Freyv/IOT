//Biblioteca ÇCD
#include <LiquidCrystal.h>
//Criar variavel LCD
LiquidCrystal lcd (2,3,4,9,10,11,12);
int letLcd = 13;

void setup()
{
  pinMode(letLcd, OUTPUT);//defininco letLcd saida
  digitalWrite(letLcd, HIGH);//ligar os leds do LCD
  lcd.begin(16,2);//Informar que s lcds tem 16 colunas e 2 linhas
lcd.clear(); //iniciar o lcd limpo
  
}

void loop()
{
  lcd.setCursor(0,0);//iniciar a escrita na linha 0 coluna 0
  lcd.print("Bom dia");
  lcd.setCursor(0,1);//iniciar a escrita na linha 0 coluna 0
  lcd.print("OLa mundo Bom dia");
}