#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    freopen("data_4_6.in", "r", stdin);
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    fclose(stdin);
    return 0;
}
/* 你的代码将被嵌在这里 */
List MakeEmpty()
{
    PtrToLNode tmp = (PtrToLNode)malloc(sizeof(struct LNode));
    tmp->Next = NULL;
    return tmp;
}
Position Find( List L, ElementType X )
{
    if(L == NULL)
    {
        return ERROR;
    }

    PtrToLNode ptr = L->Next;
    while(ptr!= NULL){
        if(ptr->Data == X)
        {
            return ptr;
        }
        ptr = ptr->Next;
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P )
{
    if(L == NULL)
    {
        printf("Wrong Position for Insertion\n");
        return false;
    }

    PtrToLNode ptr = L;
    while( (ptr->Next != NULL)&&(ptr->Next != P) )
    {
        ptr = ptr->Next;
    }
    if( ptr->Next == P)
    {
        PtrToLNode tmp = (PtrToLNode)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        ptr->Next = tmp;
        return true;
    }
    else
    {
        printf("Wrong Position for Insertion\n");
        return false;
    }

}
bool Delete( List L, Position P )
{
    if(L == NULL)
    {
        printf("Wrong Position for Deletion\n");
        return false;
    }

    PtrToLNode ptr = L;
    while( (ptr->Next != NULL)&&(ptr->Next != P) )
    {
        ptr = ptr->Next;
    }
    if( ptr->Next == P)
    {
        PtrToLNode tmp = P;
        ptr->Next = P->Next;
        free(P);
        return true;
    }
    else
    {
        printf("Wrong Position for Deletion\n");
        return false;
    }

}
