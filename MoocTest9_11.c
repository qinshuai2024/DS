#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>



//反转链表

typedef int ElemType;
typedef struct Node
{
    ElemType element;
    struct Node* link;
}Node;

typedef struct SingleList
{
    struct Node* first;
    int n;
}SingleList;

void Invert(SingleList* L)
{
    //定义两个变量用来交换两个结点的指向
    Node* p = L->first, * q;
    //L->first存放前一个要交换的结点的地址，第一个结点为NULL
    L->first = NULL;

    //相当于三个结点的操作L->first,p,q
    while (p != NULL)
    {
        q = p->link;        //先将q指向p的下一个结点
        p->link = L->first; //将上一个结点的地址放入现结点的link域
        L->first = p;       //指向现结点
        p = q;              //往后遍历
    }
}

//创建结点
Node* CreatNode(ElemType x)
{
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL)
    {
        exit(-1);
    }
    new->element = x;
    new->link = NULL;

    return new;
}

//尾插
void PushBack(SingleList* L, int x)
{
    Node* new = CreatNode(x);
    if (L->first == NULL)
    {
        L->first = new;
        (L->n)++;
    }
    else
    {
        Node* sur = L->first;
        while (sur->link)
            sur = sur->link;
        sur->link = new;
        (L->n)++;
    }

}

//打印链表
void PrintSList(SingleList* L)
{
    if (L->first == NULL)
        return;
    Node* temp = L->first;
    while (temp)
    {
        printf("%d->", temp->element);
        temp = temp->link;
    }
    printf("NULL\n");
}


//摧毁链表
void DestorySList(SingleList* L)
{
    if (L->first == NULL)
        return;
    Node* temp = L->first;
    while (temp != NULL)
    {
        Node* ttemp = temp->link;
        free(temp);
        temp = ttemp->link;
    }
}

void test()
{
    SingleList slist;
    slist.n = 0;
    slist.first = NULL;


    PushBack(&slist, 1);
    PushBack(&slist, 2);
    PushBack(&slist, 3);
    PushBack(&slist, 4);
    PushBack(&slist, 5);
    PushBack(&slist, 6);

    PrintSList(&slist);


    Invert(&slist);
    PrintSList(&slist);

    DestorySList(&slist);
}
int main()
{
    test();
    return 0;

}

‍