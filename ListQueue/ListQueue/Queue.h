
#pragma once

//用链表实现队列
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
	//队头和队尾指针
	QNode* front;
	QNode* rear;
};
typedef struct Queue Queue;

//初始化队列
void InitQueue(Queue* pq);

//判断是否为空
bool IsEmptyQueue(Queue* pq);

//创建新的结点
QNode* CreatQNode(QDataType x);

//入队
void EnterQueue(Queue* pq, QDataType x);

//出队
void DeleteQueue(Queue* pq);

//销毁队列
void DestroyQueue(const Queue* pq);

//获取队头元素
QDataType GetFront(const Queue* pq);

//获取队尾元素
QDataType GetRear(const Queue* pq);

//计算队列元素个数
int GetSizeQueue(const Queue* pq);

//打印队列
void PrintQueue(const Queue* pq);