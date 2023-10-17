//Modulo 2  - WALL-E
// Librerías
//****************************************************************
#include <Arduino.h>
#include <WiFi.h>
//****************************************************************
// Definición de etiquetas
//****************************************************************
#define motor1_Adelante 23
#define motor1_Atras 22
#define motor2_Adelante 21
#define motor2_Atras 18
#define servo1 19
#define servo2 5
//****************************************************************
//Variables globales
//****************************************************************
const char* ssid="";
const char* password="";
//****************************************************************
//Configuración
//****************************************************************
void setup()
{
  Serial.begin(115200);
  //Conectar ESP32 A WIFI
  WiFi.begin(ssid, password); 
  while(WiFi.status() !=WL_CONNECTED){
    delay(1000);
    Serial.println("Conectando a Wifi...");
  }
  Serial.println("Conexión Wifi establecida");
  Serial.println("Dirección IP asignadad: ");
  Serial.println(WiFi.localIP());

  /*Motor 1 = Rueda derecha
  Motor 2 = Rueda izquierda
  Servo1 = BrazoRobot derecho
  Servo2 = BrazoRobot izquierdo*/

  //Declaración de Salidas
  pinMode(motor1_Adelante , OUTPUT);
  pinMode(motor1_Atras, OUTPUT); 
  pinMode(motor2_Adelante, OUTPUT); 
  pinMode(motor2_Atras, OUTPUT);
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);

}
//****************************************************************
//Loop Principal
//****************************************************************
void loop()
{}
//****************************************************************