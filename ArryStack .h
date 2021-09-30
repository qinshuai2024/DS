#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

//以顺序表的形式构建栈
#include<stdio.h>
#include<stdbool.h>

typedef int STDataType;
struct Stack
{
	STDataType* data;
	int top;        //指向栈顶元素
	int maxsize;   //栈的最大容量
}; 
typedef struct Stack ST;

//初始化栈
void InitStack(ST* ps);

//判断栈是否为空
bool IsEmptyStack(ST* ps);

//判断是否栈满
bool IsFullStack(ST* ps);

//获取栈顶元素
STDataType GetTop(ST* ps);

//入栈
void PushStack(ST* ps, STDataType x);

//出栈
void PopStack(ST* ps);

//清空栈
void MakeEmpty(ST* ps);

//获得栈中元素个数
int GetSizeStack(ST* ps);

//销毁栈
void DestroyStack(ST* ps);

//打印栈
void PrintStack(ST* ps);
