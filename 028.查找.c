#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	scanf("%d", &k);
	int i = 0;
	while (i <= 9)
	{
		if (arr[i] == k)
		{
			printf("Found at index %d\n", i);
			break;
		}
		i++;
	}
	if (i == 10)
	{
		printf("Not Found\n");
	}
	return 0;
}
