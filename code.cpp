#include <LiquidCrystal.h> 
LiquidCrystal lcd(3,4,8,9,10,11); 
const int triggerPin1 = 12;
const int echoPin1 = 13;
const int triggerPin2 =7;
const int echoPin2 = 6;
long duration;
int distanceCm;
int percentage;

void setup() 
{  
lcd.begin(16,2); 
pinMode(triggerPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(triggerPin2, OUTPUT);
pinMode(echoPin2, INPUT);

}
void loop() 
{
digitalWrite(triggerPin1, LOW);
delayMicroseconds(10);
digitalWrite(triggerPin1, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin1, LOW);
duration = pulseIn(echoPin1, HIGH);
distanceCm= duration*0.034/2;
percentage= (((-10*distanceCm)+100)/9)+100;
lcd.setCursor(0,0); 
  if (distanceCm >=100)
  {
    lcd.print("Empty b1........");
  
   }
  else if (distanceCm<=10)
  {
    lcd.print("Overload b1.....");
  
  }
  else if(distanceCm>10 && distanceCm<100 )
  {
   lcd.print("Garbage b1:");
   lcd.print(percentage);
   lcd.print("%");
    delay(10);
  }

digitalWrite(triggerPin2, LOW);
delayMicroseconds(10);
digitalWrite(triggerPin2, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin2, LOW);
duration = pulseIn(echoPin2, HIGH);
distanceCm= duration*0.034/2;
percentage= (((-10*distanceCm)+100)/9)+100;
lcd.setCursor(1,1); 
  if (distanceCm >=100)
  {
    lcd.print("Empty b2........");
   
  }
  else if (distanceCm<=10)
  {
    lcd.print("Overload b2.....");
   
  }
  else if(distanceCm<100 && distanceCm >10)
  {
lcd.print("Garbage b2:");
lcd.print(percentage);
lcd.print("%");}
delay(10);
 
}
