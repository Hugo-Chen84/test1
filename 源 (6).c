#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };//��ʱ��������10��0
	int b = sizeof arr;
	int c = sizeof arr[0];
	printf("%d\n", b / c);
	printf("%d\n", arr[5]);
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", arr[i]);
		i += 1;
	}
	return 0;
}