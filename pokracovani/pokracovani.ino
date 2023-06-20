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
int pinmeter = A1;
int radek=0;

void setup() 
{
 pinMode(led,OUTPUT);
 pinMode(ledzluta,OUTPUT);
 pinMode(ledzelena,OUTPUT);
 pinMode(tlacitko,INPUT);  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.print("pripojeno");
}


void loop() 
{
meter = analogRead(pinmeter);
tisk(meter);
 if (meter < 682)
 {
  digitalWrite(ledzluta, HIGH);
  digitalWrite(ledzelena, LOW);
  digitalWrite(led, LOW);
 } 

 if (meter > 681 && meter < 852)
 {
  digitalWrite(ledzluta, LOW);
  digitalWrite(ledzelena, HIGH);
  digitalWrite(led, LOW);
 }

 if (meter > 852)
 {
  digitalWrite(ledzluta, LOW);
  digitalWrite(ledzelena, LOW);
  digitalWrite(led, HIGH);
 }

 cteniOld = cteni;
 cteni = digitalRead(tlacitko);
 
 if (cteni != cteniOld)
 {
  casMic=millis();
  casRozdil=casMic-casMicOld;
   if(casRozdil>80)
   {
    //tisk();
    casMicOld=casMic;                                                 
   }
 }
  ledka(led, cteni);
}

void tisk(int vyst)
{
  if (radek>20) 
   { Serial.println();
    radek = 0;
  }
    
   Serial.print(vyst);
   Serial.print("-");
   Serial.print(",");
   radek=radek+1;
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
