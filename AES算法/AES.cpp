#include <iostream>
#include "AES.h"
#include <fstream>
#include <sstream>
#pragma warning(disable:4996);
using namespace std;
//AES����

//��������AES�㷨
void AES(char* container, char* cipher, int S[16][16]) {
	int textContainer[4][4];
	//����/���ĵ�����ת��Ϊ4*4�ľ���
	for (int z = 0; z < strlen(container);z+=16) {
		convertToIntArray(container+z, textContainer);
		//������Կ��չ
		expandedKey(cipher, S);
		//�״ε�����Կ��
		addRoundKey(textContainer, 0);
		int i = 1;
		for (i = 1; i < 10; i++) {
			subBytes(textContainer, S);
			shiftRow(textContainer);
			mixColumn(textContainer);
			addRoundKey(textContainer, i);
		}
		//���һ�δ���ʱ������Ҫ�����л��
		subBytes(textContainer, S);
		shiftRow(textContainer);
		addRoundKey(textContainer, 10);
		convertArrayToStr(textContainer, container+z);
	}
	cout << "������:";
	cout << container << endl;
	cout << "�����AES�����㷨" << endl;
	FILE* a = fopen("D:\\test.txt", "wb");
	int L;
	L = strlen(container);
	fwrite(container, L, 1, a);
	fclose(a);
}