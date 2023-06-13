#define ledV 5
#define ledA 6
#define ledR 7
#define triggerPin 4
#define echoPin 3
#include <math.h>

void setup()
{
  Serial.begin(9600);    
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
  digitalWrite(triggerPin,LOW);


}

void loop()
{


  int Lectura = analogRead(A3) ;

  Lectura = Lectura*60/13;

  Serial.println( Lectura);

  //lectura de 25 = 65 
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  long duracion=pulseIn(echoPin,HIGH);
  long distancia=(duracion/29)/2;
//Serial.print("Distancia: ");
  //Serial.println(distancia);

  // para calcular db del emisor

  int dbEmisor = Lectura +  log10(distancia);

  //Serial.println("db emisor:  ");

  //Serial.println(dbEmisor);



  digitalWrite(ledR,LOW);
  digitalWrite(ledV, HIGH);
  digitalWrite(triggerPin,LOW);
  digitalWrite(triggerPin,HIGH);

  if (Lectura <= 60 ){
    digitalWrite(ledR,LOW);
    digitalWrite(ledV,HIGH);
    digitalWrite(ledA, LOW);
  } if (Lectura >= 70 && distancia < 10){
     digitalWrite(ledR,LOW);
    digitalWrite(ledV,LOW);
    digitalWrite(ledA, HIGH);

  }if(Lectura >= 80 && distancia < 25)  {
    digitalWrite(ledA,LOW);
    digitalWrite(ledV,LOW);
    digitalWrite(ledR, HIGH);
  }
  delay(200) ;
  Serial.flush();
  
 
 
}