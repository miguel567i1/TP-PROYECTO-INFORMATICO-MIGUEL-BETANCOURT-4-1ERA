#define ledR 2
#define ledA 3
#define ledV 4
int tmp = A0;
int ldr = A1;

void setup()
{
  pinMode(tmp, INPUT);
  pinMode(ldr, INPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledV, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int ldrVal = map(analogRead(ldr), 1023, 713, 0, 255); 
  int tmpVal = analogRead(tmp);
  float voltaje = tmpVal * (5.0 / 1023.0);
  float temperatura = (voltaje - 0.5) * 100;

  Serial.print("El nivel de luz actual es: ");
  Serial.println(ldrVal);
  delay(600);
  Serial.print("La temperatura actual es de: ");
  Serial.print(temperatura);
  Serial.println("ºC");
  delay(600);

  if (ldrVal == 0) {
    if (temperatura >= 90) {
      analogWrite(ledR, 255);
      analogWrite(ledA, 0); 
      analogWrite(ledV, 0);
    }
    else if (temperatura >= 18) {
      analogWrite(ledV, 255);
      analogWrite(ledA, 0);  
      analogWrite(ledR, 0);
    }
    else {
      analogWrite(ledA, 255);
      analogWrite(ledR, 0);  
      analogWrite(ledV, 0);
    }
  }
  else {
    analogWrite(ledA, 0);  
    analogWrite(ledR, 0);
    analogWrite(ledV, 0);
  }
}
