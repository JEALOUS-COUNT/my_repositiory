//C:\Users\12647\Desktop\pic\3.bmp

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Huffman.h"
#include"Compress.h"
using namespace std;

#define N 256

//�������
int main()
{
	int weight[N] = { 0 };
	char  filename[256];
	cout << "�����������ļ���:";
	cin >>filename;

	int ch;
	FILE *in = fopen(filename, "rb");

	while ((ch = getc(in)) != EOF)
	{
		weight[ch]++;	//��¼Ȩֵ
	}
	fclose(in);
	Compress(filename, weight, N);//ѹ��

	system("pause");
	return 0;
}