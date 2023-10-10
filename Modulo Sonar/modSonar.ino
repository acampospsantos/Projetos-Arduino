//Importação das bibliotecas
#include <Wire.h> // Biblioteca utilizada para fazer a comunicação com o I2C
#include <LiquidCrystal_I2C.h> // Biblioteca utilizada para fazer a comunicação com o display 20x4
#include <Servo.h> //Biblioteca do Servo

//Criação dos objetos
LiquidCrystal_I2C lcd(0x27, 16, 2); // Chamada da funcação LiquidCrystal para ser usada com o I2C
Servo servo1; //Objeto criado da biblioteca do Servo

//Definição dos Pinos
#define pinServo 12
#define pinEcho 8
#define pinTriger 9

//Variáveis
int pos;


void setup() { //Incia o display lcd
  Serial.begin(9600);
  //Configurações iniciais do LCD
  lcd.init(); // Serve para iniciar a comunicação com o display já conectado
  lcd.backlight(); // Serve para ligar a luz do display
  lcd.clear(); // Serve para limpar a tela do display

  //Configurações iniciais do Servo motor
  servo1.attach(pinServo, 500, 2500); //Define que o Servo está conectado a Porta 12
  servo1.write(0);
}

void loop() {
  funcServoMotor();
}

//Função padrão Ultrassônico
long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

//Função do Servo Motor --> Ultrassonico
void funcServoMotor(){
  for (pos = 0; pos <= 180; pos = pos + 1) {
    servo1.write(pos);
    funcSensorUltrassonicoLCD(pos);
    delay(10);
  }
  for(pos = 180; pos >= 0; pos = pos - 1){
    servo1.write(pos);
    funcSensorUltrassonicoLCD(pos);
    delay(10);
  }
}

//Função do Sensor Ultrassônico + Display
void funcSensorUltrassonicoLCD(int pos){
  lcd.clear();
  //Posiciona o cursor na coluna e linha indicada no comando
  lcd.setCursor(2,0); //Setta texto - coluna x linha
  lcd.print("Angulo: "); //imprime o texto que vai ser expresso
  lcd.print(pos); //imprime o texto que vai ser expresso
  lcd.print("");
 
  if (0.01723 * readUltrasonicDistance(pinTriger, pinEcho) <= 25) { //(unidade cm)
    lcd.setCursor(2,1); //Setta texto - coluna x linha
    lcd.print("Detectado!"); //imprime o texto que vai ser expresso
  } else if (0.01723 * readUltrasonicDistance(pinTriger, pinEcho) > 25) {
    lcd.setCursor(2,1); //Setta texto - coluna x linha
    lcd.print(""); //imprime o texto que vai ser expresso
  }
  delay(50);    
}



//Func Display
void funcDisplay() {
  lcd.setCursor(5, 0); // Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Fala,  "); // Comando de saída com a mensagem que deve aparecer na coluna 2 e linha 1.

  lcd.setCursor(5, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("irmao");  // Comando de saida com a mensagem que deve aparecer na coluna 2 e linha 2

  delay(3000);
  lcd.clear();
  delay(500);

  lcd.setCursor(5, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Partiu");  // Comando de saida com a mensagem que deve aparecer na coluna 2 e linha 3

  lcd.setCursor(5, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("gym ;)");  // Comando de saida com a mensagem que deve aparecer na coluna 2 e linha 4

  delay(3000);  // delay de 5 segundos com todas as mensagens na tela
  lcd.clear(); // Limpa o display até o loop ser reiniciado
  delay(500);
}

void funcTeste(){
  int dist;
  dist = (0.01723 * readUltrasonicDistance(pinTriger, pinEcho)); //em cm
  Serial.print("Distância Sensor: ");
  Serial.print(dist);
  Serial.println(" cm");
  delay(1000);
}