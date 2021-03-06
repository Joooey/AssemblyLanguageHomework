// task3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void ch2q37();
void ch2q38();
void ch2q39();
void ch2q40();
void ch3q35();
void ch3q36();
void ch3q37();
void ch3q38();
void ch3q39();

int main()
{
	//ch2q37();
	//ch2q38();
	//ch2q39();
	//ch2q40();
	//ch3q35();
	//ch3q36();
	//ch3q37();
	//ch3q38();
	ch3q39();
    return 0;
}
void ch2q37()
{
	int num1 = 0, num2 = 0;
	char a[10]= { -10,20,-1,4,-6,9,2,-100,0,7 };
	for(int i=0;i<10;i++)
	printf("%d ", a[i]);
	printf("\n");


	_asm {
		xor edi,edi//+
		xor esi,esi//-
		xor edx,edx//i
		lea ecx, a
	l2:
		mov al,byte ptr [ecx+edx]
		cmp al,0
		jz l3
		cmp al, 0
		jge l1
		inc esi
		jmp l3
	l1 :
		inc edi
	
	l3:
		inc edx
		cmp edx,10
		jl l2
		jmp l4

	
	l4:	
		mov num1, edi
		mov num2, esi
	}
	printf("正数个数：%d\n负数个数：%d\n", num1, num2);

}
void ch2q38()
{
	int num1 = 0, num2 = 0;
	char a[20] = { -10,20,-1,4,-6,9,2,-100,0,7,21,2,34,45,-99,50,90,-77,-2,-1 };
	for (int i = 0; i<20; i++)
		printf("%d ", a[i]);
	printf("\n");


	_asm {
		xor edi, edi//+
		xor esi, esi//-
		xor edx, edx//i
		lea ecx, a
	l2 :
		mov ax, word ptr[ecx + edx]
		cmp ax, 0
		jz l3
		cmp ax, 0
		jge l1
		inc esi
		jmp l3
	l1 :
		inc edi
	l3 :
		inc edx
		cmp edx, 10
		jl l2
		jmp l4


	l4 :
		mov num1, edi
		mov num2, esi
	}
	printf("作为10个16位整数的情况：\n");
	printf("正数个数：%d\n负数个数：%d\n", num1, num2);
	_asm {
		xor edi, edi//+
		xor esi, esi//-
		xor edx, edx//i
		lea ecx, a
	l22 :
		mov eax, dword ptr[ecx + edx]
		cmp eax, 0
		jz l33
		cmp eax, 0
		jge l11
		inc esi
		jmp l33
	l11 :
		inc edi
	l33 :
		inc edx
		cmp edx, 5
		jl l22
		jmp l44
	l44 :
		mov num1, edi
		mov num2, esi
	}
	printf("作为5个32位整数的情况：\n");
	printf("正数个数：%d\n负数个数：%d\n", num1, num2);
}
void ch2q39()
{
	short sum1,sum2;
	char a[10] = { -10,20,-1,4,-6,9,2,-100,0,7 };
	for (int i = 0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");
	_asm {
		xor edi, edi//sum1
		xor edx, edx//i
		lea ecx, a
		l2 :
		mov al, byte ptr[ecx + edx]
		cbw 
		add di, ax

		inc edx
		cmp edx, 10
		jl l2
		mov sum1,di
	}
	printf("有符号数情况：\n");
	printf("%08xH  %d \n", sum1,sum1);
	_asm {
		xor edi, edi//sum1
		xor edx, edx//i

		lea ecx, a
		l1 :
		mov al, byte ptr[ecx + edx]
			add di, ax

			inc edx
			cmp edx, 10
			jl l1
			mov sum2, di
	}
	printf("无符号数情况：\n");
	printf("%08xH  %d \n", sum2, sum2);

}
void ch2q40()
{
	int a[13] = { 1,2,3,4,5,6,7,8,9,-10,-11,-12,-130 };
	for (int i = 0; i<13; i++)
		printf("%d ", a[i]);
	printf("\n");
	int diff;
	int sum1, sum2;
	_asm {
		xor edx, edx//i
		xor esi, esi//ji
		xor edi, edi//ou
		l1 :
		lea ecx, a
		mov ecx, dword ptr[ecx + edx*4]
		test ecx, 00000001H
		jz l2
		add esi, ecx
		jmp l3
		l2 :
		add edi, ecx
		l3 :
		inc edx
		cmp edx, 13
		jl l1
		mov sum1,esi
		mov sum2,edi
		cmp edi, esi
		jge l4
		sub esi,edi
		mov diff,esi
		jmp l5
		l4 :
		sub edi, esi
		mov diff, edi
		l5 :
	}
	printf("奇数之和为：%d\n偶数之和为：%d\n", sum1, sum2);
	printf("奇数之和与偶数之和差的绝对值为：%d\n", diff);
}
void ch3q35()
{
	unsigned a;
	int count;
	printf("请输入一个无符号整数：");
	scanf("%d",&a);
	_asm {
		mov eax,a
		xor edx,edx//i
		xor ecx,ecx//count
		l1:
		test eax,00000001H
		jz l2
		jmp l3
			l2:
		inc ecx
			l3:
		inc edx
			shr eax,1
			cmp edx,32
			jl l1
			mov count,ecx

	}
	printf("该32位整数中位值为0的个数是：%d\n", count);
	
}
void ch3q36()
{
	char a, b;
	printf("请连续输入两个字符：");
	scanf("%c%c",&a,&b);
	unsigned short int x;
	_asm {
		mov cl, a
		mov dl, b
		xor ebx, ebx; i = 0
		xor ax, ax
		L1 :
		mov ch, 00000001B
			and ch, dl
			or al, ch
			ror ax, 1
			mov ch, 00000001B
			and ch, cl
			or al, ch
			ror ax, 1
			ror cl, 1
			ror dl, 1
			inc ebx; i++
			cmp ebx, 8
			jl L1
			mov x, ax
	}
	printf("a=%xH\n", a);
	printf("b=%xH\n", b);
	printf("a7b7a6b6a5b5a4b4a3b3a2b2a1b1a0b0 = %04xH\n", x, x); 

}
void ch3q37()
{
	int a, b;
	printf("请输入两个整数：");
	scanf("%d%d", &a, &b);
	_asm {
		mov ecx,a
		mov edx,b
		cmp ecx,0
		jge l1
		neg ecx
		l1:
		cmp edx,0
		jge l2
		neg edx
			l2:
		xchg cx,dx
		mov a,edx
			mov b,ecx

	}
	printf("交换两数绝对值的高十六位后：\na=%d,b=%d\n", a, b);
}
void ch3q38()
{
	char strs[100];

	printf("请输入一个字符串：");
	scanf("%s", strs);

	char  a = 0, b = 0, c = 0;

	_asm{
	mov esi,0;//下标
	lea eax,strs;//strs的首地址给eax
	mov cl,0;//英文字符个数
	mov ch,0;//十进制字符个数
	mov dl,0;//其他字符个数
l1:
	mov bl,byte ptr[eax + esi];//取当前一个字节
	inc esi
	cmp bl ,0;
	je l2;//到达最后一个字节

	cmp bl,30H;
	jae l3;
	inc dl;//否则一定是其他字符
	jmp l1;


l3:
	cmp bl,39H;
	ja l4;
	inc ch;//否则就是数字
	jmp l1;
l4:
	cmp bl,41H;
	jae l5;//如果大于等于65
	inc dl;//否则就是其他字符
	jmp l1;
l5:
	cmp bl,5AH;
	ja l6;//如果大于90
	inc cl;//否则是英文字符
	jmp l1;
l6:
	cmp bl,61H;
	jae l7;//如果大于等于97
	inc dl;//否则就是其他字符
	jmp l1;
l7:
	cmp bl,7AH;
	ja l8;//如果大于122
	jmp l9;


l8:
	inc dl;
	jmp l1;

l9:
	inc cl;//否则就是英文字符
	jmp l1;

l2:
	mov a, cl
	mov b, ch
	mov c, dl

	}

	printf("英文字符个数：%d，十进制字符个数：%d，其他字符个数：%d\n", a, b, c);

}
void ch3q39()
{
	char str[100];
	char str2[100];

	printf("请输入一个字符串：");
	scanf("%s", str);

	
	_asm{
	
	lea eax,str
	lea ebx,str2
	xor esi,esi//下标
	xor edi,edi
	l1:

	mov cl,byte ptr[eax + esi]//获取当前字符
	cmp cl,0
	jne l2
	jmp l3

	l2:
	inc esi
	jmp l1

	l3:
	dec esi
	cmp esi, 0
	jge l4
	jmp l5
	
	l4:
	mov cl, byte ptr[eax + edi]
	mov byte ptr [ebx + esi], cl
	inc edi
	jmp l3
	l5:
	mov [ebx+edi],0
	}
	

	printf("逆序之后的字符串：%s\n", str2);
}