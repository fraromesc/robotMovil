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
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //inicar los motores quietos
  analogWrite(ENA, 80); 
  analogWrite(ENB, 80);
}
void loop() {
  // put your main code here, to run repeatedly:
  int velA = 80;
  int velB = 85; 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, velA);
  analogWrite(ENB, velB); 

  delay(1000); 
  
  velA = 0; 
  velB = 0;

  analogWrite(ENA, velA);
  analogWrite(ENB, velB); 

  delay(1000);

  velA = 80; 
  velB = 85; 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, velA);
  analogWrite(ENB, velB); 

  delay(1000);

  velA = 0; 
  velB = 0;

  analogWrite(ENA, velA);
  analogWrite(ENB, velB); 

  delay(1000);
   
}
