#pragma once
#include"Queue.h"

//��ʼ������
void InitQueue(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
}

//�ж��Ƿ�Ϊ��
bool IsEmptyQueue(Queue* pq)
{
	assert(pq);
	if (pq->front == NULL)
		return true;
	else
		return false;
}

//�����µĽ��
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

//���
void EnterQueue(Queue* pq, QDataType x)
{
	assert(pq);
	//�������
	//1.����β��
	//2.��Ϊ��
	if (IsEmptyQueue(pq))
	{
		//Ϊ�����ͷ����βָ����ͬ
		pq->front = pq->rear = CreatQNode(x);
	}
	else
	{
		//��Ϊ�գ���βָ��ָ��Ľ���ָ����������һ�����
		pq->rear->next = CreatQNode(x);
		//������βָ��ָ�����һ��Ԫ��
		pq->rear = pq->rear->next;
	}
}

//����
void DeleteQueue(Queue* pq)
{
	assert(pq);
	//�������
	//1.����β��
	//2.��Ϊ��
	if (IsEmptyQueue(pq))
	{
		return;
	}
	else
	{
		Queue* p = pq->front;
		pq->front = pq->front->next;
		//�ͷŶ�ͷ���
		free(p);
	}
}

//���ٶ���
void DestroyQueue(Queue* pq)
{
	assert(pq);
	QNode* temp;
	//���ɾ�����
	while (pq->front != NULL)
	{
		temp = pq->front;
		pq->front = pq->front->next;

		free(temp);
		temp = NULL;
	}
}

//��ȡ��ͷԪ��
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

//��ȡ��βԪ��
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

//�������Ԫ�ظ���
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

//��ӡ����
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