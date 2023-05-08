int led = 9;                 // nastaví 
int cekani = 1000;           //delay = 1000ms
int tlacitko = 11;
int cteni = 1;
int cteniOld = 0;
int casRozdil = 0;
unsigned long casMic = 0;
unsigned long casMicOld = 0;
int pocet = 0;

void setup() 
{
 pinMode(led,OUTPUT);
 pinMode(tlacitko,INPUT);  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.print("pripojeno");
}

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
  ledka(cteni, led);
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

void ledka(int cteni, int led)	// Názvy mají odpovídat obsahu (LedSvitiAnoNe)
								// vyměnít pořadí parametrů (led je důležitější než jeho stav
								// přejmenovat cteni - neodpovídá obsahu a významu v metode ledka
{
  if (cteni == HIGH) 
  {
    digitalWrite(led,HIGH);
  }
 else 
 {
  digitalWrite(led,LOW);
 }
}