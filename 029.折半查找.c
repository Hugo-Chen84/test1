#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int k = 0;
	scanf("%d", &k);
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = (sizeof arr / sizeof arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (k < arr[mid])
		{
			right = mid-1;
		}
		else if (k > arr[mid])
		{
			left = mid+1;
		}
		else
		{
			printf("Found at index %d\n", mid);
			return 0;
		}
	}
	printf("Not Found\n");
	return 0;
}
