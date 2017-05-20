//botão
int pushButton = 2;
//verificação do botão
int pBstatus;
// teste do botão
int teste = 1;
//controles dos botões
int verifica1 = 0; // para e começa a rotação
int verifica2 = 1; //muda o sentido da rotação
//controle da velocidade
int i = 0;
int espera =5; //config do delay

void setup() {

  //motores//
  //pinos HIGH e LOW
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  //enable - controla a velocidade
  pinMode(9, OUTPUT); 

  //botão//
  pinMode(pushButton, INPUT);
  
}

void loop() {

  verifica();

//SENTIDO 1 
  while (verifica2 == 1 && i <= 255 && verifica1 == 1) {
    
    //motor1
    digitalWrite(7, HIGH); 
    analogWrite(9, i);
    digitalWrite(8, LOW);

    i++;
    delay(espera);
    verifica();
   }

//SENTIDO 2 
  while (verifica2 == 2 && i <= 255 && verifica1 == 1) {
    
    //motor1
    digitalWrite(8, HIGH); 
    analogWrite(9, i);
    digitalWrite(7, LOW);

    i++;
    delay(espera);
    verifica();
   }

// PARAR SENTIDO 1
  while (verifica1 == 0 && i >= 0 && verifica2 == 2) { 
    //motor1
    digitalWrite(7, HIGH); 
    analogWrite(9, i);
    digitalWrite(8, LOW);
    //motor2
    i--;
    delay(espera);
    verifica();
   }

// PARAR SENTIDO 2
  while (verifica1 == 0 && i >= 0 && verifica2 == 1) { 
    //motor1
    digitalWrite(8, HIGH); 
    analogWrite(9, i);
    digitalWrite(7, LOW);
    //motor2
    i--;
    delay(espera);
    verifica();
   }
   

}

void verifica(){
  pBstatus = digitalRead(pushButton);
  if(pBstatus == HIGH && teste == 1) {
   
    if(verifica1 == 1) {
      verifica1 = 0; //para
    } else {
      verifica1 = 1;//prossegue
    }
    
    if (verifica1 == 0) {
      if(verifica2 == 1) {
        verifica2 = 2;
      } else {
       verifica2 = 1; 
      }
    }
    
    teste = 0;
  }
  
  if (pBstatus == LOW) {
   teste = 1; 
  }
}


