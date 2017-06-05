#include <Ultrasonic.h>
#define TRIGGER_PIN 13
#define ECHO_PIN 8
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 9,3,4,5);

void setup() 
{
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(0,int0,LOW);
  lcd.begin(20, 2);
  lcd.print("hello, world!");
    pinMode(7,INPUT_PULLUP);

}
void loop() {
  
   
    if (digitalRead(7) == LOW)
   noInterrupts();
   //Serial.print(digitalRead(7));
  else
   interrupts();
//Serial.print(digitalRead(7));
  delay(1000);


}
void int0()
{
    float cmMsec, inMsec;
    long microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
    inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
    Serial.print("MS: "); Serial.print(microsec);
    Serial.print(", CM: "); Serial.print(cmMsec);
    Serial.print(", IN: "); Serial.println(inMsec);
    lcd.begin(20, 2);
    lcd.print("MS: "); lcd.print(microsec);
    lcd.setCursor(0, 1);
    lcd.print("CM: "); lcd.print(cmMsec);
    lcd.print(", IN: "); lcd.print(inMsec);
    delay(1000);
  
}

