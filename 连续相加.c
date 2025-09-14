#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int m, int n)
{
    int ret = 0;
    int i;
    for (i = m; i <= n; i++)
    {
        ret = ret + i;
    }
    return ret;
}
int main()
{
    int m = 0;
    int n = 0;
    scanf("%d %d", &m, &n);
    printf("sum=%d\n", sum(m, n));
    return 0;
}