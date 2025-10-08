#include <stdio.h>
void f()
{
	static int a = 2;
	a++;
	printf("%d ", a);
}
int main()
{
	int i = 0;
	while (i < 10)
	{
		f();//µ÷ÓÃº¯ÊýÒªÓÃÀ¨ºÅ
		i++;
	}
	return 0;
}
