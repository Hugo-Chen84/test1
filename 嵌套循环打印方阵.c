#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {

    int i, j, n;
    scanf("%d", &n);
    for (i = (n - 1); i >= 0;i--) {

        for (j = 1; j <= n; j++) {
            printf("%4d",i * n + j);
        }

        printf("\n");
    }

    return 0;
}