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

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */
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

#define MAXSIZE 20
int GetHeight( BinTree BT )
{
    if(BT == NULL)
    {
        return 0;
    }
    Position que[MAXSIZE];
    int front = 0, rear = 0;
    int level = 0;
    rear = (rear + 1) % MAXSIZE;
    que[rear] = BT;

    while(front != rear)
    {
        int num = (rear - front + MAXSIZE) % MAXSIZE;

        level++;

        while(num--)
        {
            front = (front + 1)%MAXSIZE;
            Position p = que[front];
            if(p->Left)
            {
                rear = (rear + 1) % MAXSIZE;
                que[rear] = p->Left;
            }
            if(p->Right)
            {
                rear = (rear + 1) % MAXSIZE;
                que[rear] = p->Right;
            }

        }

    }
    return level;
}



int TreeDepth(TreeNode* pRoot)
{
    queue<TreeNode*> q;
    if(!pRoot) return 0;

    q.push(pRoot);
    int level=0;
    while(!q.empty()){
        int len=q.size();
        level++;
        while(len--){
            TreeNode* tem=q.front();
            q.pop();
            if(tem->left) q.push(tem->left);
            if(tem->right) q.push(tem->right);
        }
    }
    return level;
}
