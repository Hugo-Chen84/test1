#include <stdio.h>,<string.h>
int main()
{
	char arr1[] = "abcedf";
	char arr2[] = { 'a','b','c','d','e','f' };
	printf(" % s\n", arr1);
	printf(" % s\n", arr2);//°´fn+f10,źŕĘÓżÉˇ˘ĎÖ˛ťÍŹĄŁ
	char arr3[] = { 'a','b','c','d','e','f','\0' };
	printf(" % s\n", arr3);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	int len3 = strlen(arr3);
	printf("%d\n %d\n %d\n", len1, len2, len3);
	printf("\a\a\a\a");
	return 0;
}
