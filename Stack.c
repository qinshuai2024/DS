#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//创建结点
SNode* CreatSNode(DataType x)
{
	SNode* newnode = (SNode*)malloc(sizeof(SNode));
	if (newnode == NULL)
		exit(-1);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//判断是否为空
bool IsEmpty(SNode* SN)
{
	if (SN == NULL)
	{
		//printf("栈为空！\n");
		return true;
	}
	else
	{
		return false;
	}
}

//入栈
void PushStack(SNode** pSN, DataType x)
{
	SNode* newnode = CreatSNode(x);
	if (*pSN == NULL)
	{
		*pSN = newnode;
	}
	else
	{
		newnode->next = *pSN;
		*pSN = newnode;
	}
}

//出栈
void PopStack(SNode** pSN)
{
	if (*pSN == NULL)
	{
		return;
	}
	else
	{
		SNode* temp = *pSN;
		*pSN = (*pSN)->next;
		free(temp);
	}
}

//获得栈顶元素
DataType GetTop(SNode* SN)
{
	return SN->data;
}

//返回栈的元素个数
int GetSize(SNode* SN)
{

	int count = 0;
	
		
	SNode* temp = SN;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}


//清空栈内元素
void MakeEmpty(SNode* SN)
{
	while (SN)
	{
		SNode*  temp = SN;
		SN = SN->next;
		free(temp);
	}
}

//打印栈内元素
void PrintStack(SNode* SN)
{
	SNode* temp = SN;
	printf("TOP");
	while (temp)
	{
		printf("->%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}