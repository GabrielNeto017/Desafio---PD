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
#include <EEPROM.h>
#include <Preferences.h>
#include <nvs_flash.h>


String SerialBuffer;

String consulta, users;

Preferences preferences;

int teste;
int num;

void setup() 
{
  // put your setup code here, to run once:
  Serial_Init();
  GPIO_Init();
  preferences.begin("EVENTOS", false);  
           
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.println("Digite: \n 1 - Cadastro do usuário \n 2 - Listagem dos nomes dos usuários cadastrados \n 3 - Listagem dos Eventos \n 4 - Liberar a Porta 1 ");
  Serial.println(" 5 - Liberar a Porta 2 \n 6 - Consultar Eventos Salvos \n 7 - Limpar Eventos Salvos \n ");
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
              List_Event();
              break;
      case 4:
              Room1();
              break;
      case 5:
              Room2();
              break;
      case 6: 
              ReadSavedData();
              break;
      case 7:
              EraseSavedData();

      default:
              break;
    }
  }
}




void SaveUsers(String Response)
{        
        users = preferences.getString("EVENTOS", "NULL");
        users = users+Response;
        preferences.putString("EVENTOS", users);  
}

void ReadSavedData()
{
        Serial.println();  
        consulta = preferences.getString("EVENTOS", "NULL");
        //preferences.end();
        Serial.println(consulta);
        Serial.println();  
}

void EraseSavedData()
{
        Serial.println();    
        Serial.println("Partição NVS sendo limpa... \n");
        nvs_flash_erase(); // apague a partição NVS
        nvs_flash_init(); // inicializa a partição NVS
}
