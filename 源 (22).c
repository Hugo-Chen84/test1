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
	printf("���������ʽ���������������,��������������λС��\n");
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
		printf("�밴��ȷ�ĸ�ʽ����");
	}
	return 0;
}//������λС���ļ��װ������