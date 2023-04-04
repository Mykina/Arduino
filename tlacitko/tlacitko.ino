int led = 9;                 // nastaví 
int cekani = 1000;           //delay = 1000ms
int tlacitko = 11;
int cteni = 0;
int cteniOld = 1;


void setup() 
{
 pinMode(led,OUTPUT);
 pinMode(tlacitko,INPUT);  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.print("pripojeno");
}

void loop() 
{
 cteni = digitalRead(tlacitko);
 if (cteni!=cteniOld) {
  Serial.print("Button pressed");

  }

  if (cteni == HIGH) {
    digitalWrite(led,HIGH);
  }

 else {
  digitalWrite(led,LOW);
  }
}
