//Modulo 2  - WALL-E
// Librerías
//****************************************************************
#include <Arduino.h>
#include "config.h"

//****************************************************************
// Definición de etiquetas
//****************************************************************
#define motor1_Adelante 23
#define motor1_Atras 22
#define motor2_Adelante 21
#define motor2_Atras 18
#define Servo1 19
#define Servo2 5
//****************************************************************
//Variables globales
//****************************************************************
void handleMessage(AdafruitIO_Data *data);

int wall_e=0;

// Configurar el feed 'Temperatura'
AdafruitIO_Feed *canalWalle= io.feed("Temperatura");
//****************************************************************
//Configuración
//****************************************************************
  void setup()
{
   Serial.begin(115200);
   pinMode(23, OUTPUT);
   pinMode(22, OUTPUT);
   pinMode(21, OUTPUT);
   pinMode(19, OUTPUT);
   pinMode(18, OUTPUT);

  // Esperamos que abra el monitor serial
  while (!Serial)
    ;
  Serial.print("Conexión a Adafruit IO");
  // conectarse a io.adafruit.com
  io.connect(); 

  canalWalle->onMessage(handleMessage);
  // espera una conexión
  while (io.status() < AIO_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  canalWalle->get();

  // Nosotros estamos conectados
  Serial.println();
  Serial.println(io.statusText());
  wall_e=0;
  
}
//****************************************************************
//Loop Principal
//****************************************************************
void loop()
{
  io.run(); // Permite conectarse con el servidor de Adafruit IO
  if(wall_e==0){ ///WALL-E QUIETO
    digitalWrite(motor1_Adelante, LOW);
    digitalWrite(motor1_Atras , LOW);
    digitalWrite(motor2_Adelante , LOW);
    digitalWrite(motor2_Atras , LOW);
  }
  if(wall_e==1){ //WALL-E CAMINA HACIA ADELANTE
    digitalWrite(motor1_Adelante, HIGH);
    digitalWrite(motor1_Atras , LOW);
    digitalWrite(motor2_Adelante , HIGH);
    digitalWrite(motor2_Atras , LOW);
  }
  if(wall_e==2){ //WALL-E CAMINA HACIA ATRÁS 
    digitalWrite(motor1_Adelante, LOW);
    digitalWrite(motor1_Atras , HIGH);
    digitalWrite(motor2_Adelante , LOW);
    digitalWrite(motor2_Atras , HIGH);
  }
  if(wall_e==4){ //GIRA A WALL-E A LA IZQUIERDA
    digitalWrite(motor1_Adelante, HIGH);
    digitalWrite(motor1_Atras , LOW);
    digitalWrite(motor2_Adelante , LOW);
    digitalWrite(motor2_Atras , LOW);
  }
  if(wall_e==5){ //GIRA A WALL-E A LA DERECHA
    digitalWrite(motor1_Adelante, LOW);
    digitalWrite(motor1_Atras , LOW);
    digitalWrite(motor2_Adelante , HIGH);
    digitalWrite(motor2_Atras , LOW);
  }
}

void handleMessage(AdafruitIO_Data *data){
  Serial.print("Recivido <- ");
  Serial.println(data->value());
  if(*data->value()=='1'){
    wall_e=1;
  }
  if(*data->value()=='2'){
    wall_e=2;
  }
  if(*data->value()=='3'){
    wall_e=3;
  }
  if(*data->value()=='4'){
    wall_e=4;
  }
  if(*data->value()=='5'){
    wall_e=5;
  }
  else{
    wall_e=0;
  }
  delay(500);
}