#define _CRT_SECURE_NO_WARNINGS 1

#include"SqList.h"
void test()
{
	SL* L = Creat(4);
	InsertBack(1, L);
	InsertBack(2, L);
	InsertBack(3, L);
	InsertBack(4, L);
	InsertBack(5, L);
	Print(L);
	Insert(3, 6, L);
	Print(L);

	Delete(2, L);
	Print(L);
	Delete(4, L); 
	Print(L);
	DeleteBack(L);
	DeleteBack(L);
	Print(L);

	InsertBack(9, L);
	InsertBack(8, L);
	InsertBack(7, L);
	InsertBack(6, L);
	BubbleSort(L);
	Print(L);
	Destory(L);
}

int main()
{
	test();
	return 0;
}