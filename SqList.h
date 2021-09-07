#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int DataType;
#define MAX_SIZE 100
struct SqList
{
	DataType* data;//动态存储
	int MaxSize;   //最大容纳项数
	int last;      //当前已存表项的最后位置,从-1开始
};
typedef struct SqList SL;

//创建顺序表
SL* Creat(int maxsize);
//销毁顺序表
void Destory(SL* L);
//初始化顺序表
void Init(SL* L);
//计算表当前长度
int Lenth(SL* L);

//搜索x在表中的位置，返回表项序号（下标）
int Search(int x, SL* L);
////定位第i个数据，返回其下标
//int Locate(int i)

//在指定位置插入元素
void Insert(int i,int x, SL* L);

//尾插
void InsertBack(int x, SL* L);

//判断是否为空
bool IsEmpty(SL* L);
//判断表满
bool IsFull(SL* L);
//扩容
void Expand(SL* L);

//删除指定元素
void Delete(int x, SL* L);
//尾删
void DeleteBack(SL* L);

//打印顺序表内元素
void Print(SL* L);

//排序（暂时针对整型）
//小到大
void BubbleSort(SL* L);