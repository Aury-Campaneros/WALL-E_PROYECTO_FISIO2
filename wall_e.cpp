//Modulo 1  - WALL-E
// Librerías
//****************************************************************
#include <Arduino.h>
#include "config.h"

//****************************************************************
// Definición de etiquetas
//****************************************************************
/*#define led_Motor1_Adelante 23
#define led_Motor1_Atras 22
#define led_Motor2_Adelante 21
#define led_Motor2_Atras 18
#define Led_Servo1 19
#define Led_Servo2 5*/
//****************************************************************
//Variables globales
//****************************************************************
int temp=0;
// Configurar el feed 'Temperatura'
AdafruitIO_Feed *tempCanal = io.feed("Temperatura");
//****************************************************************
//Configuración
//****************************************************************
  void setup()
{
   Serial.begin(115200);
  // Esperamos que abra el monitor serial
  while (!Serial)
    ;
  Serial.print("Conexión a Adafruit IO");
  // conectarse a io.adafruit.com
  io.connect();
  // espera una conexión
  while (io.status() < AIO_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  // Nosotros estamos conectados
  Serial.println();
  Serial.println(io.statusText());

  /*Motor 1 = Rueda derecha
  Motor 2 = Rueda izquierda
  Servo1 = BrazoRobot derecho
  Servo2 = BrazoRobot izquierdo*/

  //Declaración de Salidas
  /*pinMode(led_Motor1_Adelante , OUTPUT);
  pinMode(led_Motor1_Atras, OUTPUT); 
  pinMode(led_Motor2_Adelante, OUTPUT); 
  pinMode(led_Motor2_Atras, OUTPUT);
  pinMode(Led_Servo1, OUTPUT);
  pinMode(Led_Servo2, OUTPUT);*/
  //Declaración de Entradas ¡
  pinMode(23, INPUT); //Entrada Digital del brazo derecho
  pinMode(22, INPUT); //Entrada Digital del brazo Izquierdo
  pinMode(21, INPUT); //Entrada Digital del cuello
  pinMode(19, INPUT); //Entrada Digital del ojo derecho
  pinMode(18, INPUT); //Entrada Digital del ojo izquierdo
}
//****************************************************************
//Loop Principal
//****************************************************************
void loop()
{
  io.run(); // Permite conectarse con el servidor de Adafruit IO
  volatile int emg_BrazoD=digitalRead(23);   //lectura del cambio de estado de la entrada digiral del brazo derecho
  volatile int emg_BrazoI=digitalRead(22);   //lectura del cambio de estado de la entrada digiral del brazo izquierdo
  volatile int emg_Cuello=digitalRead(21);   //lectura del cambio de estado de la entrada digiral del cuello
  volatile int eog_Izquierda=digitalRead(19); //lectura del cambio de estado de la entrada digiral del ojo izquierda
  volatile int eog_Derecha=digitalRead(18); //lectura del cambio de estado de la entrada digiral del ojo derecho

//Iniciación de las salidas en cero
  /*digitalWrite(led_Motor1_Adelante, LOW);
  digitalWrite(led_Motor1_Atras, LOW);
  digitalWrite(led_Motor2_Adelante, LOW);
  digitalWrite(led_Motor2_Atras, LOW);
  digitalWrite(Led_Servo1, LOW);
  digitalWrite(Led_Servo2, LOW);*/

//Permite movilizar los motores de WALL-E
  if(emg_BrazoD==1 && emg_BrazoI==0 && emg_Cuello==0 && eog_Izquierda==0 && eog_Derecha==0 ){
    //WALL-E CAMINA HACIA ADELANTE
    temp=1;
    Serial.print("Enviando -> ");
    Serial.println(temp);
    tempCanal->save(temp);
    Serial.printf(" señal %d \n", temp);
    /*digitalWrite(led_Motor1_Adelante, HIGH);
    digitalWrite(led_Motor1_Atras, LOW);
    digitalWrite(led_Motor2_Adelante, HIGH);
    digitalWrite(led_Motor2_Atras, LOW);
    digitalWrite(Led_Servo1, LOW);
    digitalWrite(Led_Servo2, LOW);*/
  }
  if(emg_BrazoD==0 && emg_BrazoI==1 && emg_Cuello==0 && eog_Izquierda==0 && eog_Derecha==0 ){
    //WALL-E CAMINA HACIA ATRÁS
    temp=2;
    Serial.print("Enviando -> ");
    Serial.println(temp);
    tempCanal->save(temp);
    Serial.printf(" señal %f \n", temp);
    /*digitalWrite(led_Motor1_Adelante, LOW);
    digitalWrite(led_Motor1_Atras, HIGH);
    digitalWrite(led_Motor2_Adelante, LOW);
    digitalWrite(led_Motor2_Atras, HIGH);
    digitalWrite(Led_Servo1, LOW);
    digitalWrite(Led_Servo2, LOW);*/
  }
   if(emg_BrazoD==0 && emg_BrazoI==0 && emg_Cuello==1 && eog_Izquierda==0 && eog_Derecha==0 ){
    //MUEVE LOS BRAZOS DE WALL-E
    temp=3;
    Serial.print("Enviando -> ");
    Serial.println(temp);
    tempCanal->save(temp);
    Serial.printf(" señal %f \n", temp);
    /*digitalWrite(led_Motor1_Adelante, LOW);
    digitalWrite(led_Motor1_Atras, LOW);
    digitalWrite(led_Motor2_Adelante, LOW);
    digitalWrite(led_Motor2_Atras, LOW);
    digitalWrite(Led_Servo1, HIGH);
    digitalWrite(Led_Servo2, HIGH);*/
  }

  if(emg_BrazoD==0 && emg_BrazoI==0 && emg_Cuello==0 && eog_Izquierda==1 && eog_Derecha==0 ){
    //GIRA A WALL-E A LA IZQUIERDA
    temp=4;
    Serial.print("Enviando -> ");
    Serial.println(temp);
    tempCanal->save(temp);
    Serial.printf(" señal %f \n", temp);
    /*digitalWrite(led_Motor1_Adelante, HIGH);
    digitalWrite(led_Motor1_Atras, LOW);
    digitalWrite(led_Motor2_Adelante, LOW);
    digitalWrite(led_Motor2_Atras, LOW);
    digitalWrite(Led_Servo1, LOW);
    digitalWrite(Led_Servo2, LOW);*/
  }
  if(emg_BrazoD==0 && emg_BrazoI==0 && emg_Cuello==0 && eog_Izquierda==0 && eog_Derecha==1 ){
    //GIRA A WALL-E A LA DERECHA
    temp=5;
    Serial.print("Enviando -> ");
    Serial.println(temp);
    tempCanal->save(temp);
    Serial.printf(" señal %f \n", temp);
    /*digitalWrite(led_Motor1_Adelante, LOW);
    digitalWrite(led_Motor1_Atras, LOW);
    digitalWrite(led_Motor2_Adelante, HIGH);
    digitalWrite(led_Motor2_Atras, LOW);
    digitalWrite(Led_Servo1, LOW);
    digitalWrite(Led_Servo2, LOW);*/
  }
  else{
    temp=0;
  }
  /***************************** ESP32 WIFI  ************************************/
    // guardar el recuento en el feed 'Temperatura' de Adafruit IO
     // guardar el recuento en el feed 'Temperatura' de Adafruit IO
    
}