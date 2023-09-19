//Modulo 1  - WALL-E
// Librerías
//****************************************************************
#include <Arduino.h>
//****************************************************************
// Definición de etiquetas
//****************************************************************
#define ledBrazoD 23
#define ledBrazoI 22
#define ledCuello 21
#define Led_OjoD 18
#define Led_OjoI 19

//Variables generales
int btn_AnteriorBD=0;
int btn_AnteriorBI=0;
int btn_AnteriorC=0;
int btn_AnteriorOD=0;
int btn_AnteriorOI=0;

void setup()
{
  Serial.begin(115200);

  //Declaración de Salidas
  pinMode(ledBrazoD, OUTPUT); //Led que indica que el brazo derecho está activo
  pinMode(ledBrazoI, OUTPUT); //Led que indica que el brazo izquierdo está activo
  pinMode(ledCuello, OUTPUT); //Led que indica que el cuello esta activo
  pinMode(Led_OjoD, OUTPUT); //Led que indica que la ojo derecho está activo
  pinMode(Led_OjoI, OUTPUT); //Led que indica que la ojo izquierdo está activo

  //Declaración de Entradas ¡
  pinMode(25, INPUT); //Entrada Digital del brazo derecho
  pinMode(26, INPUT); //Entrada Digital del brazo Izquierdo
  pinMode(27, INPUT); //Entrada Digital del cuello
  pinMode(14, INPUT); //Entrada Digital del ojo derecho
  pinMode(12, INPUT); //Entrada Digital del ojo izquierdo

}

void loop()
{
  volatile int emg_BrazoD=digitalRead(25);   //lectura del cambio de estado de la entrada digiral del brazo derecho
  volatile int emg_BrazoI=digitalRead(26);   //lectura del cambio de estado de la entrada digiral del brazo izquierdo
  volatile int emg_Cuello=digitalRead(27);   //lectura del cambio de estado de la entrada digiral del cuello
  volatile int eog_Izquierda=digitalRead(14); //lectura del cambio de estado de la entrada digiral del ojo izquierda
  volatile int eog_Derecha=digitalRead(12); //lectura del cambio de estado de la entrada digiral del ojo derecho

//Iniciación de las salidas en cero
  digitalWrite(ledBrazoD,LOW);
  digitalWrite(ledBrazoI,LOW);
  digitalWrite(ledCuello,LOW);
  digitalWrite(Led_OjoD,LOW);
  digitalWrite(Led_OjoI,LOW);

//Permite movilizar las ruedas de WALL-E
  if(emg_BrazoD==1 && btn_AnteriorBD==0){
    digitalWrite(ledBrazoD,HIGH);
  }
  btn_AnteriorBD=emg_BrazoD;
  delay(2);
//Permite movilizar los brazos de WALL-E
  if(emg_BrazoI==1 && btn_AnteriorBI==0){
    digitalWrite(ledBrazoI,HIGH);
  }
  btn_AnteriorBI=emg_BrazoI;
  delay(2);
//Permite Movilizar la cabeza deWALL-E
  if(emg_Cuello==1 && btn_AnteriorC==0){
    digitalWrite(ledCuello,HIGH);
  }
  btn_AnteriorC=emg_Cuello;
  delay(2);
//Permite girar a WALL-E hacia la derecha
  if(eog_Derecha==1 && btn_AnteriorOD==0){
    digitalWrite(Led_OjoD,HIGH);
  }
  btn_AnteriorOD=eog_Derecha;
  delay(2);
//Permite girar a WALL-E hacia la izquierda
  if(eog_Izquierda==1 && btn_AnteriorOI==0){
    digitalWrite(Led_OjoI,HIGH);
  }
  btn_AnteriorOI=eog_Izquierda;
  delay(2);
}