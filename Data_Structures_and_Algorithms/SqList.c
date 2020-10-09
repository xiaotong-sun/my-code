#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

typedef struct {
    int *elem;
    int length;
    int listsize;
}SqList;

int InitList_Sq(SqList *L) {
    //构建一个空的线性表
    L->elem = (int *) malloc (LIST_INIT_SIZE * sizeof(int));
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

int ListInsert_Sq(SqList *L, int i, int e) {
    //在顺序线性表L中的第i个位置之前插入新的元素e
    int *q, *p;
    if (i < 1 || i > (L -> length + 1)) return ERROR;
    if (L -> length >= L -> listsize) {
        int *newBase = (int *)realloc(L -> elem, (L -> listsize + LISTINCREMENT) * sizeof(int));
        if (!newBase) exit(OVERFLOW);
        L -> elem = newBase;
        L->listsize += LISTINCREMENT;
    }
    q = &(L->elem[i - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; -- p) {
        *(p + 1) = *p;
    }
    *q = e;
    ++ L->length;
    return OK;
}

int ListDelete_Sq(SqList *L, int i, int *e) {
    //在顺序线性表L中，删除第i个元素，并用e返回其值
    //i的合法值为 1 <= i <= ListLength_Sq(L)
    int *p, *q;
    if ((i < 1) || (i > L->length)) return ERROR;
    p = &(L->elem[i - 1]);
    *e = *p;
    q = L->elem + L->length - 1;
    for (++ p; p <= q; p ++) {
        *(p - 1) = *p;
    }
    -- L->length;
    return OK;
}

int main() {
    int a = 1, e = 0;
    SqList L;
    InitList_Sq(&L);
    printf("请输入线性表的数据，输入0作为结束标志:\n");
    scanf("%d", &a);
    while (a != 0 && L.length < LIST_INIT_SIZE) {//以0为结束输入的标志
        L.elem[L.length] = a;
        scanf("%d", &a);
        L.length ++;
    }
    for (int i = 0; i < L.length; ++i) {
        printf("%d ", L.elem[i]);
    }
    printf("L.listsize = %d\n", L.listsize);
    printf("请输入要插入的数:");
    scanf("%d", &e);
    ListInsert_Sq(&L, 2, e);
    printf("插入后的线性表为：\n");
    for (int i = 0; i < L.length; ++i) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    ListDelete_Sq(&L, 4, &e);
    printf("删除的数据为：%d\n", e);
    printf("删除第4个结点后的线性表为：\n");
    for (int i = 0; i < L.length; ++i) {
        printf("%d ", L.elem[i]);
    }
    return 0;
}