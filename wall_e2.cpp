//Modulo 2  - WALL-E
// Librerías
//****************************************************************
#include <Arduino.h>
#include "config.h"

//****************************************************************
// Definición de etiquetas
//****************************************************************
#define led_Motor1_Adelante 23
#define led_Motor1_Atras 22
#define led_Motor2_Adelante 21
#define led_Motor2_Atras 18
#define Led_Servo1 19
#define Led_Servo2 5
//****************************************************************
//Variables globales
//****************************************************************
void handleMessage(AdafruitIO_Data *data);
int temp=0;
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
  
}
//****************************************************************
//Loop Principal
//****************************************************************
void loop()
{
  io.run(); // Permite conectarse con el servidor de Adafruit IO
   
}

void handleMessage(AdafruitIO_Data *data){
  Serial.print("Recivido <- ");
  Serial.println(data->value());
}
/*void handleMessage(){
  Serial.println("received<-");
  wall_e= data ->toPinLevel();
  Serial.println(data ->toPinLevel());
  if(wall_e==1){
    digitalWrite(23, HIGH);
    digitalWrite(22, LOW);
    digitalWrite(21, LOW);
    digitalWrite(19, LOW);
    digitalWrite(18, LOW);
  }
  if(wall_e==2){
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
    digitalWrite(21, LOW);
    digitalWrite(19, LOW);
    digitalWrite(18, LOW);
  }
  if(wall_e==3){
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
    digitalWrite(21, HIGH);
    digitalWrite(19, LOW);
    digitalWrite(18, LOW);
  }
  if(wall_e==4){
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
    digitalWrite(21, LOW);
    digitalWrite(19, HIGH);
    digitalWrite(18, LOW);
  }
  if(wall_e==5){
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
    digitalWrite(21, LOW);
    digitalWrite(19, LOW);
    digitalWrite(18, HIGH);
  }
  else{
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
    digitalWrite(21, LOW);
    digitalWrite(19, LOW);
    digitalWrite(18, LOW);
  }
}*/