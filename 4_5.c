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
	freopen("data4_5.in", "r", stdin);
	List L;
	ElementType X;
	Position P, tmp;
	int N;

	L = NULL;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		L = Insert(L, X, L);
		if (L == ERROR) printf("Wrong Answer\n");
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else {
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
	getchar();
	system("pause");
	return 0;
}

/* 你的代码将被嵌在这里 */
Position Find(List L, ElementType X)
{

	return L;
}
List Insert(List L, ElementType X, Position P)
{
	if (L == NULL)
	{
		if (P != NULL)
		{
			printf("Wrong Position for Insertion\n");
			return ERROR;
		}
		else
		{
			PtrToLNode tmp = (PtrToLNode)malloc(sizeof(struct LNode));
			tmp->Data = X;
			tmp->Next = NULL;
			return tmp;
		}
	}
	else
	{
		PtrToLNode ptr = L;
		PtrToLNode tmp = NULL;
		if (P != NULL)
		{
			while ((ptr->Next != NULL) && (ptr->Next != P))ptr = ptr->Next;
			if (ptr->Next == P)
			{
				tmp = (PtrToLNode)malloc(sizeof(struct LNode));
				tmp->Data = X;
				tmp->Next = NULL;
				ptr->Next = tmp;
				tmp->Next = P;
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
			while (ptr->Next != NULL)ptr = ptr->Next;
			tmp = (PtrToLNode)malloc(sizeof(struct LNode));
			tmp->Data = X;
			tmp->Next = NULL;
			ptr->Next = tmp;
			return L;
		}
	}
}
List Delete(List L, Position P)
{
	return L;
}
