#include <iostream>
#include "AES.h"
#include <fstream>
#include <sstream>
#pragma warning(disable:4996);
using namespace std;
//AES加密

//用来调用AES算法
void AES(char* container, char* cipher, int S[16][16]) {
	int textContainer[4][4];
	//将明/密文的内容转化为4*4的矩阵
	for (int z = 0; z < strlen(container);z+=16) {
		convertToIntArray(container+z, textContainer);
		//进行密钥拓展
		expandedKey(cipher, S);
		//首次的轮密钥加
		addRoundKey(textContainer, 0);
		int i = 1;
		for (i = 1; i < 10; i++) {
			subBytes(textContainer, S);
			shiftRow(textContainer);
			mixColumn(textContainer);
			addRoundKey(textContainer, i);
		}
		//最后一次处理时，不需要进行列混合
		subBytes(textContainer, S);
		shiftRow(textContainer);
		addRoundKey(textContainer, 10);
		convertArrayToStr(textContainer, container+z);
	}
	cout << "密文是:";
	cout << container << endl;
	cout << "已完成AES加密算法" << endl;
	FILE* a = fopen("D:\\test.txt", "wb");
	int L;
	L = strlen(container);
	fwrite(container, L, 1, a);
	fclose(a);
}