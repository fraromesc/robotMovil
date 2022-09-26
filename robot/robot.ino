//motor izquierdo in1 in2 ENA
#define IN1 4
#define IN2 5
#define ENA 3

//motor derecho in3 in4 ENB
#define IN3 7
#define IN4 8
#define ENB 6

#define difMot 5 //diferencia entre velocidad motor izquierdo y derecho
void avanzar(int vel)
{  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, vel); 
  analogWrite(ENB, vel+difMot); 
  }
void retroceder(int vel)
{  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, vel); 
  analogWrite(ENB, vel+difMot); 
  }
void rotIzq(int vel)
{  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, vel); 
  analogWrite(ENB, vel+difMot); 
  }
void rotDer(int vel)
{  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, vel); 
  analogWrite(ENB, vel+difMot); 
  }
void girIzq(int vel)
{  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0); 
  analogWrite(ENB, vel+difMot);  
  }
void girDer()
{  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, vel); 
  analogWrite(ENB, 0);  
  }
void parar()
{ analogWrite(ENA, 0); 
  analogWrite(ENB, 0); 
  }

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
  parar()
}
void loop() {

   
}
