
/*
  추가적인 요소
  1. (문제)led를 점등하기 전에 RouletteLED함수를 호출하여
       led에 모든 rgb색상이 빠르게 전환되며 마치 룰렛처럼 돌아간다.
       3번 반복 후, randLED함수에서 Red Blue, Green중 랜덤하게 점등한다.
  2. 반응시간이 2초가 넘을 경우 이는 틀린것으로 간주하여 점수를 감점한다.
  3. 한 문제가 끝났을 시 ClearScreen함수를 호출하여 SerialMonitor화면을 정리한다.
*/


#define SERIAL_RATE (9600)
#define PIN_R (8)
#define PIN_G (9)
#define PIN_B (10)
#define CHECK_R (1)
#define CHECK_G (2)
#define CHECK_B (4)
#define LEFT_BUTTON (2)
#define RIGHT_BUTTON (3)
#define DELAY_LED (200)
#define DELAY_ROULETTE (50)



enum ButtonType {  // 버튼이 눌러진 상태용 열거형 상수
  BT_NONE,
  BT_LEFT,
  BT_RIGHT,
  BT_BOTH
};

//전역 변수
int nScore;

int nRand;

void initLed() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void initGame() {
  Serial.begin(SERIAL_RATE);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  randomSeed(analogRead(A0));
  initLed();
}

void turnRgbLed(int nColor) {
  int nR = nColor & CHECK_R;  // &: 비트 단위 and 연산
  int nG = nColor & CHECK_G;
  int nB = nColor & CHECK_B;
  digitalWrite(PIN_R, (nR) ? HIGH : LOW);
  digitalWrite(PIN_G, (nG) ? HIGH : LOW);
  digitalWrite(PIN_B, (nB) ? HIGH : LOW);
}

void turnOffLed() {
  digitalWrite(PIN_R, LOW);
  digitalWrite(PIN_G, LOW);
  digitalWrite(PIN_B, LOW);
}



void displayLed() {
  for (int i = 1; i <= 7; i++) {
    turnRg#bLed(i);
    delay(DELAY_LED);
  }
}

ButtonType getButtonInput() {
  int nInputLeft = digitalRead(LEFT_BUTTON);
  int nInputRight = digitalRead(RIGHT_BUTTON);
  delay(100);  // 입력을 시간을 두고 입력을 받기 위함
  ButtonType nResult;
  if (nInputLeft == LOW) {
    if (nInputRight == LOW) nResult = BT_BOTH;
    else nResult = BT_LEFT;
  } else {
    if (nInputRight == LOW) nResult = BT_RIGHT;
    else nResult = BT_NONE;
  }
  return nResult;
}



//화면을 정리하기 위한 함수
void ClearScreen() {
  delay(2000);
  for (int i = 0; i <= 40; i++) {
    Serial.println();
  }
}



// 게임 인트로 화면 led반복
void IntroGame(int nInput) {
  Serial.println("rgdLED게임입니다!!!!");
  Serial.println("아무버튼이나 누르면 시작합니다.\n\n\n");
  while (nInput == BT_NONE) {
    displayLed();
    nInput = getButtonInput();
  }
  turnOffLed();
}

//게임 시작전 버튼을 누르지 않을 때까지 반복하는 함수
void notbutton(int nInput) {

  while (nInput != BT_NONE) {
    nInput = getButtonInput();
    Serial.println("\n\n\n버튼을 누르지 마세요.");
    delay(500);
  }
}


// led색이 모든  rgb색 대로 빠르게 변하며 3번 반복한다. 시각적으로  룰렛처럼 보이다 문제가 나오기 위하여
void RouletteLED() {
  int count = 3;
  while (count != 0) {

    for (int i = 1; i <= 7; i++) {
      turnRgbLed(i);
      delay(DELAY_ROULETTE);
    }
    count--;
  }
  turnOffLed();
}

//난수를 발생하여 Led를 점등
void randLED() {
  Serial.println("RGB 깃발 중의 하나가 표시됩니다.\n\n");
  nRand = random(BT_LEFT, BT_BOTH + 1);  // 1, 2, 3
  if (nRand == 1) {
    Serial.println("\t빨강!\n\n");
    turnRgbLed(1);
  }  // R
  else if (nRand == 2) {
    Serial.println("\t파랑!\n\n");
    turnRgbLed(4);
  }  // B
  else {
    Serial.println("\t초록!\n\n");
    turnRgbLed(2);
  }  // G
}



//결과 출력
void Result(int nInput, unsigned long startTime, unsigned long inputTime) {
  if (inputTime >= 2000) {  //2초 이상일시
    Serial.println("반응이 너무 느리신데요~? \t감점-1!\n");
    nScore--;
  } else {
    if (nInput == nRand) {
      Serial.print("\t성공!! \t득점 +1~!!\n");
      nScore++;
    } else {
      Serial.print("\t실패!! \t감점-1이에요~ㅠㅠ\n");
      nScore--;
    }
  }

  Serial.println("\t스코어 : " + String(nScore));
  Serial.println("\t반응시간 : " + String(inputTime / 1e3) + "초");
  ClearScreen();
}

//정답 입력
int InputAnswer(int nInput) {
  nInput = getButtonInput();
  while (nInput == BT_NONE) {
    nInput = getButtonInput();
  }
  return nInput;
}



//stepup()
void setup() {
  // put your setup code here, to run once:
  initGame();
  int nInput = getButtonInput();
  IntroGame(nInput);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nInput = getButtonInput();

  notbutton(nInput);

  // 난수 발생, 게임 시작
  RouletteLED();  // red를 빠르게 점등하며 카운트 다운한다.
  randLED();      //난수를 발생하여 Led를 점등

  unsigned long startTime = millis();  // led가 점등하였으면 시간을 기록한다.
  nInput = InputAnswer(nInput);
  unsigned long inputTime = millis() - startTime;


  Result(nInput, startTime, inputTime);
}