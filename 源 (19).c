#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char password[20] = {0};
	printf ("%s", "���������룺");
	scanf ("%s", password);
	printf ("%s", "��ȷ������(Y/N):");
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
}//���յõ�������ֻ�пո�֮ǰ��