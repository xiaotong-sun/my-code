#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define OVERFLOW -2
#define ERROR -3
#define INFINITY 10000       //最大值
#define MAX_VERTEX_NUM 20      //最大顶点个数

//--------- 图的数组（邻接矩阵）储存表示----------
typedef enum {
    DG, DN, UDG, UDN    //{有向图，有向网，无向图，无向网}
} GraphKind;

typedef struct ArcCell {
    int adj;            //权值
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    char vexs[MAX_VERTEX_NUM];       //顶点向量
    AdjMatrix arcs;                   //邻接矩阵
    int vexnum, arcnum;               //图的当前顶点数和弧数
    GraphKind kind;                   //图的种类标志
} MGraph;

//---------采用邻接矩阵表示法构造无向图----------
int LocateVex(char *vexs, char v) {     //确定一个顶点的位置，并返回该位置
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        if (v == vexs[i]) {
            return i;
        }
    }
    return 0;
}

int CreatUDG(MGraph *G) {       //创建无向图
    printf("请输入节点个数及弧的个数:");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    getchar();
    printf("请输入顶点信息：");
    for (int i = 0; i < G->vexnum; ++i) {       //构造顶点向量
        scanf("%c", &G->vexs[i]);
        getchar();
    }
    for (int i = 0; i < G->vexnum; ++i) {       //初始化邻接数组
        for (int j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = INFINITY;
        }
    }
    printf("请输入弧对应的两个顶点v1,v2和权值w:\n");
    getchar();
    for (int k = 0; k < G->arcnum; ++k) {       //构造邻接矩阵
        char v1, v2;
        int w;                                  // w代表权值
        //printf("请输入第%d个弧对应的两个顶点v1,v2和权值w:\n", k + 1);
        //getchar();
        scanf("%c %c %d", &v1, &v2, &w);
        getchar();
        int i = LocateVex(G->vexs, v1);
        int j = LocateVex(G->vexs, v2);
        G->arcs[i][j].adj = w;
        G->arcs[j][i] = G->arcs[i][j];          //置<v1,v2>的对称弧<v2,v1>
    }
    return OK;
}

//---------深度优先搜索--------
int visited[MAX_VERTEX_NUM];    //访问标志数组，1为访问，0为未访问

void VisitFunc(int v, char *vexs) {     //访问节点
    printf("%c ", vexs[v]);
}

int FirstAdjVex(MGraph *G, int v) {        //某节点的第一个邻接节点
    for (int i = 0; i < G->vexnum; ++i) {
        if (G->arcs[v][i].adj != INFINITY) {
            return i;
        }
    }
}

int NextAdjVex(MGraph *G, int v, int w) {   //某节点邻接节点的下一个节点
    for (int i = w + 1; i < G->vexnum; ++i) {
        if (G->arcs[v][i].adj != INFINITY) {
            return i;
        }
    }
    return -1;
}

/*
上面的两个函数是基于邻接矩阵的特点实现的，
 让行固定，使列逐次增1，从而实现按一定顺序
 寻找某节点所有邻接点的目的。
*/

void DFS(MGraph *G, int v) {                //深度优先搜索次函数
    visited[v] = 1;
    VisitFunc(v, G->vexs);
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

void DFSTraverse(MGraph *G) {               // 深度优先搜索主函数
    for (int v = 0; v < G->vexnum; ++v) {
        visited[v] = 0;
    }
    for (int v = 0; v < G->vexnum; ++v) {
        if (!visited[v]) DFS(G, v);
    }
}

//--------广度优先搜索--------------
//---辅助队列Q-----
typedef struct QNode {
    char data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

int InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (!Q->front) exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

int EnQueue(LinkQueue *Q, char e) {         //入队列操作
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if (!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

int DeQueue(LinkQueue *Q, char *e) {        //出队列操作
    if (Q->front == Q->rear) return ERROR;
    QueuePtr p;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

//-----广度优先非递归遍历-------
void BFSTraverse(MGraph *G) {
    for (int v = 0; v < G->vexnum; ++v) {
        visited[v] = 0;
    }
    LinkQueue Q;
    InitQueue(&Q);
    for (int v = 0; v < G->vexnum; ++v) {
        if (!visited[v]) {
            visited[v] = 1;
            VisitFunc(v, G->vexs);
            EnQueue(&Q, G->vexs[v]);
            while (Q.front != Q.rear) {
                char e;
                DeQueue(&Q, &e);
                int i = LocateVex(G->vexs, e);
                for (int w = FirstAdjVex(G, i); w >= 0; w = NextAdjVex(G, i, w)) {
                    if (!visited[w]) {
                        visited[w] = 1;
                        VisitFunc(w, G->vexs);
                        EnQueue(&Q, G->vexs[w]);
                    }
                }
            }
        }
    }
}

int main() {
    MGraph G;
    CreatUDG(&G);
    printf("深度优先搜索：\n");
    DFSTraverse(&G);
    printf("\n广度优先搜索\n");
    BFSTraverse(&G);
    return 0;
}
