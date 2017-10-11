#include <stdio.h>

void main()
{
    freopen("data_5_1.in", "rw", stdin);
    int K = 0;
    scanf("%d", &K);
    int ar[K];
    while(K)
    {
        scanf("%d",ar[K]);
        K--;
    }

    fclose(stdin);

}
