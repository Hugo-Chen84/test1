#include <stdio.h>//选择语句
int main()
{
	int input = 0;
	printf("你会好好学习吗？会请按1，不会请按0\n");
	scanf_s("%d", &input);
	if (input == 1)
	{
		printf("找到好工作\n");
	}
	else
	{
		printf("回家种地\n");
	}
	return 0;
}