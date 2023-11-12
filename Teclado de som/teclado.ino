
//Definição dos pinos
#define pinDo 2
#define pinRe 3
#define pinMi 4
#define pinFa 5
#define pinSol 6
#define pinLa 7
#define pinSi 8
#define pinBuzzer 11


void setup(){
  pinMode(pinDo, OUTPUT);
  pinMode(pinRe, OUTPUT);
  pinMode(pinMi, OUTPUT);
  pinMode(pinFa, OUTPUT);
  pinMode(pinSol, OUTPUT);
  pinMode(pinLa, OUTPUT);
  pinMode(pinSi, OUTPUT);
  pinMode(pinBuzzer, OUTPUT); //Buzzer
}

void loop(){
  teclado();
}


//Função do teclado de som - com as notas musicais + frequências
void teclado(){
  if( digitalRead(pinDo) == HIGH ){
    tone(pinBuzzer, 261.63, 100);
  }
  if( digitalRead(pinRe) == HIGH ){
    tone(pinBuzzer, 293.66, 100);
  }
  if( digitalRead(pinMi) == HIGH ){
    tone(pinBuzzer, 329.63, 100);
  }
  if( digitalRead(pinFa) == HIGH ){
    tone(pinBuzzer, 349.23, 100);
  }
  if( digitalRead(pinSol) == HIGH ){
    tone(pinBuzzer, 391.99, 100);
  }
  if( digitalRead(pinLa) == HIGH ){
    tone(pinBuzzer, 440, 100);
  }
  if( digitalRead(pinSi) == HIGH ){
    tone(pinBuzzer, 493.88, 100);
  }
  delay(10);
}

// TABELA NOTAS MUSICAIS
//Dó - 261.63 Hz
//Ré - 293.66 Hz
//Mi - 329.63 Hz 
//Fá - 349.23 Hz
//Sol - 391.99 Hz
//Lá - 440.00 Hz
//Si - 493.88 Hz