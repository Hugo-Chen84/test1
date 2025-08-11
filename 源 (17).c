#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0;
    scanf("%d", &a);
    int b = 0;
    if (a >= 0)
    {
        b = a;
    }
    else {
        b = -a;
    }
    printf("%d", b % 10);
    return 0;
}