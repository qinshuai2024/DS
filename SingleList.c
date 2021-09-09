#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

// ����ı������ͷָ�룬��һ��ָ��
void SListPrint(SLNode* phead)
{
	SLNode* sur = phead;//��������
	while (sur != NULL)
	{
		printf("%d->", sur->data);
		sur = sur->next;
	}
	printf("NULL\n");
}

//����һ���µĽ��
SLNode* CreatSLNode(DataType x)
{
	SLNode* NewNode = (SLNode*)malloc(sizeof(SLNode));
	if (NewNode == NULL)
		exit(-1);
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

// ���ܻ�ı������ͷָ�룬������ָ��
void SListPushBack(SLNode** pphead, DataType x)
{
	//β��
	//1������Ϊ�ա�2������Ϊ��

	SLNode* new = CreatSLNode(x);
	if (*pphead == NULL)
	{
		//�������ĵ�һ����㸳ֵ��ͷָ��
		*pphead = new;
	}
	else
	{
		//Ѱ�������β
		SLNode* sur = *pphead;
		while(sur->next!=NULL)
		{
			sur = sur->next;
		}
		//����
		sur->next = new;
	}
}
void SListPushFront(SLNode** pphead, DataType x)
{
	//ͷ��
	//1������Ϊ�ա�2������Ϊ��
	SLNode* new = CreatSLNode(x);
	if (*pphead == NULL)
	{
		//�������ĵ�һ����㸳ֵ��ͷָ��
		*pphead = new;
	}
	else
	{
		//����
		new->next = *pphead;
		//���²���Ľ��ָ�븳��ͷָ��
		*pphead = new;
	}

}
void SListPopFront(SLNode** pphead)
{
	//ͷɾ
	//1������Ϊ�ա�2������ֻ��һ�����

	if (*pphead == NULL)
	{
		printf("SingleList is empty\n");
		return;
	}
	else
	{
		SLNode* sur = *pphead;
		//��ͷ������һ����ַ��ֵ��ͷָ��
		*pphead = sur->next;
		//�ͷ�ͷ���ռ�
		free(sur);
	}
}
void SListPopBack(SLNode** pphead)
{
	//βɾ
	//1������Ϊ�ա�2��һ�����.3�����


	if (*pphead == NULL)
	{
		return;
	}
	else
		if ((*pphead)->next == NULL)
		{
			SLNode* sur = *pphead;
			//��ͷ������һ����ַ��ֵ��ͷָ��
			*pphead = NULL;
			//�ͷ�ͷ���ռ�
			free(sur);
		}
		else
		{
			SLNode* sur = *pphead;
			//����
			while (sur->next->next != NULL)
			{
				sur = sur->next;
			}
			SLNode* tail = sur->next;
			//β����ǰһ������next���ÿ�
			sur->next = NULL;
			free(tail);
		}
}

//����ֵx
SLNode* SListFind(SLNode* phead, DataType x)
{
	if (phead == NULL)
	{
		printf("SingleList is empty\n");
		return NULL;
	}
	else
	{
		SLNode* sur = phead;
		while (sur->data != x&&sur->next!=NULL)
		{
			sur = sur->next;
		}
		if (sur->data == x)
		{
			return sur;
		}
		else
			return NULL;
		
	}
}

// ��pos��ǰ�����x
void SListInsert(SLNode** pphead, SLNode* pos, DataType x)
{
	
	if (*pphead == pos)
	{
		SListPopFront(&pos, x);
	}
	else
	{
		SLNode* sur = *pphead;
		while (sur->next != pos && sur->next != NULL)
		{
			sur = sur->next;
		}
		if (sur->next == pos)
		{
			SLNode* new = CreatSLNode(x);
			sur->next = new;
			new->next = pos;
		}
		else
		{
			printf("�����ڸý��\n");
		}
	}
}
// ɾ��posλ�õ�ֵ
void SListErase(SLNode** pphead, SLNode* pos)
{
	
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLNode* sur = *pphead;
		while (sur->next != pos && sur->next != NULL)
		{
			sur = sur->next;
		}
		//�ҵ�pos��㣬ִ��ɾ������
		if (sur->next == pos)
		{
			sur->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}

//�ݻ�����
void DestorySList(SLNode* phead)
{
	if (phead == NULL)
		return;
	while (phead!=NULL&&phead->next != NULL)
	{
		SLNode* sur = phead->next;
		free(phead);
		phead = sur;
	}
}