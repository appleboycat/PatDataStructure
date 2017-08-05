#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
	freopen("data_4_5.in", "r", stdin);
	List L;
	ElementType X;
	Position P, tmp;
	int N;

	L = NULL;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		L = Insert(L, X, L);
		//for (P = L; P; P = P->Next) printf("%p: %d\t", P, P->Data);
		//printf("\n");
		if (L == ERROR) printf("Wrong Answer\n");
	}
	scanf("%d", &N);
	while (N--) {
	    //Position PO;
       // for (PO = L; PO; PO = PO->Next) printf("%p: %d\t", PO, PO->Data);
		//printf("\n");


		scanf("%d", &X);
		P = Find(L, X);
        //printf("find X:%d  addr:%p\n",X,P);


		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else {
           // printf("delete: L= %p, P= %p\n",L,P);
			L = Delete(L, P);
			printf("%d is found and deleted.\n", X);
			if (L == ERROR)
				printf("Wrong Answer or Empty List.\n");
		}
	}
	L = Insert(L, X, NULL);
	if (L == ERROR) printf("Wrong Answer\n");
	else
		printf("%d is inserted as the last element.\n", X);
	P = (Position)malloc(sizeof(struct LNode));
	tmp = Insert(L, X, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	tmp = Delete(L, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	for (P = L; P; P = P->Next) printf("%d ", P->Data);
	fclose(stdin);
	return 0;
}

/* 你的代码将被嵌在这里 */
Position Find(List L, ElementType X)
{
    PtrToLNode ptr = L;
    while(ptr != NULL)
    {
        if(ptr->Data == X)
        {
            return ptr;
        }
        else
            ptr = ptr->Next;
    }
    return ERROR;
}


List Insert(List L, ElementType X, Position P)
{
    PtrToLNode tmp = NULL;
    if(!L)
    {
        if(!P)
        {
            tmp = (PtrToLNode)malloc(sizeof(struct LNode));
            tmp->Data = X;
            tmp->Next = NULL;
            L = tmp;
            return L;
        }
        else
        {
            printf("Wrong Position for Insertion\n");
            return ERROR;
        }
    }
    else
    {
        PtrToLNode ptr = L, pre = NULL ;
        if(ptr == P)
        {
            tmp = (PtrToLNode)malloc(sizeof(struct LNode));
            tmp->Data = X;
            tmp->Next = P;
            L = tmp;
            return L;
        }
        else
        {
            while( (ptr->Next)&&(ptr->Next != P) )
            {
                ptr = ptr->Next;
            }
            if(ptr->Next == P)
            {
                tmp = (PtrToLNode)malloc(sizeof(struct LNode));
                tmp->Data = X;
                tmp->Next = P;
                ptr->Next = tmp;
                return L;

            }
            else
            {
                printf("Wrong Position for Insertion\n");
                return ERROR;
            }
        }
    }
}
List Delete(List L, Position P)
{
    PtrToLNode ptr = L;
    if(!ptr || !P)
    {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    else
    {
        if(ptr == P)
        {
            L = ptr->Next;
            free(ptr);
            return L;
        }
        else
        {
            while( (ptr->Next != NULL)&&(ptr->Next != P) )
            {
                ptr = ptr->Next;
            }
            if( ptr->Next == P)
            {
                 ptr->Next = P->Next;
                 free(P);
                 return L;
            }
            else
            {
                printf("Wrong Position for Deletion\n");
                return ERROR;
            }

        }
    }
}
