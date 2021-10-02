#pragma once
#include"Queue.h"

//初始化队列
void InitQueue(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}

//判断是否为空
bool IsEmptyQueue(Queue* pq)
{
	assert(pq);
	if (pq->front == NULL)
		return true;
	else
		return false;
}

//创建新的结点
QNode* CreatQNode(QDataType x)
{
	QNode* new = (QNode*)malloc(sizeof(QNode));
	if (new == NULL)
	{
		printf("malloc fail!\n");
		return NULL;
	}
	new->data = x;
	new->next = NULL;
	return new;
}

//入队
void EnterQueue(Queue* pq, QDataType x)
{
	assert(pq);
	//两种情况
	//1.队列尾空
	//2.不为空
	if (IsEmptyQueue(pq))
	{
		//为空则队头，队尾指向相同
		pq->front = pq->rear = CreatQNode(x);
	}
	else
	{
		//不为空，将尾指针指向的结点的指针域链接下一个结点
		pq->rear->next = CreatQNode(x);
		//重新让尾指针指向最后一个元素
		pq->rear = pq->rear->next;
	}
}

//出队
void DeleteQueue(Queue* pq)
{
	assert(pq);
	//两种情况
	//1.队列尾空
	//2.不为空
	if (IsEmptyQueue(pq))
	{
		return;
	}
	else
	{
		Queue* p = pq->front;
		pq->front = pq->front->next;
		//释放队头结点
		free(p);
	}
}

//销毁队列
void DestroyQueue(Queue* pq)
{
	assert(pq);
	QNode* temp;
	//逐个删除结点
	while (pq->front != NULL)
	{
		temp = pq->front;
		pq->front = pq->front->next;

		free(temp);
		temp = NULL;
	}
}

//获取队头元素
QDataType GetFront(const Queue* pq)
{
	assert(pq);
	if (pq->front == NULL)
	{
		return -1;
	}
	else
	{
		return pq->front->data;
	}
}

//获取队尾元素
QDataType GetRear(const Queue* pq)
{
	assert(pq);
	if (pq->front == NULL)
	{
		return -1;
	}
	else
	{
		return pq->rear->data;
	}
}

//计算队列元素个数
int GetSizeQueue(const Queue* pq)
{
	assert(pq);
	QNode* p = pq->front;
	int size = 0;
	while (p != NULL)
	{
		size++;
		p = p->next;
	}
	return size;
}

//打印队列
void PrintQueue(const Queue* pq)
{
	assert(pq);
	QNode* p = pq->front;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("TOP\n");
}