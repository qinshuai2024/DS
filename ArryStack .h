#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

//��˳������ʽ����ջ
#include<stdio.h>
#include<stdbool.h>

typedef int STDataType;
struct Stack
{
	STDataType* data;
	int top;        //ָ��ջ��Ԫ��
	int maxsize;   //ջ���������
}; 
typedef struct Stack ST;

//��ʼ��ջ
void InitStack(ST* ps);

//�ж�ջ�Ƿ�Ϊ��
bool IsEmptyStack(ST* ps);

//�ж��Ƿ�ջ��
bool IsFullStack(ST* ps);

//��ȡջ��Ԫ��
STDataType GetTop(ST* ps);

//��ջ
void PushStack(ST* ps, STDataType x);

//��ջ
void PopStack(ST* ps);

//���ջ
void MakeEmpty(ST* ps);

//���ջ��Ԫ�ظ���
int GetSizeStack(ST* ps);

//����ջ
void DestroyStack(ST* ps);

//��ӡջ
void PrintStack(ST* ps);
