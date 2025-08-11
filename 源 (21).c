#include <stdio.h.>
int main()
{
	static int i = 1;
	while (i < 100)
	{
		printf("%d\n", i);
		i = i + 2;
	}
	return 0;
}//输出1到100间所有的奇数