#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

void CreatList_L(LinkList L, int n) {
    //逆位序输入n个元素的值，建立带表头结点的单链线性表L
    LinkList p;
    L -> next = NULL;
    printf("依次输入元素值：\n");
    for (int i = n; i > 0; --i) {
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &(p -> data));
        p->next = L->next;
        L->next = p;
    }
}

void PrintList_L(LinkList L, int n) {
    //顺序打印链表
    LinkList q = L;
    for (int i = n; i > 0; --i) {
        q = q->next;
        printf("%d ", q->data);
    }
    printf("\n");
}

int ListInsert_L(LinkList L, int i, int e) {
    //在第i个位置之前插入元素e
    LinkList p = L;
    int j = 0;
    while (p && j < i -1) {//寻找第i-1个结点
        p = p->next;
        ++ j;
    }
    if (!p || j > i -1) {
        return ERROR;
    }
    LinkList s = (LinkList) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

int ListDelete_L(LinkList L, int i, int *e) {
//删除第i个元素，并由e返回其值
    LinkList p = L;
    int j = 0;
    while (p->next && j < i - 1) {//寻找第i个结点，并令p指向其前驱
        p = p->next;
        j ++;
    }
    if (!p->next && j >= i - 1) {
        return ERROR;
    }
    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

int main() {
    int n;
    LinkList L = (LinkList) malloc (sizeof(LNode));
    printf("请输入元素的个数n:\n");
    scanf("%d", &n);
    CreatList_L(L, n);
    PrintList_L(L, n);
    printf("在第3个位置之前插入23\n");
    ListInsert_L(L, 3, 23);
    PrintList_L(L, n + 1);
    printf("删除第二个元素，并输出其值\n");
    int *e;
    ListDelete_L(L, 2, e);
    printf("%d\n", *e);
}
