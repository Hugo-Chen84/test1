#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long reverse(long number);

int main() {
    long number;
    scanf("%ld", &number);
    printf("%ld", reverse(number));
    return 0;
}

long reverse(long number)
{
    int flag;


    long res = 0;
    
    flag = number < 0 ? -1 : 1;
    if (flag == -1)
        number = -number;

    while (number != 0) {
        res = res * 10 + number % 10;
        number /= 10;
    }
    return flag * res;
}
