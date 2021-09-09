#define _CRT_SECURE_NO_WARNINGS 1
#include"SingleList.h"


void test1()
{
	SLNode* slist = NULL;
	SListPushFront(&slist, 1);
	SListPushFront(&slist, 2);
	SListPushFront(&slist, 3);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	SListPushBack(&slist, 6);
	SListPrint(slist);


	SListPopBack(&slist);
	SListPopBack(&slist);
	SListPopFront(&slist);
	SListPopFront(&slist);
	SListPrint(slist);
	DestorySList(slist);
}
void test2()
{
	SLNode* slist = NULL;
	SListPushFront(&slist, 3);
	SListPushFront(&slist, 2);
	SListPushFront(&slist, 1);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	SListPushBack(&slist, 6);
	SListPrint(slist);

	//相当于把4换成7
	SLNode* temp = SListFind(slist, 4);
	if (temp)
	{
		SListInsert(&slist, temp, 7);
		SListErase(&slist, temp);
	}
	SListPrint(slist);

	SLNode* temp2 = SListFind(slist, 5);
	if (temp2)
	{
		SListInsert(&slist, temp2, 8);
		SListErase(&slist, temp2);
	}
	SListPrint(slist);



	DestorySList(slist);
}
int main()
{
	//test1();
	test2();
	return 0;
}