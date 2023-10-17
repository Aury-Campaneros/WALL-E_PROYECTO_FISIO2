//Modulo 1  - WALL-E
// Librerías
//****************************************************************
#include <Arduino.h>
#include <WiFi.h>
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
int comunicacion=0;
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
  pinMode(led_Motor1_Adelante , OUTPUT);
  pinMode(led_Motor1_Atras, OUTPUT); 
  pinMode(led_Motor2_Adelante, OUTPUT); 
  pinMode(led_Motor2_Atras, OUTPUT);
  pinMode(Led_Servo1, OUTPUT);
  pinMode(Led_Servo2, OUTPUT);
  //Declaración de Entradas ¡
  pinMode(25, INPUT); //Entrada Digital del brazo derecho
  pinMode(26, INPUT); //Entrada Digital del brazo Izquierdo
  pinMode(27, INPUT); //Entrada Digital del cuello
  pinMode(14, INPUT); //Entrada Digital del ojo derecho
  pinMode(12, INPUT); //Entrada Digital del ojo izquierdo

}
//****************************************************************
//Loop Principal
//****************************************************************
void loop()
{
  volatile int emg_BrazoD=digitalRead(25);   //lectura del cambio de estado de la entrada digiral del brazo derecho
  volatile int emg_BrazoI=digitalRead(26);   //lectura del cambio de estado de la entrada digiral del brazo izquierdo
  volatile int emg_Cuello=digitalRead(27);   //lectura del cambio de estado de la entrada digiral del cuello
  volatile int eog_Izquierda=digitalRead(14); //lectura del cambio de estado de la entrada digiral del ojo izquierda
  volatile int eog_Derecha=digitalRead(12); //lectura del cambio de estado de la entrada digiral del ojo derecho

//Iniciación de las salidas en cero
  digitalWrite(led_Motor1_Adelante, LOW);
  digitalWrite(led_Motor1_Atras, LOW);
  digitalWrite(led_Motor2_Adelante, LOW);
  digitalWrite(led_Motor2_Atras, LOW);
  digitalWrite(Led_Servo1, LOW);
  digitalWrite(Led_Servo2, LOW);

//Permite movilizar los motores de WALL-E
  if(emg_BrazoD==1 && emg_BrazoI==0 && emg_Cuello==0 && eog_Izquierda==0 && eog_Derecha==0 ){
    //WALL-E CAMINA HACIA ADELANTE
    comunicacion=1;
    digitalWrite(led_Motor1_Adelante, HIGH);
    digitalWrite(led_Motor1_Atras, LOW);
    digitalWrite(led_Motor2_Adelante, HIGH);
    digitalWrite(led_Motor2_Atras, LOW);
    digitalWrite(Led_Servo1, LOW);
    digitalWrite(Led_Servo2, LOW);
  }
  if(emg_BrazoD==0 && emg_BrazoI==1 && emg_Cuello==0 && eog_Izquierda==0 && eog_Derecha==0 ){
    //WALL-E CAMINA HACIA ATRÁS
    comunicacion=2;
    digitalWrite(led_Motor1_Adelante, LOW);
    digitalWrite(led_Motor1_Atras, HIGH);
    digitalWrite(led_Motor2_Adelante, LOW);
    digitalWrite(led_Motor2_Atras, HIGH);
    digitalWrite(Led_Servo1, LOW);
    digitalWrite(Led_Servo2, LOW);
  }
   if(emg_BrazoD==0 && emg_BrazoI==0 && emg_Cuello==1 && eog_Izquierda==0 && eog_Derecha==0 ){
    //MUEVE LOS BRAZOS DE WALL-E
    comunicacion=2;
    digitalWrite(led_Motor1_Adelante, LOW);
    digitalWrite(led_Motor1_Atras, LOW);
    digitalWrite(led_Motor2_Adelante, LOW);
    digitalWrite(led_Motor2_Atras, LOW);
    digitalWrite(Led_Servo1, HIGH);
    digitalWrite(Led_Servo2, HIGH);
  }

  if(emg_BrazoD==0 && emg_BrazoI==0 && emg_Cuello==0 && eog_Izquierda==1 && eog_Derecha==0 ){
    //GIRA A WALL-E A LA IZQUIERDA
    comunicacion=3;
    digitalWrite(led_Motor1_Adelante, HIGH);
    digitalWrite(led_Motor1_Atras, LOW);
    digitalWrite(led_Motor2_Adelante, LOW);
    digitalWrite(led_Motor2_Atras, LOW);
    digitalWrite(Led_Servo1, LOW);
    digitalWrite(Led_Servo2, LOW);
  }
  if(emg_BrazoD==0 && emg_BrazoI==0 && emg_Cuello==0 && eog_Izquierda==0 && eog_Derecha==1 ){
    //GIRA A WALL-E A LA DERECHA
    comunicacion=4;
    digitalWrite(led_Motor1_Adelante, LOW);
    digitalWrite(led_Motor1_Atras, LOW);
    digitalWrite(led_Motor2_Adelante, HIGH);
    digitalWrite(led_Motor2_Atras, LOW);
    digitalWrite(Led_Servo1, LOW);
    digitalWrite(Led_Servo2, LOW);
  }
}
//****************************************************************