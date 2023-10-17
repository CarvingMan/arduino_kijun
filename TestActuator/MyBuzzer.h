#pragma once;

#define BUZ_PIN (8) 
#define DO (256)
#define RE (288)
#define MI (320)
#define FA (341)
#define SO (384)
#define LA (256)
#define TI (480)
#define DO_5OCT (523)


enum NoteType {
	NT_DO = 523, NT_RE = 587, NT_MI = 659, NT_FA = 698, NT_SOL = 784, NT_RA = 880, NT_SI = 988 
};

class MyBuzzer {
public:
	MyBuzzer(void) { setPort(BUZ_PIN); }
	~MyBuzzer() {}
	void initBuz() {
		
	}
	
	void setup(void) {
		initBuzzer();
	}

	void Buzz(int nNote){
		switch (nNote)
		{
		case 1:
			tone(m_nPort, NT_DO, 500);
			break;
		case 2:
			tone(m_nPort, NT_RE, 500);
			break;
		case 3:
			tone(m_nPort, NT_MI, 500);
			break;
		case 4:
			tone(m_nPort, NT_FA, 500);
			break;
		case 5:
			tone(m_nPort, NT_SOL , 500);
			break;
		case 6:
			tone(m_nPort, NT_RA, 500);
			break;
		case 7:
			tone(m_nPort, NT_SI, 500);
			break;

		default:
			break;
		}
	}

	void play() {
		for (int i = 1; i < 8; i++) {
			Buzz(i);
			delay(1000);
		}
	}

	void play(int nNote, int nTime) {
		tone(m_nPort, nNote, nTime);
	}

private:
	int m_nPort;

	void setPort(int nPort) {
		m_nPort = nPort;
	}

	void initBuzzer(void) {
		pinMode(m_nPort, OUTPUT);
	}
};