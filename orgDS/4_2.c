#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );
void Print( List L ); 

int main()
{
	freopen("data.in", "r", stdin);
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
	printf("-----------------------print:\n");Print(L);
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
		printf("zhd Insert(L,X,0) =(L,%d,0)\n",X); 
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
	printf("-----------------------print:\n");Print(L);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
		printf("zhd Find(L,X) =(L,%d)\n",X); 
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
	printf("-----------------------print:\n");Print(L);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
		printf("zhd Delete(L,P) =(L,%d)\n",P); 
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
		printf("--print:\n");Print(L);
		printf("zhd Insert(L,0,P) =(L,0,%d)\n",P); 
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
		printf("-----------------------print:\n");Print(L);

    }
	fclose(stdin);
    return 0;
}

/* ������Ƕ */
List MakeEmpty()
{
	List L = malloc(sizeof(struct LNode));	
	L->Last = -1;
	return L;
}
Position Find( List L, ElementType X )
{
	int i = 0;
	if( L->Last != -1 )
	while( i <= L->Last ) 
	{
		if( X == L->Data[i] )
			return i;
		i++;
	}	
	return ERROR;
}

bool Insert( List L, ElementType X, Position P )
{
	if(L->Last == (MAXSIZE-1))
	{
		printf("FULL");
		return false;
	}else if( P<0 || (P>L->Last+1) ) 
	{
		printf("ILLEGAL POSITION");
		return false;
	
	}else
	{
		int last = L->Last;
		int i;
		for(i = last; i >= P; i--)
			L->Data[i+1] = L->Data[i];
		L->Data[P] = X;
		L->Last ++;
		return true;
	}
}
bool Delete( List L, Position P )
{
	if(P<0 || P>=MAXSIZE || L->Last!=-1&&P>L->Last || L->Last == -1)
	{
		printf("POSITION %d EMPTY",P);
		return false;
	}else
	{
		int i;
		for(i = P; i < L->Last; i++)
			L->Data[i] = L->Data[i+1];
		L->Last --;
		return true;
	} 
}
void Print( List L )
{
	int i = 0;
	printf("---L->Last = %d\n", L->Last);
	while( i <= L->Last )
	{
		printf("--Data[%d]=%d\n",i,L->Data[i]);
		i++;
	}
}
