#include <stdio.h>//ѭ����� 
int main()
{
	int line = 0;
	while (line < 99)
	{
		printf("д����:%d\n",line);
		line++;
	}
	if (line >= 100)
	{
		printf("��offer\n");
	}
	else
	{
		printf("��������\n");
	}
	return 0;
}