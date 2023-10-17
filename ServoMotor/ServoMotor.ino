#include <Servo.h> //아두이노에서 제공하는 라이브러리 헤더파일 폴더 검색해서 include 이기에 <> 사용자 헤더면""

#define DIGITAL_4 4 
// Servo-moter 결선도
// 빨간색(중앙의 도선): +5v 연결
// 갈색 : GND(0v)연결
//주황색: digital port(2~13)연결

Servo servo;

void setup() {
  // put your setup code here, to run once:
  // 서보 모터를 제어할 digital port 연결
  servo.attach(DIGITAL_4); // D4(digital 4)에 서보 모터의 제어선 연결
  servo.write(0); //서보 모터 위치를 0으로 이동
  delay(1000); //1000ms 동안 기다림: 서보모터가 이동할 시간을 
}

void loop() {
  // put your main code here, to run repeatedly:
  // 서보 모터 이동 범위: 0~180도 만 이동 가능
  // DC모터: 모든 각도로 이동 가능; 여러번 회전도 가능
  servo.write(180); //180도 위치로 이동
  delay(1000); //1000ms 기다림
  servo.write(0); //원위치
  delay(1000);
}
