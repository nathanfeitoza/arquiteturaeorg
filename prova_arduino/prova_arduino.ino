int pinLed = 10;
int pinBuzzer = 11;
int pinSensorPIR = 9;
int valorSensorPIR = 0;

void setup()
{
  Serial.begin(9600); //Inicializando o serial monitor
 
  //Definido pinos como de entrada ou de saída
  pinMode(pinSensorPIR,INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer,OUTPUT);
}

void loop()
{
  //Lendo o valor do sensor PIR. Este sensor pode assumir 2 valores
  //1 quando detecta algum movimento e 0 quando não detecta.
  valorSensorPIR = digitalRead(pinSensorPIR);
   
  Serial.print("Valor do Sensor PIR: ");  
  Serial.println(valorSensorPIR);
   
  //Verificando se ocorreu detecção de movimentos
  if (valorSensorPIR == 1) {
    delay(1500);
    ligarAlarme();
  } else {
    desligarAlarme();
  }    
}
void ligarAlarme(){
  Serial.print("\nLiguei\n"); 
  digitalWrite(pinLed, HIGH);
  tone(pinBuzzer, 1500);
  delay(4000); //tempo que o led fica acesso e o buzzer toca
  desligarAlarme();
}

void desligarAlarme(){
    Serial.print("\nDesliguei\n"); 
    digitalWrite(pinLed, LOW);
    noTone(pinBuzzer);
}
