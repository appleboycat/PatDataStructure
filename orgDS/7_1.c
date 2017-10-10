#include <stdio.h>
int max(int a, int b)
{
    return a>b?a:b;
}
void main()
{
    int n;
    scanf("%d\n", &n);
    int ar[n];
    int i = 0;
    while(i < n)
    {
        scanf("%d", ar+i);
        i++;
    }
    int max = MaxSum(ar, 0, n-1);

    printf("max = %d\n", max);
}

int MaxSum(int* Ar, int bg, int ed)
{
    printf("---enter---\n");
    printf("[%d, %d]\n", bg, ed);
    if( bg > ed )
    {
        printf("--return--[%d] bg > ed\n", 0);
        //printf("[%d, %d]\n", bg, ed);
        return 0;
    }
    else if( bg == ed )
    {
        printf("--return--[%d] bg = ed\n", Ar[bg]);
        //printf("[%d, %d]\n", bg, ed);
        return Ar[bg];
    }
    else if( (bg+1) == ed )
    {
        int tmp = max(Ar[bg], Ar[ed]);
        tmp = max(tmp, Ar[bg] + Ar[ed]);
        printf("--return--[%d] bg+1 = ed\n", tmp);
        //printf("[%d, %d]\n", bg, ed);
        return tmp;
    }
    int length = ed - bg + 1;

    int md = bg + length/2 ;
    printf("length = %d md = %d\n", length, md);
    int Max = 0;
    int Left = MaxSum(Ar, bg, md);
    int Right = MaxSum(Ar, md+1, ed);
    Max = max(Left, Right);
    Left = 0;
    Right = 0;
    int l = 0;
    int r = 0;
    int i = md;
    while(i >= bg)
    {
        l += Ar[i];
        if(Left < l)
        {
            Left = l;
        };
        i--;
    }
    i = md+1;
    while(i <= ed)
    {
        r += Ar[i];
        if(Right < r)
        {
            Right = r;
        };
        i++;
    }
    printf("while--- Left[%d] Right[%d]\n", Left, Right);
    Max = max(Left, Right);
    if( Max < (Left + Right) )
    {
        Max = Left + Right;
    };
    printf("--return-- Max = %d\n", Max);
    return Max;
}
