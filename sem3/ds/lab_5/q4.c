#include <stdio.h>
#include <stdlib.h>
int tos = -1;
int stack[20];
int pop()
{
    if (tos == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        return stack[--tos + 1];
    }
}
void push(int t)
{
    if (tos == 19)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        stack[++tos] = t;
        return;
    }
}

void del(int *arr, int n, int k)
{
    int flag = 0;
    int kc = k;
    int i;
    for (i = 0; i < n, k != 0; i++)
    {
        if (*(arr + i) < *(arr + i + 1))
        {
            if (tos != -1)
            {
                if (stack[tos] < *(arr + i + 1))
                {
                    int t = pop();
                    push(*(arr + i + 1));
                    k = k - 2;
                    i = i + 1;
                    continue;
                }
            }
        }

        else
        {
            push(*(arr + i));
        }
    }
    if (kc == k)
    {
        printf("No elements were deleted\n");
        exit(0);
    }
    if (k != 0)
    {
        printf("%d elements were not deleted\n", k);
    }
    i--;
    for (; i < n; i++)
    {
        push(*(arr + i));
    }
    return;
}

int main()
{
    int n, k, arr[20];
    printf("Enter no. of elements in array:");
    scanf("%d", &n);
    printf("Enter an array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter no: of elements to delete:");
    scanf("%d", &k);
    int *p = (int *)calloc(k, sizeof(int));
    del(arr, n, k);
    printf("Modified array:\n");
    for (int i = 0; i < n - k; i++)
    {
        printf("%d\t", stack[i]);
    }
}