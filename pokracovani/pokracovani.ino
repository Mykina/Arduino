int led = 9;
int ledzluta = 6;
int ledzelena = 8;                 
int cekani = 1000;           //delay = 1000ms
int tlacitko = 11;
int cteni = 1;
int cteniOld = 0;
int casRozdil = 0;
unsigned long casMic = 0;
unsigned long casMicOld = 0;
int pocet = 0;
int meter = 0;
int pinmeter = A0;

void setup() 
{
 pinMode(led,OUTPUT);
 pinMode(tlacitko,INPUT);  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.print("pripojeno");g
}

meter = analogRead(pinmeter);
if (meter < 330)
{
  digitalWrite(ledzluta, HIGH)
  digitalWrite(ledzelena, LOW)
  digitalWrite(led, LOW)
  
  

void loop() 
{
 cteniOld = cteni;
 cteni = digitalRead(tlacitko);
 
 if (cteni != cteniOld)
 {
  casMic=millis();
  casRozdil=casMic-casMicOld;
   if(casRozdil>80)
   {
    tisk();
    casMicOld=casMic;                                                 
   }
 }
  ledka(led, cteni);
}

void tisk()
{
   if(pocet>15)
    { 
     Serial.println();
     pocet=0;
    }
     Serial.print(cteni);
     Serial.print("-");
     Serial.print(casRozdil);
     Serial.print(",");
}

void ledka(int led, int stav)
{
  if (stav == HIGH) 
  {
    digitalWrite(led,HIGH);
  }
 else 
 {
  digitalWrite(led,LOW);
 }
}
