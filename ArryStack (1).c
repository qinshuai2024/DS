#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//初始化栈
void InitStack(ST* ps)
{
	//最初设置栈的容量为4，不够后续再扩充
	ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->data == NULL)
	{
		printf("malloc fail!\n");
		return;
	}
	ps->maxsize = 4;
	ps->top = -1;//最初top指向第一个元素的前一个位置
}

//判断栈是否为空
bool IsEmptyStack(ST* ps)
{
	if (ps->top == -1)
		return true;
	else
		return false;
}

//判断是否栈满
bool IsFullStack(ST* ps)
{
	if (ps->top == ps->maxsize - 1)
		return true;
	else
		return false;
}

//获取栈顶元素
STDataType GetTop(ST* ps)
{
	return ps->data[ps->top];
}

//入栈
void PushStack(ST* ps, STDataType x)
{
	if (IsFullStack(ps))
	{
		
		//如果满了就扩容
		//扩大为原来的两倍
		STDataType* new = (STDataType*)realloc(ps->data, sizeof(STDataType) * ps->maxsize * 2);
		if (new == NULL)
		{
			printf("realloc fail!\n");
			return;
		}
		ps->data = new;
		ps->maxsize *= 2;
	}

	ps->data[ps->top + 1] = x;
	ps->top++;
}

//出栈
void PopStack(ST* ps)
{
	if (IsEmptyStack(ps))
	{
		//栈为空则返回
		return;
	}
	else
	{
		ps->top--;
	}
}
//清空栈
void MakeEmpty(ST* ps)
{
	ps->top = -1;
}

//获得栈中元素个数
int GetSizeStack(ST* ps)
{
	return ps->top + 1;
}

//销毁栈
void DestroyStack(ST* ps)
{
	ps->top = -1;
	ps->maxsize = 0;
	free(ps->data);
}

//打印栈
void PrintStack(ST* ps)
{
	if (ps->data == NULL)
		return;
	else
	{
		for (int i = 0; i <= ps->top; i++)
		{
			printf("%d->", ps->data[i]);
		}
		printf("TOP\n");
	}
}