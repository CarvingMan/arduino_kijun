void setup() {
  // put your setup code here, to run once:
  //Dcmotot 사용법은 led와 동일?
  //DC motor: port 2개 필요
  // moter 초기화
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(1000);

  //방향 회전
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1000);
}
