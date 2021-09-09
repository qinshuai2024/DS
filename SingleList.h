#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>

//����һ������ͷ��������


typedef int DataType;
typedef struct SingleListNode SLNode;
struct SingleListNode 
{
	DataType data;   //������
	SLNode* next;        //ָ����
};

//��ʼ����������

// ����ı������ͷָ�룬��һ��ָ��
void SListPrint(SLNode* phead);

//����һ���µĽ��
SLNode* CreatSLNode(DataType x);

// ���ܻ�ı������ͷָ�룬������ָ��
void SListPushBack(SLNode** pphead, DataType x);
void SListPushFront(SLNode** pphead, DataType x);
void SListPopFront(SLNode** pphead);
void SListPopBack(SLNode** pphead);

//����ֵx
SLNode* SListFind(SLNode* phead, DataType x);

// ��pos��ǰ�����x
void SListInsert(SLNode** pphead, SLNode* pos, DataType x);
// ɾ��posλ�õ�ֵ
void SListErase(SLNode** pphead, SLNode* pos);

//�ݻ�����
void DestorySList(SLNode* phead);
