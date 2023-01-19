/*==================================

Author: Gabriel Luiz B. Neto
Date: 19/01/2023
Project: Desafio

==================================*/

#include <GPIO.h>

void GPIO_Init()
{
  //initialize the led pins
  pinMode (Sala1 , OUTPUT);
  pinMode (Sala2 , OUTPUT);
  
  //initialize push button
  pinMode (Botao1, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(Botao1), botaoacionado, FALLING);
  attachInterrupt(digitalPinToInterrupt(Botao1), botaoacionado, FALLING);

}

void botaoacionado(){
  
  //Close Room1
  if(digitalRead(Botao1)== LOW)
  {
    digitalWrite(Sala1, LOW);
  }

  //Close Room2
  if(digitalRead(Botao2)== LOW)
  {
    digitalWrite(Sala2, LOW);
  }
}