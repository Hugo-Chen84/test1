#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int c = a / b;
    int d = a % b;
    printf("%d %d", c, d);
    return 0;
}