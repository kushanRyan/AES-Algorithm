#include <iostream>
#include "AES.h"
#include "deAES.h"
#include "sBoxSpawner.h"
#include <string>
using namespace std;
//S盒
static int S[16][16] = {0};
//逆S盒
static int S1[16][16] = {0};
//字符串随机生成
char* strRandom() {
	char randomCipher[17];
	for (int i = 0; i < 16; i++) {
		char temp = rand() % 256;
		randomCipher[i] = abs(temp);
	}
	return randomCipher;
}
//执行AES
void excuteAES() {
	//生成S盒和逆S盒
	spwanSbox(S);
	spwanInvSbox(S1);
	//明/密文 密钥
	char* textContainer, * cipher;
	//输入密钥和明文
	char tempTc[257];
	while (1) {
		cout << "输入明文，请(无慈悲)" << endl;
		cin.get(tempTc, 257);
		if (strlen(tempTc)%16==0) {
			break;
		}
		else {
			cout << "明文长度不符合要求" << endl;
		}
	}
	textContainer = tempTc;
	cipher = strRandom();
	//开始执行AES加解密算法
	AES(textContainer, cipher,S);
	cout << endl;
	deAES(textContainer, cipher,S1);
	cout << endl;
	cout << "AES算法演示完成" << endl;
}
//密文例子(32字节):试看将来的环球，必是赤旗的世界！
int main() {
	excuteAES();
}


