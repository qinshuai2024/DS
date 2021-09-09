#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

// 不会改变链表的头指针，传一级指针
void SListPrint(SLNode* phead)
{
	SLNode* sur = phead;//用来遍历
	while (sur != NULL)
	{
		printf("%d->", sur->data);
		sur = sur->next;
	}
	printf("NULL\n");
}

//创建一个新的结点
SLNode* CreatSLNode(DataType x)
{
	SLNode* NewNode = (SLNode*)malloc(sizeof(SLNode));
	if (NewNode == NULL)
		exit(-1);
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

// 可能会改变链表的头指针，传二级指针
void SListPushBack(SLNode** pphead, DataType x)
{
	//尾插
	//1、链表为空。2、链表不为空

	SLNode* new = CreatSLNode(x);
	if (*pphead == NULL)
	{
		//将创建的第一个结点赋值给头指针
		*pphead = new;
	}
	else
	{
		//寻找链表的尾
		SLNode* sur = *pphead;
		while(sur->next!=NULL)
		{
			sur = sur->next;
		}
		//链接
		sur->next = new;
	}
}
void SListPushFront(SLNode** pphead, DataType x)
{
	//头插
	//1、链表为空。2、链表不为空
	SLNode* new = CreatSLNode(x);
	if (*pphead == NULL)
	{
		//将创建的第一个结点赋值给头指针
		*pphead = new;
	}
	else
	{
		//链接
		new->next = *pphead;
		//将新插入的结点指针赋给头指针
		*pphead = new;
	}

}
void SListPopFront(SLNode** pphead)
{
	//头删
	//1、链表为空。2、链表只有一个结点

	if (*pphead == NULL)
	{
		printf("SingleList is empty\n");
		return;
	}
	else
	{
		SLNode* sur = *pphead;
		//将头结点的下一个地址赋值给头指针
		*pphead = sur->next;
		//释放头结点空间
		free(sur);
	}
}
void SListPopBack(SLNode** pphead)
{
	//尾删
	//1、链表为空。2、一个结点.3、多个


	if (*pphead == NULL)
	{
		return;
	}
	else
		if ((*pphead)->next == NULL)
		{
			SLNode* sur = *pphead;
			//将头结点的下一个地址赋值给头指针
			*pphead = NULL;
			//释放头结点空间
			free(sur);
		}
		else
		{
			SLNode* sur = *pphead;
			//查找
			while (sur->next->next != NULL)
			{
				sur = sur->next;
			}
			SLNode* tail = sur->next;
			//尾结点的前一个，的next域置空
			sur->next = NULL;
			free(tail);
		}
}

//查找值x
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

// 在pos的前面插入x
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
			printf("不存在该结点\n");
		}
	}
}
// 删除pos位置的值
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
		//找到pos结点，执行删除操作
		if (sur->next == pos)
		{
			sur->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}

//摧毁链表
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