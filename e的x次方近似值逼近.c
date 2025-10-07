#include<stdio.h>
#include<math.h>

double fact(int n)
{
    double ret = 1;
    if (n == 0) {
        return 1.0;//特殊规则
    }
    for (int i = 1; i <= n; i++) {
        ret = ret * i;
    }
    return ret;
}//阶乘函数

int main()
{
    double n;
    scanf_s("%lf", &n);
    if (n < 0 || n>5)
        return 0;
    double total = 0.0;
    int i = 0;
    while (pow(n, i) / fact(i) >= 0.00001) {
        total = total + pow(n, i) / fact(i);
        i++;
    }
    printf("%.4f", total);
    return 0;
}