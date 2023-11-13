//Motor 1
#define PWM_A 14
#define A_IN_1 26
#define A_IN_2 27
#define ENCA_1 18
#define ENCB_1 5
#define frec_A 25000
//Motor 2
#define PWM_B  23
#define B_IN_1 32
#define B_IN_2 22
#define ENCA_2 19
#define ENCB_2 21
#define frec_B 5000

#define STNBY 25

void setup() {
  //pinMode(PWM_A, OUTPUT);
  pinMode(A_IN_1, OUTPUT);
  pinMode(A_IN_2, OUTPUT);

  pinMode(STNBY, OUTPUT);
  
  //pinMode(PWM_B, OUTPUT);
  pinMode(B_IN_1, OUTPUT);
  pinMode(B_IN_2, OUTPUT);

  //Activación del microcontrolador
  digitalWrite(STNBY, HIGH);


  ledcSetup(0, frec_A, 8);

  ledcAttachPin(14, 0);

  
}

void loop() {
  avanzar();

  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(0, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(0, dutyCycle);   
    delay(15);
  }




  
  
  /*
  for(int i = 0; i<=90; i++){
    analogWrite(PWM_A, i);
    analogWrite(PWM_B, i);
    delay(i/2);
  }
  detenerse();
  analogWrite(PWM_A, 0);
  analogWrite(PWM_B, 0);
  delay(1000);
  retroceder();
  for(int i = 90; i>=0; i--){
    analogWrite(PWM_A, i);
    analogWrite(PWM_B, i);
    delay(i/2);
  }
  */
}



void avanzar(){
  digitalWrite(A_IN_1, HIGH);
  digitalWrite(A_IN_2, LOW);
  digitalWrite(B_IN_1, HIGH);
  digitalWrite(B_IN_2, LOW);
}

void retroceder(){
  digitalWrite(A_IN_1, LOW);
  digitalWrite(A_IN_2, HIGH);
  digitalWrite(B_IN_1, LOW);
  digitalWrite(B_IN_2, HIGH);
}

void detenerse(){
  digitalWrite(A_IN_1, LOW);
  digitalWrite(A_IN_2, LOW);
  digitalWrite(B_IN_1, LOW);
  digitalWrite(B_IN_2, LOW);
}




