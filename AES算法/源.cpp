#include <iostream>
#include "AES.h"
#include "deAES.h"
#include "sBoxSpawner.h"
#include <string>
using namespace std;
//S��
static int S[16][16] = {0};
//��S��
static int S1[16][16] = {0};
//�ַ����������
char* strRandom() {
	char randomCipher[17];
	for (int i = 0; i < 16; i++) {
		char temp = rand() % 256;
		randomCipher[i] = abs(temp);
	}
	return randomCipher;
}
//ִ��AES
void excuteAES() {
	//����S�к���S��
	spwanSbox(S);
	spwanInvSbox(S1);
	//��/���� ��Կ
	char* textContainer, * cipher;
	//������Կ������
	char tempTc[257];
	while (1) {
		cout << "�������ģ���(�޴ȱ�)" << endl;
		cin.get(tempTc, 257);
		if (strlen(tempTc)%16==0) {
			break;
		}
		else {
			cout << "���ĳ��Ȳ�����Ҫ��" << endl;
		}
	}
	textContainer = tempTc;
	cipher = strRandom();
	//��ʼִ��AES�ӽ����㷨
	AES(textContainer, cipher,S);
	cout << endl;
	deAES(textContainer, cipher,S1);
	cout << endl;
	cout << "AES�㷨��ʾ���" << endl;
}
//��������(32�ֽ�):�Կ������Ļ��򣬱��ǳ�������磡
int main() {
	excuteAES();
}


