#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[4] = { 0 };
	int i = 0;
	while (i < 4)
	{
	    scanf("%d", &arr[i]);
		i++;
	}
	int max = 0;
	i = 0;
	while (i < 4)
	{
		if (max < arr[i])
		{
			max = arr[i];
			i++;
		}
	}
	printf("%d", max);
	return 0;
}
//Ã°ÅÝÅÅÐò
