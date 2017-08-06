#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    freopen("data_4_7.in", "r", stdin);
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push:
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    fclose(stdin);
    return 0;
}

/* 你的代码将被嵌在这里 */
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    S->MaxSize = MaxSize;
    S->Top1 = -1;
    S->Top2 = MaxSize;
    return S;
}
bool Push( Stack S, ElementType X, int Tag )
{
    if( (S->Top1 + 1) < S->Top2 )
    {
        switch(Tag)
        {
        case 1:
            S->Data[++S->Top1] = X;
            break;
        case 2:
            S->Data[--S->Top2] = X;
            break;
        }
        return true;
    }
    else
    {
        printf("Stack Full\n");
        return false;
    }
}
ElementType Pop( Stack S, int Tag )
{
    ElementType ret = ERROR;
    bool flag = false;
    switch(Tag)
    {
    case 1:
        if(S->Top1 > -1)
        {
            ret = S->Data[S->Top1--];
            flag = true;
        }
        break;
    case 2:
        if(S->Top2 < S->MaxSize)
        {
            ret = S->Data[S->Top2++];
            flag = true;
        }
        break;
    }
    if(!flag)
        printf("Stack %d Empty\n", Tag);
    return ret;
}
