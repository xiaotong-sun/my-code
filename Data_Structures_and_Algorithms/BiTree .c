#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 100

//二叉树的二叉链表储存结构
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//栈的储存结构
typedef struct {
    BiTree base;
    BiTree top;
    int stacksize;
} SqStack;

//利用带终止符的线序序列构建二叉树
int CreateBiTree(BiTree *T) {  //利用二级指针传参，因为在这个函数中需要改变一级指针的指向，如果不用二级指针就相当于一级指针的值传递，不能改变指针的指向。
    char ch;
    scanf("%c", &ch);
    if (ch == ' ') *T = NULL;
    else {
        if (!*T) exit(OVERFLOW);
        (*T)->data = ch;
        (*T)->lchild = (BiTree)malloc(sizeof(BiTNode));
        if (!(*T)->lchild) exit(OVERFLOW);
        (*T)->rchild = (BiTree)malloc(sizeof(BiTNode));
        if (!(*T)->rchild) exit(OVERFLOW);
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
        }
    return OK;
}

int PrintElement(char e) {
    printf("%c ", e);
    return OK;
}

//初始化一个空栈
int InitStack(SqStack *S) {
    S->base = (BiTree)malloc(STACK_INIT_SIZE * sizeof(BiTNode));
    if (!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//判断一个栈是否为空栈
int StackEmpty(SqStack S) {
    if (S.base == S.top) return 1;
    return 0;
}

//将数据压入栈中
int Push(SqStack *S, BiTree p) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (BiTree)realloc(S->base, (S->stacksize + 50) * sizeof(BiTNode));
        if (!S->base) exit(OVERFLOW);
        S->top = S->base + S->stacksize;
        S->stacksize += 50;
    }
    * S->top ++ = *p;
    return OK;
}

//栈顶数据出栈
int Pop(SqStack *S, BiTree *p) {
    if (S->top== S->base) return ERROR;
    *p = --(S->top);
    return OK;
}

//（非递归）的中序遍历
int InOrderTraverse(BiTree T) {
    SqStack S;
    BiTree p = T;
    BiTree *p1 = &p;
    InitStack(&S);
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(&S,p);
            p = p->lchild;
        } else {
            Pop(&S,p1);
            if (!PrintElement(p->data)) return ERROR;
            p = p->rchild;
        }
    }
    return OK;
}

//（递归）的先序遍历
int PreOrder(BiTree T) {
    if (T) {
        PrintElement(T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    return OK;
}

//（递归）的后序遍历
int PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        PrintElement(T->data);
    }
    return OK;
}

int InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        PrintElement(T->data);
        InOrder(T->rchild);
    }
    return OK;
}

int main() {
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    BiTree *T1 = &T;
    CreateBiTree(T1);
    printf("非递归的中序遍历结果为：\n");
    InOrderTraverse(T);
    printf("\n递归的先序遍历结果为：\n");
    PreOrder(T);
    printf("\n递归的后序遍历结果为：\n");
    PostOrder(T);
    printf("\n递归的中序遍历结果为：\n");
    InOrder(T);
    return 0;
}
