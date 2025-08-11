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
}//Êä³ö1µ½100¼äËùÓÐµÄÆæÊý
