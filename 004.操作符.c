#include<stdio.h>
typedef int i;
int main()
{
	int a = 1;
	int b = 10;
	if (a&&b)
	{
		printf("true.");
	}
	int c = 1;
	int d = 0;
	if (c || d)
	{
		printf("true.");
	}
	i e = 20;
	i f = 30;
	i result = e > f ? e : f;
	printf("%d", result);

	return 0;
}
