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
    sift(R, 1, 5);
    i = 1;
    while(i <= Rlen)
    {
        printf("%d: %d \n", i, R[i]);
        i++;
    }


	fclose(stdin);
	return 0;

}
void sift(int* R, int k, int m)
{
    int i = k;
    int j = 2 * i;

    while( j <= m )
    {
        if(R[j] > R[j+1])
        {
            j++;
        }
        if(R[i] < R[j])
        {
            break;
        }
        else
        {
            int tmp = R[i];
            R[i] = R[j];
            R[j] = tmp;
            i = j;
            j = i * 2;
        }
    }


}
