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
		f();//���ú���Ҫ������
		i++;
	}
	return 0;
}