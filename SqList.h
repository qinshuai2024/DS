#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int DataType;
#define MAX_SIZE 100
struct SqList
{
	DataType* data;//��̬�洢
	int MaxSize;   //�����������
	int last;      //��ǰ�Ѵ��������λ��,��-1��ʼ
};
typedef struct SqList SL;

//����˳���
SL* Creat(int maxsize);
//����˳���
void Destory(SL* L);
//��ʼ��˳���
void Init(SL* L);
//�����ǰ����
int Lenth(SL* L);

//����x�ڱ��е�λ�ã����ر�����ţ��±꣩
int Search(int x, SL* L);
////��λ��i�����ݣ��������±�
//int Locate(int i)

//��ָ��λ�ò���Ԫ��
void Insert(int i,int x, SL* L);

//β��
void InsertBack(int x, SL* L);

//�ж��Ƿ�Ϊ��
bool IsEmpty(SL* L);
//�жϱ���
bool IsFull(SL* L);
//����
void Expand(SL* L);

//ɾ��ָ��Ԫ��
void Delete(int x, SL* L);
//βɾ
void DeleteBack(SL* L);

//��ӡ˳�����Ԫ��
void Print(SL* L);

//������ʱ������ͣ�
//С����
void BubbleSort(SL* L);