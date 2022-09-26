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



void setup(){
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  Serial.begin(9600); 
  //establecer direcciones
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  //inicar los motores quietos
  analogWrite(ENA, stopA); 
  analogWrite(ENB, stopB);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ENA,80); 
  analogWrite(ENB, 85); 

  delay(1000); 
  //giro izquierda
  analogWrite(ENA, 10); 
  delay(1000); 

  analogWrite(ENA, 80); 
  delay(1000); 
  //giro derecha
  analogWrite(ENB, 10); 
  delay(1000); 

  analogWrite(ENB, 85); 
  delay(500);

  analogWrite(ENA, stopA); 
  analogWrite(ENB, stopB);
  delay(1000); 

  


}
