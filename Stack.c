#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//�������
SNode* CreatSNode(DataType x)
{
	SNode* newnode = (SNode*)malloc(sizeof(SNode));
	if (newnode == NULL)
		exit(-1);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//�ж��Ƿ�Ϊ��
bool IsEmpty(SNode* SN)
{
	if (SN == NULL)
	{
		//printf("ջΪ�գ�\n");
		return true;
	}
	else
	{
		return false;
	}
}

//��ջ
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

//��ջ
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

//���ջ��Ԫ��
DataType GetTop(SNode* SN)
{
	return SN->data;
}

//����ջ��Ԫ�ظ���
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


//���ջ��Ԫ��
void MakeEmpty(SNode* SN)
{
	while (SN)
	{
		SNode*  temp = SN;
		SN = SN->next;
		free(temp);
	}
}

//��ӡջ��Ԫ��
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