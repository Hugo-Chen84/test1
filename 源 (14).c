#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	scanf("%d", &i);
	int a = 1;
	for (; i >= 1; i--)
	{
		a = a * i;
	}
	printf("%d", a);
	return 0;
}
	//¼ÆËã½×³Ë