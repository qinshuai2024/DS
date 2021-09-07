#define _CRT_SECURE_NO_WARNINGS 1
#include"SqList.h"

//����˳���
SL* Creat(int maxsize)
{
	SL* L=(SL*)malloc(sizeof(SL));
	if (L == NULL)
		exit(-1);
	L->data = (DataType*)malloc(sizeof(DataType) * maxsize);
	if (L->data == NULL)
		exit(-1);
	L->last = -1;
	L->MaxSize = maxsize;
	return L;
}
//����˳���
void Destory(SL* L)
{
	free(L->data);
	L->last = -1;
	L->MaxSize = 0;
	free(L);
}
////��ʼ��˳���     
//void Init(SL* L);


//�����ǰ����
int Lenth(SL* L)
{
	return L->last+1;
}

//����x�ڱ��е�λ�ã����ر�����ţ��±꣩
int Search(int x, SL* L)
{

	for (int i = 0; i <= L->last; i++)
	{
		if (L->data[i] == x)
			return i;
	}
	return -1;
}

////��λ��i�����ݣ��������±�
//int Locate(int i)



//��ָ��λ�ò���Ԫ��
void Insert(int i, int x, SL* L)
{
	
	//��������˾�����
	Expand(L);
	int j;
	for (j = L->last; j >= i; j--)
	{
		L->data[j + 1] = L->data[j];
	}
	L->data[i] = x;
	++(L->last);

}

//β��
void InsertBack(int x, SL* L)
{
	//��������˾�����
	Expand(L);

	L->data[L->last+1] = x;
	++(L->last);
}

//ɾ��ָ��Ԫ��
void Delete(int x, SL* L)
{
	if (!IsEmpty(L))
	{
		int j = Search(x, L);
		if (j == -1)
		{
			printf("%d������˳�����\n", x);
			return;
		}
		for (; j < L->last; j++)
		{

			L->data[j ] = L->data[j+1];
		}
		--(L->last);
	}
	else
	{
		printf("˳���Ϊ��\n");
		return;
	}
}
//βɾ
void DeleteBack(SL* L)
{
	if (!IsEmpty(L))
	{
		--(L->last);
	}
	else
	{
		printf("˳���Ϊ��\n");
		return;
	}
}


//�ж��Ƿ�Ϊ��
bool IsEmpty(SL* L)
{
	if (L->last == -1)
		return true;
	else
		return false;
}

//�жϱ���
bool IsFull(SL* L)
{
	if (L->last + 1 == L->MaxSize)
		return true;
	else
		return false;
}

void Expand(SL* L)
{
	if (IsFull(L))
	{
		//��������
		DataType* new = (DataType*)realloc(L->data, 2 * (L->MaxSize) * sizeof(DataType));
		if (new)
			L->data = new;
		else
			return;
	}
	else
		return;
}

//��ӡ˳�����Ԫ��
void Print(SL* L)
{
	for (int i = 0; i <= L->last; i++)
	{
		if (i % 6 == 0)
			printf("\n");
		printf("%d ", L->data[i]);
	}
}

//������ʱ������ͣ�
//С����
void BubbleSort(SL* L)
{
	for (int i = 0; i <= L->last; i++)
	{
		for (int j = 0; j < L->last - i; j++)
		{
			if (L->data[j] > L->data[j + 1])
			{
				DataType temp = L->data[j];
				L->data[j] = L->data[j + 1];
				L->data[j + 1] = temp;
			}
		}
	}
}