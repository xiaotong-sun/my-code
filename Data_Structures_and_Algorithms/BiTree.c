#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100

//二叉树的二叉链表储存表示
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct {
    BiTree base;
    BiTree top;
    int stacksize;
} SqStack;

int CreateBiTree(BiTree T) {
    char ch;
    scanf("%c", &ch);
    if (ch == ' ') T = NULL;
    else {
        if (!T) exit(OVERFLOW);
        T->data = ch;
        T->lchild = (BiTree)malloc(sizeof(BiTNode));
        if (!T->lchild) exit(OVERFLOW);
        T->rchild = (BiTree)malloc(sizeof(BiTNode));
        if (!T->rchild) exit(OVERFLOW);
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
        }
    printf("aaaa\n");
    return OK;
}

int PrintElement(char e) {
    printf("%c ", e);
    return OK;
}

int InitStack(SqStack *S) {
    S->base = (BiTree)malloc(STACK_INIT_SIZE * sizeof(BiTNode));
    if (!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

int StackEmpty(SqStack S) {
    if (S.base == S.top) return 1;
    return 0;
}

int Push(SqStack *S, BiTree p) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (BiTree)realloc(S->base, (S->stacksize + 50) * sizeof(BiTNode));
        if (!S->base) exit(OVERFLOW);
        S->top = S->base + S->stacksize;
        S->stacksize += 50;
    }
    * S->top ++ = *p;//????????????
    return OK;
}

int Pop(SqStack *S, BiTree p) {
    if (S->top == S->base) return ERROR;
    *p = * --S->top;
    return OK;
}

int InOrderTraverse(BiTree T) {
    SqStack S;
    BiTree p = T;
    InitStack(&S);
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(&S,p);
            p = p->lchild;
        } else {
            Pop(&S,p);
            if (!PrintElement(p->data)) return ERROR;
            p = p->rchild;
        }
    }
    return OK;
}


int main() {
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    CreateBiTree(T);
    InOrderTraverse(T);
}
