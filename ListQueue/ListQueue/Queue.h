
#pragma once

//������ʵ�ֶ���
#include<stdio.h>
#include<stdbool.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;
struct QNode
{
	QDataType data;
	struct QNode* next;
};
typedef struct QNode QNode;

struct Queue
{
	//��ͷ�Ͷ�βָ��
	QNode* front;
	QNode* rear;
};
typedef struct Queue Queue;

//��ʼ������
void InitQueue(Queue* pq);

//�ж��Ƿ�Ϊ��
bool IsEmptyQueue(Queue* pq);

//�����µĽ��
QNode* CreatQNode(QDataType x);

//���
void EnterQueue(Queue* pq, QDataType x);

//����
void DeleteQueue(Queue* pq);

//���ٶ���
void DestroyQueue(const Queue* pq);

//��ȡ��ͷԪ��
QDataType GetFront(const Queue* pq);

//��ȡ��βԪ��
QDataType GetRear(const Queue* pq);

//�������Ԫ�ظ���
int GetSizeQueue(const Queue* pq);

//��ӡ����
void PrintQueue(const Queue* pq);