/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x64 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>         //i2c 통신을 위한 라이브러리
#include <Adafruit_GFX.h> //그래픽 관련 라이브러리
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



// 로고 출력하는 함수
void DisplayLOGO(){
   // 버퍼 초기화
  display.clearDisplay();

  display.setTextSize(2); //폰트 사이즈 설정
  display.setTextColor(WHITE); //글자 색상 설정 
  display.setCursor(0,3); //위치 x,y 왼쪽 상단이 0,0
  display.print("PowerMeter");
  display.println("    1.0\n");

  display.setTextSize(1); //폰트 사이즈 설정
  display.print("by ");
  display.setTextSize(2); //폰트 사이즈 설정
  display.println("ADMOTECH");
  display.display(); //화면 출력 
  delay(2000); //2초후 변경

  display.clearDisplay(); //버퍼 초기화
}


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { //oled lcd 주소 = 0x3C
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // 로고 출력
  DisplayLOGO();

}

float fNum1 = -83.8;
float fNum2 = 70.1;

// 값을 출력하는 함수
void DisplayNumber(float n1, float n2){
  display.setTextSize(2); //폰트 사이즈 설정
  display.setTextColor(WHITE); //글자 색상 설정 
  display.setCursor(0,0); //위치
  display.println("pow: ");
  display.print(" "+String(n1)+"dBm");
  display.println("@ ADC: ");
  display.println("   "+String(n2));
  display.display(); //화면 출력 
  delay(2000); 
}

void loop() {
  //함수 호출
  DisplayNumber(fNum1, fNum2);
}

