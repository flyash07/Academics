#include <stdio.h>
#include <stdlib.h>
int tos = -1;
int c[20];

void push(int t)
{
	if (tos == 19)
	{
		printf("Stack overflow\n");
		return;
	}
	else
	{
		c[++tos] = t;
		return;
	}
}

int pop(void)
{
	if (tos == -1)
	{
		printf("stack underflow\n");
		return -1;
	}
	else
	{
		// tos--;
		return c[--tos + 1];
	}
}

int convert(int d)
{
	while (d != 0)
	{
		push(d % 2);
		d = d / 2;
	}
	int b = 0;
	while (tos != -1)
	{
		b = b * 10 + pop();
	}
	return b;
}
int main()
{
	int dec, bin;
	char t, dummy;
	printf("Enter a decimal number:");
	scanf("%d", &dec);
	printf("Binary equivalent is:%d\n", convert(dec));
	return 0;
}
