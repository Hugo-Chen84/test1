#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct Calculation
{
	double num1;
	char law;
	double num2;
};
int main()
{
	printf("请输入计算式：数字运算符数字,计算结果将保留两位小数\n");
	struct Calculation c = { 0.0,'+',0.0};
	scanf("%lf%c%lf", &c.num1,&c.law,&c.num2 );
	if (c.law == '+')
	{
		printf("%.2lf", c.num1 + c.num2);
	}
	else if (c.law == '-')
	{
		printf("%.2lf", c.num1 - c.num2);
	}
	else if (c.law == '*')
	{
		printf("%.2lf", c.num1 * c.num2);
	}
	else if (c.law == '/')
	{
		printf("%.2lf", c.num1 / c.num2);
	}
	else
	{
		printf("请按正确的格式输入");
	}
	return 0;
}//保留两位小数的简易版计算器