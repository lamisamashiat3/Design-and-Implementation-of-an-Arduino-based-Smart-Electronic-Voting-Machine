#include<LiquidCrystal.h> 
LiquidCrystal lcd(2,3,4,5,6,7);
int sw1=13;
int sw2=12;
int sw3=11;
int sw4=10;
int sw5=9;
int a=0;
int b=0;
int c=0;
#define led 8

void setup() {
  // put your setup code here, to run once:
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
  pinMode(sw4,INPUT);
  pinMode(sw5,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
lcd.begin(16,2);
lcd.setCursor(4,0);
lcd.print("ELECTRONIC");
lcd.setCursor(0,1);
lcd.print("VOTING");
lcd.setCursor(8,1);
lcd.print("MACHINE");
delay(1500);
lcd.clear();

digitalWrite(sw1,HIGH);
digitalWrite(sw2,HIGH);
digitalWrite(sw3,HIGH);
digitalWrite(sw4,HIGH);
digitalWrite(sw5,HIGH);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("IIUC");
lcd.setCursor(6,0);
lcd.print("NSU");
lcd.setCursor(12,0);
lcd.print("EDU");
lcd.setCursor(0,1);
lcd.print("SW1");
lcd.setCursor(6,1);
lcd.print("SW2");
lcd.setCursor(12,1);
lcd.print("SW3");

delay(500);

}

void loop() 
{
  
  // put your main code here, to run repeatedly:

if(digitalRead(sw1)==LOW)
{
  a=a+1;
  digitalWrite(led,HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("THANKS FOR");
  lcd.setCursor(5,1);
  lcd.print("VOTING");
  while(digitalRead(sw4)== HIGH);
  digitalWrite(led,LOW);
  admin();
     
}
else if(digitalRead(sw2)== LOW)
{
  b=b+1;
  digitalWrite(led,HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("THANKS FOR");
  lcd.setCursor(5,1);
  lcd.print("VOTING");
  while(digitalRead(sw4)==HIGH);
  digitalWrite(led,LOW);
  admin();
}
else if(digitalRead(sw3)== LOW)
{ 
  c=c+1;
  digitalWrite(led,HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("THANKS FOR");
  lcd.setCursor(5,1);
  lcd.print("VOTING");
  while(digitalRead(sw4)==HIGH);
  digitalWrite(led,LOW);
  admin();
}

 
if(digitalRead(sw5)== LOW)
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("IIUC");
  lcd.setCursor(6,0);
  lcd.print("NSU");
  lcd.setCursor(12,0);
  lcd.print("EDU");
  lcd.setCursor(0,1);
  lcd.println(a);
  lcd.setCursor(6,1);
  lcd.println(b);
  lcd.setCursor(12,1);
  lcd.println(c);
  delay(5000);
  lcd.clear();
  int d=a+b+c;
  if(d)
  { 
  if(a>b && a>c )
  {
   lcd.setCursor(0,0);
   lcd.print("CONGRATS");
   lcd.setCursor(5,1);
   lcd.print("IIUC WINS");
   delay(5000);
   lcd.clear();
  }
  else if(b>a && b>c )
  {
   lcd.setCursor(0,0);
   lcd.print("CONGRATS");
   lcd.setCursor(5,1);
   lcd.print("NSU WINS");
   delay(5000);
   lcd.clear();
  }
  else if(c>b && c>a )
  {
   lcd.setCursor(0,0);
   lcd.print("CONGRATS");
   lcd.setCursor(5,1);
   lcd.print("EDU WINS");
   delay(5000);
   lcd.clear();
  }
  else
  {
  lcd.setCursor(0,0);
  lcd.print("NO RESULT");
  lcd.setCursor(0,1);
  lcd.print("OR TIE");
  
  delay(5000);
  lcd.clear();
 
  }
  }
  else
  {
  lcd.print("NO VOTE");
  delay(5000);
  lcd.clear();
  }  
}
}


int admin()
{
  if(digitalRead(sw4)== LOW)
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("IIUC");
  lcd.setCursor(6,0);
  lcd.print("NSU");
  lcd.setCursor(12,0);
  lcd.print("EDU");
  lcd.setCursor(0,1);
  lcd.print("SW1");
  lcd.setCursor(6,1);
  lcd.print("SW2");
  lcd.setCursor(12,1);
  lcd.print("SW3");

  delay(500);

}
}
