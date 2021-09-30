#pragma once
#include"Stack.h"

void test()
{
	ST s;
	InitStack(&s);
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	PushStack(&s, 4);
	PushStack(&s, 5);
	PushStack(&s, 6);
	PrintStack(&s);
	printf("top is %d\n", GetTop(&s));
	printf("size is %d\n", GetSizeStack(&s));

	PopStack(&s);
	PopStack(&s);
	PopStack(&s);
	PopStack(&s);
	PrintStack(&s);
	printf("top is %d\n", GetTop(&s));
	printf("size is %d\n", GetSizeStack(&s));
	DestroyStack(&s);

}
int main()
{
	test();

	return 0;
}