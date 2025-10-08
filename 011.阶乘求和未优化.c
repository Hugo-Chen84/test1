#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
	int X(int n,int i)
	{
		unsigned long long ret = 1;
		for (; i <= n; i++)
		{
			ret = ret * i;
		}
		return ret;
	}
int main()
{
	int a = 1;
	unsigned long long b = 0;
	unsigned long long sum = 0;
	for (; a <= 10; a++)
	{
		b= X(a, 1);
		sum = sum + b;
	}
	printf("%lld", sum);
	return 0;
}
//1µ½10½×³ËµÄºÍ
