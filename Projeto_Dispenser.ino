#include <Ultrasonic.h>
// Define os pinos e cada componente ligado a eles
const int trigPin = 12;
const int echoPin = 8;
const int motor = 2;
const int LED1 = 4;
const int LED2 = 5;
Ultrasonic ultrasonic(trigPin, echoPin);
// Define as variáveis de cálculo da distância
long duration;
float distance;

void setup() {

  pinMode(trigPin, OUTPUT); // Determina o TrigPin como Saída
  pinMode(LED1, OUTPUT);    // Determina o LED1 como Saída
  pinMode(LED2, OUTPUT);    // Determina o LED2 como Saída
  pinMode(echoPin, INPUT);  // Determina o echoPin como Entrada
  pinMode(motor, OUTPUT);   // Determina o Motor como Saída
  Serial.begin(9600);

}

void loop() {

  // Acende LED1 e LED2
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);

  // Zera o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Seta o trigPin em estado HIGH por 10 micro segundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o echoPin, retorna o tempo de viagem da onda em microsegundos
  duration = pulseIn(echoPin, HIGH);
  Serial.println(duration);
 
  // Cálculo da distância
  distance = duration * 0.034/2;
  Serial.println(distance);
  // Calculo da média da distância
  int SomaMedidas = 0;
  int i, Media;
  for (i = 0; i < 5; i++) {
    SomaMedidas = SomaMedidas + distance;
    Media = (SomaMedidas / 5);
  }

  // Distância final é a média obtida
  distance = Media;

  if (distance < 10) {
    // Espera 1 segundo
    delay(1000);

    // Liga o Motor e desliga os LEDs
    digitalWrite(motor, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);

    // Espera meio segundo
    delay(500);

    // Liga ambos LEDs
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);

    // Espera por mais meio segundo
    delay(100);

    // Desliga o Motor
    digitalWrite(motor, LOW);

    //Espera por mais um segundo e meio
    delay(1500);

    // Apaga LEDs
    digitalWrite(LED1, LOW); 
    digitalWrite(LED2, LOW);
  }

}
