#include <Javino.h>
Javino javino;
int led = 13;
int LM35 = A5;//temperatura
int LDR = A0;//luz
double temp = 0.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LM35,INPUT);
  pinMode(LDR,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int luz = analogRead(LDR);
  temp = (analogRead(LM35)*10)*0.00488759;
  char tempSend[30];
  char luzSend[10];
  char resp[21]; 
  dtostrf(temp,3,2,tempSend);
  dtostrf(luz,3,2,luzSend);
  char i = ";";
  strcat(tempSend,i);
  //strcat(resp,i);
  strcat(tempSend,luzSend);
  //javino.sendmsg(tempSend);
  javino.sendmsg(tempSend);
}
