#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int DataType;


struct StackNode
{
	DataType data;
	struct StackNode* next;
};
typedef struct StackNode SNode;

//�������
SNode* CreatSNode(DataType x);


//�ж��Ƿ�Ϊ��
bool IsEmpty(SNode* SN);

//��ջ
void PushStack(SNode** pSN, DataType x);

//��ջ
void PopStack(SNode** pSN);

//���ջ��Ԫ��
DataType GetTop(SNode* SN);

//����ջ��Ԫ�ظ���
int GetSize(SNode* SN);

 
//���ջ��Ԫ��
void MakeEmpty(SNode* SN);


//��ӡջ��Ԫ��
void PrintStack(SNode* SN);
