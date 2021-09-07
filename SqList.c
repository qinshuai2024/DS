#define _CRT_SECURE_NO_WARNINGS 1
#include"SqList.h"

//创建顺序表
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
//销毁顺序表
void Destory(SL* L)
{
	free(L->data);
	L->last = -1;
	L->MaxSize = 0;
	free(L);
}
////初始化顺序表     
//void Init(SL* L);


//计算表当前长度
int Lenth(SL* L)
{
	return L->last+1;
}

//搜索x在表中的位置，返回表项序号（下标）
int Search(int x, SL* L)
{

	for (int i = 0; i <= L->last; i++)
	{
		if (L->data[i] == x)
			return i;
	}
	return -1;
}

////定位第i个数据，返回其下标
//int Locate(int i)



//在指定位置插入元素
void Insert(int i, int x, SL* L)
{
	
	//如果表满了就扩容
	Expand(L);
	int j;
	for (j = L->last; j >= i; j--)
	{
		L->data[j + 1] = L->data[j];
	}
	L->data[i] = x;
	++(L->last);

}

//尾插
void InsertBack(int x, SL* L)
{
	//如果表满了就扩容
	Expand(L);

	L->data[L->last+1] = x;
	++(L->last);
}

//删除指定元素
void Delete(int x, SL* L)
{
	if (!IsEmpty(L))
	{
		int j = Search(x, L);
		if (j == -1)
		{
			printf("%d不存在顺序表中\n", x);
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
		printf("顺序表为空\n");
		return;
	}
}
//尾删
void DeleteBack(SL* L)
{
	if (!IsEmpty(L))
	{
		--(L->last);
	}
	else
	{
		printf("顺序表为空\n");
		return;
	}
}


//判断是否为空
bool IsEmpty(SL* L)
{
	if (L->last == -1)
		return true;
	else
		return false;
}

//判断表满
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
		//两倍增容
		DataType* new = (DataType*)realloc(L->data, 2 * (L->MaxSize) * sizeof(DataType));
		if (new)
			L->data = new;
		else
			return;
	}
	else
		return;
}

//打印顺序表内元素
void Print(SL* L)
{
	for (int i = 0; i <= L->last; i++)
	{
		if (i % 6 == 0)
			printf("\n");
		printf("%d ", L->data[i]);
	}
}

//排序（暂时针对整型）
//小到大
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