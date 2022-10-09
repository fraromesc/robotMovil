//motor 1 in1 in2 ena
#define IN1 4
#define IN2 5
#define ENA 3

//motor 2 in3 in4 enb
#define IN3 7
#define IN4 8
#define ENB 6

#define stopA 0
#define stopB 0

#define trigDer 52
#define echoDer 50

#define trigIzq 24
#define echoIzq 22

int distanciaUS(int, int);
void avanza(int);
void retrocede(int);
void para();
void giroIzq();
void giroDer();
void pivotIzq();
void pivotDer();
void setup(){
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  Serial.begin(9600); 
  //establecer direcciones
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //inicar los motores quietos
  analogWrite(ENA, 80); 
  analogWrite(ENB, 80);
}
  int kp = 1; 
  int ref; 
  int estado=0; 
  float uk = 0; 
  float e = 0; 
  float eDer = 0;
  float eIzq = 0;  
  float Tm = 0.01; 
  unsigned long t = 0; 
  
void loop() {
  //maquina de estado para la referencia
  if((eDer == 0 || eIzq==0)&& estado < 2 ) estado ++;
  switch (estado){
    case 0: 
      ref=30;
    break; 
    case 1: 
      ref=50; 
      break;  
    default: 
      para(); 
      break; 
  }

  //calculo de errores
  if (millis()- t >= Tm*1000)
  {    
    eDer=distanciaUS(trigDer, echoDer)-ref; 
    eIzq=distanciaUS(trigIzq, echoIzq)-ref; 
    e=(eDer+eIzq)/2; 

    //implementación de controlador P
    //uk = Kp * (ek + Int_err / Ti + Td * (ek - ek1) / Tm);
    uk = kp*e; 

    //modulo de saturación
    if (uk > 255) uk = 255; 
    else if (uk < -255) uk = -255; 

    t = millis(); 
  }
  //actuación
  if (uk > 0) avanza(uk);
  else if (uk < 0) retrocede(-uk); 
  else para(); 
  
  //Serial.print(distanciaUS(trigDer, echoDer)); 
  //Serial.print("\t"); 
  Serial.println(distanciaUS(trigDer, echoDer)); 
 // Serial.print("\t"); 
  //Serial.println(ref); 
  
  
   
}
void avanza(int vel)
{
  int velA = vel;
  int velB = (85/80)*vel; //Manteniendo proporción para rectitud 
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, velA);
  analogWrite(ENB, velB); 
}
void retrocede(int vel)
{
  int velA = vel;
  int velB = (85/80)*vel; //Manteniendo proporción para rectitud 
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  analogWrite(ENA, velA);
  analogWrite(ENB, velB); 
}
void para()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0); 
}
void giroIzq()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  analogWrite(ENB, 85); 
  analogWrite(ENA, 10); 
}
void giroDer()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  analogWrite(ENB, 10); 
  analogWrite(ENA, 80); 
}

void pivotIzq()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 80); 
  analogWrite(ENB, 85);
}

void pivotDer()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 80); 
  analogWrite(ENB, 85); 
}
int distanciaUS(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
