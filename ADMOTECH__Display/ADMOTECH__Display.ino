#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SERIAL_NUMBER 1125200 

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET  -1
#define SCREEN_ADDRESS 0x3c

#define CurSorX 5 //디스플레이 출력 초기 x 좌표
#define CurSorY 5 //디스플레이 출력 초기 y 좌표
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

double Pow=-83.5f;
double adc=70.1f;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_NUMBER);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  //testdrawrect();
  Startmain();//메인 시작화면
  Digital();  // POW, ADC 출력
}

void loop() {
  // put your main code here, to run repeatedly:

}

void Startmain(void) { //메인화면
    display.clearDisplay();  // 디스플레이 버퍼 지우기
    display.setTextSize(2); // 폰트 사이즈 2
    display.setTextColor(WHITE);  // 하얀색으로 설정
    display.setCursor(CurSorX, CurSorY); // 좌표 설정
    display.println("Power Meter 1.0");
    display.setCursor(5, display.getCursorY()); // 문자의 y값을 반환
    display.println("by ADMOTECH");
    display.drawRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT,WHITE);//사각형 그리기
    display.display();
    delay(2000);
}

void  Digital(void) { // 측정 화면
    while (1){
    display.clearDisplay();  // 디스플레이 버퍼 지우기
    display.drawRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT,WHITE);//사각형 그리기
    display.setTextSize(2); // 폰트 사이즈 2
    display.setTextColor(WHITE); // 하얀색으로 설정
    display.setCursor(CurSorX, CurSorY); // 좌표 설정
    display.println("POW: "+String(Pow,1)+" dBm");
    display.setCursor(5, display.getCursorY());
    display.println("@ADC: "+String(adc,1));
    display.display();
    delay(1000);
    }
}

