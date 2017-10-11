#include<stdio.h>
#include<stdlib.h>
#define MaxSize 11
typedef struct ArcNd
{
    int adjvex;
    struct ArcNd* nextarc;
}ArcNode;
typedef struct
{
    //char data;
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

    AGraph* pag = (AGraph*)malloc(sizeof(AGraph));
    printf("sizeof(AGraph) %d\n",sizeof(AGraph));
    freopen("6_3.in", "r", stdin);
    scanf("%d %d", &(pag->n), &(pag->e));
    int i = 0;
	for( i = 1; i <= pag->n; i++ )
		pag->adjlist[i].firstarc = NULL;
	i = 0;
    while(i<(pag->e))
    {
        int s, d;
        scanf("%d %d", &s, &d);
        printf("%d %d\n", s, d);
        s;
        d;
        ArcNode* arc1 = malloc(sizeof(ArcNode));
        arc1->adjvex = d;
        arc1->nextarc = NULL;

        ArcNode* arc2 = malloc(sizeof(ArcNode));
        arc2->adjvex = s;
        arc2->nextarc = NULL;


        ArcNode** p = &(pag->adjlist[s].firstarc);
		//printf("**p %p\n", **p);

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

    i = 1;
    while(i<=(pag->n))
    {
        ArcNode* p = pag->adjlist[i].firstarc;
        printf("i %d: ", i);
        while(p)
        {
            printf(" %d", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
        i++;
    }

    for(i = 1; i <= pag->n; i++)
    {
        if(visit[i] == 0)
        {
            printf("{");
            DFS(pag, i);
            printf(" }\n");
        }
    }
    //for(i = 1; i <= MaxSize; i++)visit[i] = 0;
    //visit[] = {0};
    for(i = 1; i <= pag->n; i++)
    {
        //printf("¡¾%d¡¿-----\n", i);
        int j;
        for(j = 1; j <= MaxSize; j++)visit[j] = 0;
        BFS(pag, i);
        int num = 0;
        for(j = 1; j<=(pag->n); j++)
        {
            if(visit[j])
            {
                //printf("%d ",j);
                num++;
            }
        }
        printf("%d: %.2f%%\n", i, (float)num/10 * 100);

        //printf("-----\n");
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

    //printf(" %d", j);
    visit[j] = 1;
    rear = (rear + 1) % MaxSize;
    que[rear] = j;

    int depth = 0;


    int qsize = 0;
    // (rear - front + MaxSize) % MaxSize;
    //printf("qsize %d\n", qsize);
    while((front != rear)&&(depth < 6))
    {
        depth++;
        //printf("depth:%d\n", depth);
        int num = (rear - front + MaxSize) % MaxSize;

        while(num--)
        {
            front = (front + 1) % MaxSize;
            int k = que[front];
            ArcNode* p = ag->adjlist[k].firstarc;
            while(p != NULL)
            {
                if(visit[p->adjvex] == 0)
                {
                    rear = (rear+1)%MaxSize;
                    que[rear] = p->adjvex;
                    //printf("       eque %d\n", p->adjvex);
                    visit[p->adjvex] = 1;
                }
                p = p->nextarc;

            }
        }
    }
}
