#include <stdio.h>//º¯Êý
int Add(int x, int y)
{
	return (x+y);
}
int main()
{
	int n1 = 0;
	int n2 = 0;
	scanf_s ("%d %d", &n1, &n2);
	int sum = Add(n1, n2);
	printf("%d\n", sum);
	return 0;
}
