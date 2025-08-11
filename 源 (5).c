#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d/%d", &a, &b);
	int result = a / b;
	int mod = a % b;
	printf("%d......%d", result, mod);
	return 0;
}