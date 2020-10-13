#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct {
    int *base;
    int *top;
    int stacksize;
}SqStack;

int InitStack(SqStack *S) {
    //构造一个空栈
    S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

int Push(SqStack *S, int e) {
    //插入元素e为新的栈顶元素
    if(S->top - S->base >= S->stacksize) {//栈满，追加存储空间
        S->base = (int *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(int));
        if (!S->base) exit(OVERFLOW);
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top ++) = e;
    return OK;
}

int Pop(SqStack *S, int *e) {
    //若栈不空，删除栈顶元素，用e返回其值，并返回ok，否则返回error。
    if(S->top == S->base) {//判断栈空
        return ERROR;
    }
    *e = * (-- S->top);
    return OK;
}

int main() {
    SqStack S;
    InitStack(&S);
    int a = 0, b = 0;
    printf("请输入一个十进制数：\n");
    scanf("%d", &a);
    while (a) {
        b = a % 16;
        if (b >= 10) {
            b = 87 + b;
        }
        Push(&S, b);
        a /= 16;
    }
    while (S.top != S.base){
        int *e;
        Pop(&S, e);
        if (*e >= 97) {
            printf("%c", *e);
        } else {
            printf("%d", *e);
        }
    }
    return 0;
}