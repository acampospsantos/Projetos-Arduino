
// Declaração dos pinos
#define pinoLedAmarelo 8
#define pinoLedAzul 9
#define pinoLedVermelho 10
#define sensorSom 3 

/************************ VARIÁVEIS AUXILIARES ******************************* */
// Essas variáveis definem alguns parâmetros do programa e auxiliam na detecção e contagem das palmas.
int delayfinal = 100;       //Valor representa um tempo em milissegundos, esse tempo é aguardado pelo programa para que se inicie novamente o loop.  
int duracaoPalma = 200;     //Valor representa um tempo em milissegundos, é o tempo que dura o som de uma palma, precisa ser calibrado entre 100 e 250. 
int intervaloPalmas = 500;  //Valor representa um tempo em milissegundos, é o intervalo máximo permitido entre uma sequência de palmas.  
int quantidadePalmas = 0;   //Quantidade de palmas registradas.
long momentoPalma = 0;      //Marcador usado para a detecção das palmas, será utilizado junto com a função millis. 
long esperaPalmas = 0;      //Marcador usado para contagem dos intervalos de tempo, será utilizado junto com a função millis. 

/******************* CONFIGURAÇÕES INICIAIS DO CÓDIGO ************************ */
void setup() {
  pinMode(sensorSom, INPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedAzul, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
}

/********************* EXECUÇÃO DO CÓDIGO QUE SE REPETE ********************** */
void loop() {  
  //Faz a leitura digital do sensor de som, quando este sensor detecta som ele desliga a porta de entrada, mudando seu estado para LOW e quando não detecta mantem em HIGH.
  int leituraSom = digitalRead(sensorSom);
  
  //Ações quando o sensor detectar som, ou seja, entrar em LOW. 
  if (leituraSom == LOW) {    
     //Marca o momento da palma, soma a quantidade de palmas e aguarda um intervalo para não marcar a mesma palma mais de uma vez. 
     if (momentoPalma == 0) {
        momentoPalma = esperaPalmas = millis();
        quantidadePalmas = quantidadePalmas + 1; 
     } else if ((millis() - momentoPalma) >= duracaoPalma) {
        momentoPalma = 0;
     }
  }

  //Verifica se nenhuma palma mais pode ser dada, e em seguida faz o acionamento dos leds conforme o número de palmas já registrado. 
  if (((millis() - esperaPalmas) > intervaloPalmas) && (quantidadePalmas != 0)) {
    
    if(quantidadePalmas == 1){
       digitalWrite(pinoLedAmarelo, !digitalRead(pinoLedAmarelo));          //O sinal de exclamação inverte a condição do led, se estava ligado será desligado e vice versa. 
       }
    if(quantidadePalmas == 2){
       digitalWrite(pinoLedAzul, !digitalRead(pinoLedAzul));      //O sinal de exclamação inverte a condição do led, se estava ligado será desligado e vice versa.  
       }  
    if(quantidadePalmas == 3){
       digitalWrite(pinoLedVermelho, !digitalRead(pinoLedVermelho));      //O sinal de exclamação inverte a condição do led, se estava ligado será desligado e vice versa. 
       }

     delay(delayfinal);     //Tempo de espera para continuar o programa, esse tempo é importante para evitar efeitos de possiveis detecções truncadas de ecos e reverberações no som. 
     quantidadePalmas = 0;  //Retoma a condição inicial da quantidade de palmas. 
   }
    
}