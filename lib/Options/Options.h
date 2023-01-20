/*==================================

Author: Gabriel Luiz B. Neto
Date: 19/01/2023
Project: Desafio


==================================*/
#ifndef _OPTIONS_H
#define _OPTIONS_H


#include <Arduino.h>
#include <PinDefinition.h>

void Reg();
void List_User();                                         
void List_Event();
void Room1();
void Room2();
void SaveUsers(String Response);
void ReadSavedData();
void EraseSavedData();

#endif