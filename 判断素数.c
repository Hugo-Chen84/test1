#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 2;
	scanf("%d", &n);
	while (i)
	{
		if (n % i == 0)
		{
			printf("%d��������\n",n);
			break;
		}
		else if(i*i >=n)
		{
			printf("%d������\n", n);
			break;
		}
		else
		{
			i++;
		}
	}
	return 0;
}