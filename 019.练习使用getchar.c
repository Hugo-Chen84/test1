#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char password[20] = {0};
	printf ("%s", "请输入密码：");
	scanf ("%s", password);
	printf ("%s", "请确认密码(Y/N):");
	int try = 0;
	while ((try = getchar()) !=  '\n')
	{
		getchar;
	}
	int ch = getchar();
	if (ch == 'Y')
	{
		printf ("YES\n");
	}
	else
	{
		printf ("NO\n");
	}
	printf("%s", password);
	return 0;
}//最终得到的密码只有空格之前的
