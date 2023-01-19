/*==================================

Author: Gabriel Luiz B. Neto
Date: 19/01/2023
Project: Desafio

==================================*/

#include <Arduino.h>
#include <Options.h>

//Declarations
String nome[50];
String senha[50];
String tipo[50];
String sala[50];
String evento[100];

String verificacao;

int i, l = 0; //array to store data

int nameNo;
bool found = false;

void Reg()
{
    Serial.print("Entre com o seu nome: ");
    // wait for user input through serial
    while(Serial.available() == 0);
    //read the input
    nome[i] = Serial.readStringUntil('\n');
   	Serial.println(nome[i]);
  
   	Serial.print("Defina uma senha: ");
   	// wait for user input through serial
    while(Serial.available() == 0);
    //read the input
    senha[i] = Serial.readStringUntil('\n');
    Serial.println(senha[i]);

    while(tipo[i]!= "Padrao" && tipo[i]!="Admin")
    {
        Serial.print("Que tipo de usuario voce eh? (Padrao ou  Admin): ");
    	// wait for user input through serial
        while(Serial.available() == 0);

       //read the input
        tipo[i] = Serial.readStringUntil('\n');
        Serial.println(tipo[i]);
    }

    Serial.println("");
    i++;
}
    


void List_User()
{
    for(int j =0 ; j<=i ; j++)
    {
        Serial.print("" +nome[j]);
      	Serial.println(" - " +tipo[j]);
      
    }
}


