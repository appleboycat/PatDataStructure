#include <stdio.h>

int main()
{
    freopen("5_7.in", "r", stdin);
    int Rlen = 0;
    int Tlen = 0;
    scanf("%d %d\n", &Rlen, &Tlen);
    int R[Rlen + 1];
    int TNode[Tlen + 1];
    int i = 1;
    while(i <= Rlen)
    {
        scanf("%d", &R[i]);
        i++;
    }
    i = 1;
    while(i <= Tlen)
    {
        scanf("%d", &TNode[i]);
        i++;
    }
    i = 1;
    while(i <= Rlen)
    {
        printf("%d: %d \n", i, R[i]);
        i++;
    }


	fclose(stdin);
	return 0;

}
void sift(int* R, int i, int m)
{

}
