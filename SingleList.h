#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>

//构建一个不带头单向链表


typedef int DataType;
typedef struct SingleListNode SLNode;
struct SingleListNode 
{
	DataType data;   //数据域
	SLNode* next;        //指针域
};

//初始化链表，返回

// 不会改变链表的头指针，传一级指针
void SListPrint(SLNode* phead);

//创建一个新的结点
SLNode* CreatSLNode(DataType x);

// 可能会改变链表的头指针，传二级指针
void SListPushBack(SLNode** pphead, DataType x);
void SListPushFront(SLNode** pphead, DataType x);
void SListPopFront(SLNode** pphead);
void SListPopBack(SLNode** pphead);

//查找值x
SLNode* SListFind(SLNode* phead, DataType x);

// 在pos的前面插入x
void SListInsert(SLNode** pphead, SLNode* pos, DataType x);
// 删除pos位置的值
void SListErase(SLNode** pphead, SLNode* pos);

//摧毁链表
void DestorySList(SLNode* phead);
