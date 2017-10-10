#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* ʵ��ϸ�ں��� */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
int GetHeight( BinTree BT )
{
    if(BT)
    {
        int lht = GetHeight(BT->Left);
        int rht = GetHeight(BT->Right);
        return (lht>rht?lht:rht) + 1;
    }
    else
    {
        return 0;
    }
}
