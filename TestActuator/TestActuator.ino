/*[Actiator(구동기)구햔]
1. 모터: servo motor, Dc motor
-0도 -> 180도 -> 0도
2. 3색 led
  - 7개 색깔을 1초씩 출력
3.부저(buzzer)
  -도레미파솔라시도를 1초씩 출력
4. 모든 acturator 클래스로
*/
#include "AServo.h"
#include "LED.h"
#include "MyBuzzer.h"

AServo aServo;
LED led;
MyBuzzer myBuzzer;


int nLed;
int nNote;

void setup() {
  // put your setup code here, to run once:
  aServo.setup();
  aServo.move(0);
  myBuzzer.setup();

  nLed = 0;
  nNote = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  led.turnRgbLed(nLed);
  nLed++;
  aServo.move(180);
  //myBuzzer.Buzz(nNote);
  myBuzzer.play();
  nNote++;
  //myBuzzer.play();
  aServo.move(0);
  if(nLed >= 7){
    nLed = 0;
  }
  if(nNote >= 8){
    nNote = 1;
  }
  delay(1000);
}
