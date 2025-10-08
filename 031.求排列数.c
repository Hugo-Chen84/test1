#include <stdio.h>

double fact(int n);

int main(void)
{
    int m, n;
    double result;

    scanf_s("%d%d", &m, &n);
    if (m > 0 && n > 0 && m <= n) {
        result = fact(n) / fact(n - m);
        printf("result = %.0f\n", result);
    }

    return 0;
}

double fact(int n)
{
    double ret = 1;
    int i = 1;
    for (; i <= n; i++)
    {
        ret = ret * i;
    }
    return ret;
}
