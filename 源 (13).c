#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 1;
	unsigned long long result = 1;
	for (; i <= n; i++)
	{
		result = result * i;
	}
	printf("%llu", result);//±ÜÃâÒç³ö
	return 0;
}