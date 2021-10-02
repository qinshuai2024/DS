#pragma once

#include"Queue.h"

void test()
{
	Queue q;
	InitQueue(&q);
	EnterQueue(&q, 1);
	EnterQueue(&q, 2);
	EnterQueue(&q, 3);
	EnterQueue(&q, 4);
	EnterQueue(&q, 5);
	EnterQueue(&q, 6);
	PrintQueue(&q);

	printf("size is %d\n", GetSizeQueue(&q));
	printf("front is %d\n", GetFront(&q));
	printf("rear is %d\n", GetRear(&q));

	DeleteQueue(&q);
	DeleteQueue(&q);
	DeleteQueue(&q);
	DeleteQueue(&q);
	PrintQueue(&q);

	printf("size is %d\n", GetSizeQueue(&q));
	printf("front is %d\n", GetFront(&q));
	printf("rear is %d\n", GetRear(&q));

	DestroyQueue(&q);
}

int main()
{
	test();
	return 0;
}
