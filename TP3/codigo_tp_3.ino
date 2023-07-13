#define r 3
#define a 5
#define v 6
#define bot 7
int estado = 0;
int potr = A0;
int pota = A1;
int potv = A2;
int valpotr;
int valpota;
int valpotv;
int ledr;
int leda;
int ledv;

void setup()
{
  pinMode(r, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(potr, INPUT);
  pinMode(pota, INPUT);
  pinMode(potv, INPUT);
  Serial.begin(9600);
}

void loop()
{
  valpotr = analogRead(potr);
  valpota = analogRead(pota);
  valpotv = analogRead(potv);
  estado = digitalRead(bot);
  
  if (estado == HIGH){
    analogWrite(r, 0);
    analogWrite(a, 0);
    analogWrite(v, 0);
    Serial.println( "Tiene 10 s para configurar el color del led....");
    ledr = map(valpotr, 0, 1023, 0, 255);
    leda = map(valpota, 0, 1023, 0, 255);
    ledv = map(valpotv, 0, 1023, 0, 255);    
    delay(10000);
  
    analogWrite(r, ledr);
    analogWrite(a, leda);
    analogWrite(v, ledv);
    
    Serial.println("El led esta usando esta configuracion de colores RGB:   ");
    Serial.print("R: ");
    Serial.print(ledr);
    Serial.print(" ");
    Serial.print("G: ");
    Serial.print(ledv);
    Serial.print(" ");
    Serial.print("B: ");
    Serial.println(leda);
    delay(500);
  }
}