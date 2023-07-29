#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int trigPin1 = 9;
int echoPin1 = 7;
int trigPin2 = 10;
int echoPin2 = 8;
int green = A0;             
int red = A2;
int yellow = A1;
int buzzer = A3;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(yellow,OUTPUT);
  lcd.begin(16,2);
 digitalWrite(red,HIGH);
 delay(1000);
 digitalWrite(red,LOW);
 digitalWrite(yellow,HIGH);
 delay(1000);
 digitalWrite(yellow,LOW);
}

void loop()
{
  calculateDistance(echoPin1, trigPin1);
  calculateDistance(echoPin2, trigPin2);
}

void calculateDistance(int echo, int trigger) {
  
  long duration,distance;
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.412;

  if (distance>200)
  {
    lcd.setCursor(0,0);
    lcd.print("NO OBSTACLE ");
    lcd.setCursor(0,2);
    lcd.print("WITHIN:");
    lcd.print("200cm");
    digitalWrite(yellow,LOW); 
    digitalWrite(green,HIGH); 
    }
else if(distance<=200 || distance>100)
  {
    lcd.setCursor(0,0);
    lcd.print("OBJECT DETECTED");
    lcd.setCursor(0,2);
    lcd.print("AT :");
    lcd.print(distance);
    lcd.print("cm");  
      }
if(distance >= 200)
{
  digitalWrite(red,LOW);
 
  }
else if(distance>200 || distance<=100)
{
  lcd.setCursor(0,0);
  lcd.print("ALERT!,TOO CLOSE");
  lcd.setCursor(0,2);
  lcd.print("DISTANCE:");
  lcd.print(distance);
  lcd.print("cm");
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW); 
  digitalWrite(buzzer,HIGH);
}
else
{
  digitalWrite(yellow,HIGH);
  delay(100);
  digitalWrite(yellow,LOW);
  delay(100);
  digitalWrite(red,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(green,LOW); 
}
delay(100);
  }
