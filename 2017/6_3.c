#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10000
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
void BFS(AGraph* ag, int j);
int main()
{
    AGraph* pag = (AGraph*)malloc(sizeof(AGraph));
    freopen("6_3_1.in", "r", stdin);
    scanf("%d %d", &(pag->n), &(pag->e));
    int i = 0;
	for( i = 1; i <= pag->n; i++ )
		pag->adjlist[i].firstarc = NULL;
	i = 0;
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

    for(i = 1; i <= pag->n; i++)
    {
        int j;
        for(j = 1; j <= MaxSize; j++)visit[j] = 0;
        BFS(pag, i);
        int num = 0;
        for(j = 1; j<=(pag->n); j++)
        {
            if(visit[j])
            {
                num++;
            }
        }
        printf("%d: %.2f%%\n", i, (double)num/pag->n * 100);
    }


    fclose(stdin);
    return 0;
}

void BFS(AGraph* ag, int j)
{
    int que[MaxSize];
    int front = 0;
    int rear = 0;

    visit[j] = 1;
    rear = (rear + 1) % MaxSize;
    que[rear] = j;

    int depth = 0;
    while((front != rear)&&(depth < 6))
    {
        depth++;
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
                    visit[p->adjvex] = 1;
                }
                p = p->nextarc;
            }
        }
    }
}
