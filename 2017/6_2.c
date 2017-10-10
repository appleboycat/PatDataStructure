#include <stdio.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10   /* 最大顶点数设为10 */
typedef int Vertex;       /* 用顶点下标表示顶点,为整型 */

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;        /* 邻接点下标 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MaxVertexNum];     /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

LGraph CreateGraph(); /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) );

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}

/* 你的代码将被嵌在这里 */
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    int que[MaxVertexNum];
    int front = 0;
    int rear = 0;

    Visit(S);Visited[S] = 1;
    rear = (rear+1) % MaxVertexNum;que[rear] = S;
    while(front != rear)
    {
        front = (front+1) % MaxVertexNum;
        int k = que[front];
        PtrToAdjVNode p = Graph->G[k].FirstEdge;
        while(p != NULL)
        {
            if(Visited[p->AdjV] == 0)
            {
                Visit(p->AdjV);Visited[p->AdjV] = 1;
                rear = (rear+1) % MaxVertexNum;que[rear] = p->AdjV;
            }
            p = p->Next;
        }
    }
}
