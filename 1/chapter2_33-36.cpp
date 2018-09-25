// task2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"

void q33_34();
void q35();
void q36();

int main()
{
	q33_34();
	q35();
	fflush(stdin);
	q36();
	return 0;
}
void q33_34()
{
	int a, b;
	int result1, result2;
	int difference;
	printf("请输入两个整数：");
	scanf("%d%d", &a, &b);
	_asm {
		MOV ECX, a
		MOV EDX, b
		CMP ECX, EDX
		JGE LAB1
		MOV result1, EDX
		SUB EDX, ECX
		MOV difference, EDX
		JMP OK1
		LAB1 :
		MOV result1, ECX
			SUB ECX, EDX
			MOV difference, ECX
			OK1 :
	}
	printf("有符号整数情况较大值：%d\n", result1);
	_asm {
		MOV ECX, a
		MOV EDX, b
		CMP ECX, EDX
		JAE LAB2
		MOV result2, EDX
		JMP OK2
		LAB2 :
		MOV result2, ECX
			OK2 :
	}
	printf("无符号整数情况较大值：%d\n", result2);
	printf("两数差的绝对值为：%d\n", difference);

}
void q35()
{
	char str[4];
	short word1 = 0, word2 = 0;
	int word3 = 0;
	printf("\n请输入四个字符：");
	setbuf(stdin, NULL);
	scanf("%c%c%c%c", &str[0],&str[1],&str[2],&str[3]);

	_asm {
	
		mov ah, str[0]
		mov al, str[1]
		mov word1, ax
		shl eax,16
		mov ah,str[2]
		mov al,str[3]
		mov word2, ax
		mov word3,eax

	}

	printf("%xH\n", word2);
	printf("%xH\n", word1);
	printf("%xH\n", word3);

}
void q36()
{

	char str[100000];
	printf("\n请输入一个字符串：");
	setbuf(stdin, NULL);
	scanf("%s", str);
	int count;
	_asm {
		lea edi, str
		mov eax, 0
		L1 : 
		cmp byte ptr[edi], 0
		je L2
		inc edi
		inc eax
		mov count,eax
		jmp L1
		L2 : 
	}
	printf("该字符串长度为：%d\n", count);
		
}

