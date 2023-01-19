/*==================================

Author: Gabriel Luiz B. Neto
Date: 19/01/2023
Project: Desafio


==================================*/

#include <Arduino.h>
#include <PinDefinition.h>
#include <GPIO.h>
#include <Serial.h>
#include <Options.h>

String SerialBuffer;

void setup() 
{
  // put your setup code here, to run once:
  Serial_Init();
  GPIO_Init();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.println("Digite: \n 1 - Cadastro do usuário \n 2 - Listagem dos nomes dos usuários cadastrados \n 3 - Listagem dos Eventos \n 4 - Liberar a Porta 1 \n 5 - Liberar a Porta 2 \n");
  while(Serial.available() == 0);
  SerialBuffer = Serial.readStringUntil('\n');
  
  if(SerialBuffer.length()<=1)
  {
    switch(SerialBuffer.toInt())
    {
      case 1:
              Reg();
              break;
      case 2:
              List_User();
              break;
      case 3:
              //List_Event();
              break;
      case 4:
              //Room1();
              break;
      case 5:
              //Room2();
              break;
      default:
              break;
    }
  }
}


