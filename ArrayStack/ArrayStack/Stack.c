#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//��ʼ��ջ
void InitStack(ST* ps)
{
	//�������ջ������Ϊ4����������������
	ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->data == NULL)
	{
		printf("malloc fail!\n");
		return;
	}
	ps->maxsize = 4;
	ps->top = -1;//���topָ���һ��Ԫ�ص�ǰһ��λ��
}

//�ж�ջ�Ƿ�Ϊ��
bool IsEmptyStack(ST* ps)
{
	if (ps->top == -1)
		return true;
	else
		return false;
}

//�ж��Ƿ�ջ��
bool IsFullStack(ST* ps)
{
	if (ps->top == ps->maxsize - 1)
		return true;
	else
		return false;
}

//��ȡջ��Ԫ��
STDataType GetTop(ST* ps)
{
	return ps->data[ps->top];
}

//��ջ
void PushStack(ST* ps, STDataType x)
{
	if (IsFullStack(ps))
	{
		
		//������˾�����
		//����Ϊԭ��������
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

//��ջ
void PopStack(ST* ps)
{
	if (IsEmptyStack(ps))
	{
		//ջΪ���򷵻�
		return;
	}
	else
	{
		ps->top--;
	}
}
//���ջ
void MakeEmpty(ST* ps)
{
	ps->top = -1;
}

//���ջ��Ԫ�ظ���
int GetSizeStack(ST* ps)
{
	return ps->top + 1;
}

//����ջ
void DestroyStack(ST* ps)
{
	ps->top = -1;
	ps->maxsize = 0;
	free(ps->data);
}

//��ӡջ
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