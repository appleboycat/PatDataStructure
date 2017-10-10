#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */
/***没有头结点***/
List Reverse( List L );

int main()
{
	freopen("data.in", "r", stdin);
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
	fclose(stdin);
    return 0;
}

List Read()
{
	int N=0;
	PtrToNode L = malloc(sizeof(struct Node)); 
	PtrToNode pre = L,p = NULL;
	scanf("%d\n",&N);	
	scanf("%d",&(L->Data));
	for(int i=1;i<N;i++)
	{
		p=malloc(sizeof(struct Node));
		scanf("%d",&(p->Data));
		p->Next = NULL;
		pre->Next = p;	
		pre = pre->Next;
	}
	return L;
}
void Print( List L ) 
{
	while(L!=NULL)
	{
		printf("%d ",L->Data);
		L = L->Next;
	}
	printf("\n");
}
/* 你的代码将被嵌在这里 */
List Reverse( List L )
{
	List R = malloc(sizeof(struct Node));
	R->Next = NULL;
	PtrToNode r = R, l = L;	
	while(l!=NULL)
	{
//		printf("zhd l->data=%d\n",l->Data);
//		printf("L:");Print(L);
//		printf("R:");Print(R);

		r = R->Next;
		R->Next = l;
		l = l->Next;
		R->Next->Next = r;
		r = R->Next;
	}
	r = R;
	R = R->Next;
	free(r);
	return R;	
}

