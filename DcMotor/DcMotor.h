#pragma once

#define DEF_SERVO_PORT1 (2)
#define DEF_SERVO_PORT2 (3)

class DcMotor
{
public:
	DcMotor(void) {
		setPort(DEF_SERVO_PORT1, DEF_SERVO_PORT2);
	}

	~DcMotor() {}


	void setPort(int nPort) { 
		m_nPort = nPort1;
		m_nPort = nPort2;
	}

private:
	int m_nPort1; // m_: member�� ��
	int m_nPort2; // m_: member�� ��
};