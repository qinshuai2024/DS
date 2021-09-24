#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"


void test()
{
	SNode* stack = NULL;
	PushStack(&stack, 1);
	PushStack(&stack, 2);
	PushStack(&stack, 3);
	PushStack(&stack, 4);
	PushStack(&stack, 5);
	PushStack(&stack, 6);
	PrintStack(stack);

	printf("TOP IS %d\n", GetTop(stack));
	printf("SIZE IS %d\n", GetSize(stack));

	PopStack(&stack); 
	PopStack(&stack);
	PopStack(&stack);
	printf("After the change :TOP IS %d\n", GetTop(stack));
	printf("After the change :SIZE IS %d\n", GetSize(stack));
	PrintStack(stack);


	MakeEmpty(stack);
	
}

int main()
{
	test();
	return 0;
}