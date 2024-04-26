//C:\Users\12647\Desktop\pic\3.bmp

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Huffman.h"
#include"Compress.h"
using namespace std;

#define N 256

//程序入口
int main()
{
	int weight[N] = { 0 };
	char  filename[256];
	cout << "请输入您的文件名:";
	cin >>filename;

	int ch;
	FILE *in = fopen(filename, "rb");

	while ((ch = getc(in)) != EOF)
	{
		weight[ch]++;	//记录权值
	}
	fclose(in);
	Compress(filename, weight, N);//压缩

	system("pause");
	return 0;
}