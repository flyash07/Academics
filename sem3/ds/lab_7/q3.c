#include <stdio.h>
int main()
{
    int t, i;
    printf("Enter number of testcases:");
    scanf("%d", &t);
    int N[t], k[t];
    printf("Enter values of N and K:");
    for (i = 0; i < t; i++)
    {
        scanf("%d%d", &N[i], &k[i]);
    }
    for (i = 0; i < t; i++)
    {
        if (k[i] % 3 == 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
}