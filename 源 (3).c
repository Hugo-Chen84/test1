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
		f();//调用函数要用括号
		i++;
	}
	return 0;
}