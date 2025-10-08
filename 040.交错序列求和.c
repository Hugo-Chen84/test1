#include <stdio.h>
int main()
{
    int n;
    scanf_s("%d", &n);
    int flag = 1;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + flag / (3.0 * i - 2.0);
        flag = -flag;
    }
    printf("sum = %.3f", sum);
    return 0;
}
