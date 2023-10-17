#pragma once;

#define PIN_R (5)
#define PIN_G (6)
#define PIN_B (7)

#define CHECK_R (1)
#define CHECK_G (2)
#define CHECK_B (4)



class LED {
public:
	LED(void) { initLed(); }
	~LED() {}

	void turnRgbLed(int nColor) {
		int nR = nColor & CHECK_R;  // &: ��Ʈ ���� and ����
		int nG = nColor & CHECK_G;
		int nB = nColor & CHECK_B;
		digitalWrite(PIN_R, (nR) ? HIGH : LOW);
		digitalWrite(PIN_G, (nG) ? HIGH : LOW);
		digitalWrite(PIN_B, (nB) ? HIGH : LOW);
		delay(1000);
	}

	void turnOffLed() {
		digitalWrite(PIN_R, LOW);
		digitalWrite(PIN_G, LOW);
		digitalWrite(PIN_B, LOW);
	}


	void displayLed() { //1�ʿ� �� ���� led���� �ٲ�
		for (int i = 1; i <= 7; i++) {
			turnRgbLed(i);
		}
		turnOffLed();
	}
private:
	int m_nPortR, m_nPortG, m_nPortB;

	void initLed() const{ // led�ʱ�ȭ
		pinMode(PIN_R, OUTPUT);
		pinMode(PIN_G, OUTPUT);
		pinMode(PIN_B, OUTPUT);
	}

	void setPort(int nPortR,int nPortG,int nPortB) {
		m_nPortR = nPortR;
		m_nPortG = nPortG;
		m_nPortB = nPortB;
	}
};