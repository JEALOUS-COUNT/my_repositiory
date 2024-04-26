#define _CRT_SECURE_NO_WARNINGS
#include"Huffman.h"
#include<iostream>
using namespace std;

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n) 
{ 
	int m, i, s1, s2; 
	HuffmanTree p;

	if (n <= 1)    return;
	m = 2 * n - 1;//Huffman树的节点树目

	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); 
	//初始化数的树的所有结点
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)
	{//初始化叶子结点
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; ++i, ++p)
	{
		(*p).parent = 0;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}

	for (i = n + 1; i <= m; ++i) // 建赫夫曼树
	{ 
		select(HT, i - 1, s1, s2);
		HT[s1].parent = HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	


	/*===============求哈夫曼编码========================*/
	unsigned c, cdlen;
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	// 分配n个字符编码的头指针向量
	char *cd;
	cd = (char*)malloc(n * sizeof(char)); 
	c = m;
	cdlen = 0;

	for (i = 1; i <= m; ++i)
		HT[i].weight = 0; //结点
	while (c)
	{
		if (HT[c].weight == 0)
		{ // 向左
			HT[c].weight = 1;
			if (HT[c].lchild != 0)
			{
				c = HT[c].lchild;
				cd[cdlen++] = '0';
			}
			else if (HT[c].rchild == 0)
			{ 
				HC[c] = (char *)malloc((cdlen + 1) * sizeof(char));
				cd[cdlen] = '\0';
				strcpy(HC[c], cd); 
			}
		}
		else if (HT[c].weight == 1)
		{ // 向右
			HT[c].weight = 2;
			if (HT[c].rchild != 0)
			{
				c = HT[c].rchild;
				cd[cdlen++] = '1';
			}
		}
		else
		{ // HT[c].weight==2,退回
			HT[c].weight = 0;
			c = HT[c].parent;
			--cdlen; // 退到父结点,编码长度减1
		}
	}
	free(cd);
}

void select(HuffmanTree t, int i, int &s1, int &s2)
{ // s1为最小，s2为次小
	int j;
	s1 = min(t, i);
	s2 = min(t, i);
	if (s1 > s2)
	{
		j = s1;
		s1 = s2;
		s2 = j;
	}
}

int min(HuffmanTree t, int i)
{ // select()调用
	int j, s;
	int k = INT_MAX; 
	for (j = 1; j <= i; j++)
		if (t[j].weight < k && t[j].parent == 0)
		{
			k = t[j].weight; 
			s = j;
		}
	t[s].parent = 1;	

	return s;
}
