#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct ArcNd
{
    int adjvex;
    struct ArcNd* nextarc;
}ArcNode;

typedef struct
{
    struct ArcNd* firstarc;
}VNode;
typedef struct
{
    int n,e;
    VNode adjlist[MaxSize];
}AGraph;

static int visit[MaxSize] = {0};
void DFS(AGraph* ag, int j);
void BFS(AGraph* ag, int j);

int main()
{
    freopen("6_input.txt", "r", stdin);
    AGraph* pag = (AGraph*)malloc(sizeof(AGraph));
    scanf("%d %d", &(pag->n), &(pag->e));
    int i = 0;
    while(i<(pag->e))
    {
        int s, d;
        scanf("%d %d", &s, &d);
        ArcNode* arc1 = malloc(sizeof(ArcNode));
        arc1->adjvex = d;
        arc1->nextarc = NULL;

        ArcNode* arc2 = malloc(sizeof(ArcNode));
        arc2->adjvex = s;
        arc2->nextarc = NULL;

        ArcNode** p = &(pag->adjlist[s].firstarc);
        if(*p == NULL)
        {
            *p = arc1;
        }
        else
        {
            ArcNode* pre = *p;
            ArcNode* tmp = *p;
            if( arc1->adjvex < tmp->adjvex )
            {
                arc1->nextarc = *p;
                *p = arc1;
            }
            else
            {
                while((tmp != NULL) && (arc1->adjvex > tmp->adjvex))
                {
                    pre = tmp;
                    tmp = tmp->nextarc;
                }
                pre->nextarc = arc1;
                arc1->nextarc = tmp;
            }
        }

        p = &(pag->adjlist[d].firstarc);
        if(*p == NULL)
        {
            *p = arc2;
        }
        else
        {
            ArcNode* pre = *p;
            ArcNode* tmp = *p;
            if( arc2->adjvex < tmp->adjvex )
            {
                arc2->nextarc = *p;
                *p = arc2;
            }
            else
            {
                while((tmp != NULL) && (arc2->adjvex > tmp->adjvex))
                {
                    pre = tmp;
                    tmp = tmp->nextarc;
                }
                pre->nextarc = arc2;
                arc2->nextarc = tmp;
            }
        }

        i++;
    }

    /*i = 0;
    while(i<(pag->n))
    {
        ArcNode* p = pag->adjlist[i].firstarc;
        while(p)
        {
            printf("%d\n", p->adjvex);
            p = p->nextarc;
        }
        i++;
    }*/

    for(i = 0; i<pag->n; i++)
    {
        if(visit[i] == 0)
        {
            printf("{");
            DFS(pag, i);
            printf(" }\n");
        }
    }
    for(i = 0; i<MaxSize; i++)visit[i] = 0;
    for(i = 0; i<pag->n; i++)
    {
        if(visit[i] == 0)
        {
            printf("{");
            BFS(pag, i);
            printf(" }\n");
        }
    }


    fclose(stdin);
    return 0;
}

void DFS(AGraph* ag, int j)
{
    visit[j] = 1;
    printf(" %d", j);
    ArcNode* p = ag->adjlist[j].firstarc;
    while(p != NULL)
    {
        if(visit[p->adjvex] == 0)
        {
            DFS(ag, p->adjvex);
        }
        p = p->nextarc;
    }
}
void BFS(AGraph* ag, int j)
{
    int que[MaxSize];
    int front = 0;
    int rear = 0;

    printf(" %d", j);
    visit[j] = 1;
    rear = (rear+1)%MaxSize;
    que[rear] = j;

    while(front != rear)
    {
        front = (front+1)%MaxSize;
        int k = que[front];
        ArcNode* p = ag->adjlist[k].firstarc;
        while(p != NULL)
        {
            if(visit[p->adjvex] == 0)
            {
                rear = (rear+1)%MaxSize;
                que[rear] = p->adjvex;
                printf(" %d", p->adjvex);
                visit[p->adjvex] = 1;
            }

            p = p->nextarc;
        }
    }

}
