//ÓÅ»¯°æ
#include<stdio.h>
int main()
{
	int ret = 1;
	int sum = 0;
	int i = 1;
	for (i = 1; i <= 10; i++)
	{
		ret = ret * i;
		sum = sum + ret;
	}
	printf("%d", sum);
	return 0;
}