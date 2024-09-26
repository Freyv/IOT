const int ledGreenCar = 8;
const int ledYellowCar = 10;
const int ledRedCar = 12;

const int ledGreenPed = 6;
const int ledRedPed = 4;

const int sensorEcho = 9;
const int sensorTrig = 7;

unsigned long tempo;

void setup() {
  tempo = millis();
  
  pinMode(ledGreenCar, OUTPUT);
  pinMode(ledYellowCar, OUTPUT);
  pinMode(ledRedCar, OUTPUT);
  
  pinMode(ledGreenPed, OUTPUT);
  pinMode(ledRedPed, OUTPUT);
  
  pinMode(sensorTrig, OUTPUT);
  pinMode(sensorEcho, INPUT);

  digitalWrite(ledGreenCar, HIGH);
  digitalWrite(ledRedPed, HIGH);
}

void loop() {
  long distancia = calculaDistancia();

  if ((millis() - tempo) > 5000 || distancia < 50) {
    
    if (distancia < 50) {
      digitalWrite(ledGreenCar, LOW);
      digitalWrite(ledYellowCar, HIGH);
      delay(2000);
      digitalWrite(ledYellowCar, LOW);
      digitalWrite(ledRedCar, HIGH);
      delay(1000);
      digitalWrite(ledRedPed, LOW);
      digitalWrite(ledGreenPed, HIGH);
      
      delay(15000);

      digitalWrite(ledGreenPed, LOW);
      digitalWrite(ledRedPed, HIGH);
      delay(500);
      
      digitalWrite(ledRedCar, LOW);
      digitalWrite(ledGreenCar, HIGH);
      
      tempo = millis();
    }
  }
  delay(10);
}

long calculaDistancia() {
  digitalWrite(sensorTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTrig, LOW);
  
  long duracao = pulseIn(sensorEcho, HIGH);
  long distancia = duracao * 0.034 / 2;
  
  return distancia;
}
