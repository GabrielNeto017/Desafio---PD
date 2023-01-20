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


void List_Event()
{
    Serial.print("Nome do Usuario: ");
  	// wait for user input through serial
  	while(Serial.available() == 0);

  	//read the input
 	verificacao = Serial.readStringUntil('\n');
    Serial.println(verificacao);
    
    for(int k =0 ; k<i ; k++)
    {

      	if (verificacao == nome[k])
        {
        	  found = true;
         	  nameNo = k;
        }
    }

    if(found!=true)
    {
        Serial.println("USUARIO NAO ENCONTRADO NO NOSSO BANCO DE DADOS \n");
    }

  	else if(tipo[nameNo]=="Padrao" && found==true)
    {
      	Serial.println("ESSE USUARIO NAO EH UM ADMIN");
      	Serial.println("");
    }
    
    else if(tipo[nameNo]=="Admin" && found==true)
    {
     	Serial.print("Entre com a senha: ");
  		// wait for user input through serial
  		while(Serial.available() == 0);

  		//read the input
 	    verificacao = Serial.readStringUntil('\n');
     	Serial.println(verificacao);
      	
      
        if(senha[nameNo]!=verificacao)
        {
            Serial.println("SENHA INCORRETA \n");
        }
      
        else if(senha[nameNo]==verificacao)
        {
            Serial.println();
            Serial.print("LISTAGEM DE EVENTOS\n");
            Serial.println();
            for(int j =0 ; j<=l ; j++)
            {
               
                Serial.println(evento[j]);

        	}
             Serial.println();
        } 
    }  
    found = false;
}


void Room1()
{
    Serial.print("Nome do Usuario: ");
    // wait for user input through serial
    while(Serial.available() == 0);

    //read the input
    verificacao = Serial.readStringUntil('\n');
    Serial.print(verificacao);
    Serial.println(" ");
    
    for(int k =0 ; k<i ; k++)
    {
        if (verificacao == nome[k])
        {
            found = true;
            nameNo = k;
        }
    }
    
    if(found)
    {
        Serial.print("Entre com a senha: ");
        // wait for user input through serial
        while(Serial.available() == 0);

        //read the input
        verificacao = Serial.readStringUntil('\n');
        Serial.print(verificacao);
        Serial.println("");
        
        if(senha[nameNo]!=verificacao)
        {
            Serial.println("SENHA INCORRETA");
            Serial.println("");
        }
      
        else if(senha[nameNo]==verificacao)
        {
            sala[nameNo] = "Sala1";
            Serial.println("Abrir Porta 1? 1 - SIM  ou 2 - NAO");
            // wait for user input through serial
            while(Serial.available() == 0);

            //read the input
            verificacao = Serial.readStringUntil('\n');
            Serial.println(verificacao);
            
            if(verificacao=="1")
            {
                sala[nameNo] = "Abriu a porta1";
                evento[l].concat(l);
                evento[l].concat(" - "); 
                evento[l].concat(nome[nameNo]);
                evento[l].concat(",");
                evento[l].concat(tipo[nameNo]);
                evento[l].concat(",");
                evento[l].concat(sala[nameNo]);
                l++; 
                digitalWrite(Sala1 , HIGH);
                Serial.println("Porta1 Liberada");
                delay(5000);
                digitalWrite(Sala1 , LOW);
                
            }
        }
    }
}

void Room2()
{
    Serial.print("Nome do Usuario: ");
    // wait for user input through serial
    while(Serial.available() == 0);

    //read the input
    verificacao = Serial.readStringUntil('\n');
    Serial.print(verificacao);
    Serial.println(" ");
    
    for(int k =0 ; k<i ; k++)
    {
        if (verificacao == nome[k])
        {
            found = true;
            nameNo = k;
        }
    }
    
    if(found)
    {
        Serial.print("Entre com a senha: ");
        // wait for user input through serial
        while(Serial.available() == 0);

        //read the input
        verificacao = Serial.readStringUntil('\n');
        Serial.print(verificacao);
        Serial.println("");
        
        if(senha[nameNo]!=verificacao)
        {
            Serial.println("SENHA INCORRETA");
            Serial.println("");
        }
      
        else if(senha[nameNo]==verificacao)
        {
        
            sala[nameNo] = "Sala1";
            Serial.println("Abrir Porta 2? 1 - SIM  ou 2 - NAO");
            // wait for user input through serial
            while(Serial.available() == 0);

            //read the input
            verificacao = Serial.readStringUntil('\n');
            Serial.println(verificacao);
            
            if(verificacao=="1")
            {
                sala[nameNo] = "Abriu a porta2";
                evento[l].concat(l);
                evento[l].concat(" - "); 
                evento[l].concat(nome[nameNo]);
                evento[l].concat(",");
                evento[l].concat(tipo[nameNo]);
                evento[l].concat(",");
                evento[l].concat(sala[nameNo]);
                l++;
                digitalWrite(Sala2 , HIGH);
                Serial.println("Porta2 Liberada");
                delay(5000);
                digitalWrite(Sala2 , LOW);
            }
        }
    }
}

    