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

//创建结点
SNode* CreatSNode(DataType x);


//判断是否为空
bool IsEmpty(SNode* SN);

//入栈
void PushStack(SNode** pSN, DataType x);

//出栈
void PopStack(SNode** pSN);

//获得栈顶元素
DataType GetTop(SNode* SN);

//返回栈的元素个数
int GetSize(SNode* SN);

 
//清空栈内元素
void MakeEmpty(SNode* SN);


//打印栈内元素
void PrintStack(SNode* SN);
