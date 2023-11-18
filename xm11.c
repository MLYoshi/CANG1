//插一个数(在第3个数后)，用链表
#include <stdio.h>
#include <stdlib.h>

typedef struct SHU
{
    int num;
    struct SHU* next;
}shu;

shu* Build(int n);
shu* Find(int index, shu* head);
shu* Insert(shu* head);
void FreeList(shu* head);

shu* Build(int n)
{
    shu* Pt, * prePt, * head;
    int i;

    Pt = (shu*)malloc(sizeof(shu));
    if (Pt != NULL)
    {
        scanf_s("%d", &Pt->num);
        head = Pt;
        prePt = Pt;
    }
    else
    {
        printf("fail");
        exit(0);
    }
    for (i = 1; i < n; i++)
    {
        Pt = (shu*)malloc(sizeof(shu));
        if (Pt != NULL)
        {
            scanf_s("%d", &Pt->num);
            prePt->next = Pt;
            prePt = Pt;
        }
        else
        {
            printf("fail");
            exit(0);
        }
    }
    Pt->next = NULL;
    return head;
}

shu* Find(int index, shu* head)
{
    int i = 1;
    shu *Pt = head;
    while (i < index && Pt != NULL)
    {
        Pt = Pt->next;
        i++;
    }
    return Pt;
}

shu* Insert(shu* head)
{
    int a = 3;
    shu* Pt, * prePt;
    Pt = (shu*)malloc(sizeof(shu));
    printf("输入要插入的数据x:");
    scanf_s("%d", &Pt->num);
    prePt = Find(a,head);
    if (prePt != NULL)
    {
        Pt->next = prePt->next;
        prePt->next = Pt;
    }
    else
    {
        printf("没找到");
    }
    return head;
}

int main(void)
{
    int n, i = 0;
    shu* p,*s;
    printf("输入数组几个元素。\n");
    scanf_s("%d", &n);
    printf("此链表各个结点的数据域为：");
    p = Build(n);
    s = p;
    while (i < n)
    {
        printf("%d\n", s->num);
        s = s->next;
        i++;
    }
    i = 0;
    
    p=Insert(p);
    printf("插入后链表各个结点的数据域为：");
    while (i < n+1)
    {
        printf("%4d", p->num);
        p = p->next;
        i++;
    };
    FreeList(p);
    return 0;
}


void FreeList(shu* head)
{
    shu* current = head;
    shu* next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}