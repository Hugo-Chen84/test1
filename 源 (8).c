#include <stdio.h>//循环语句 
int main()
{
	int line = 0;
	while (line < 99)
	{
		printf("写代码:%d\n",line);
		line++;
	}
	if (line >= 100)
	{
		printf("好offer\n");
	}
	else
	{
		printf("继续加油\n");
	}
	return 0;
}