#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double c = 0.0;
    double d = 0.0;
    scanf("%lf %lf", &c, &d);
    printf("%.3lf%%", d / c * 100);
    return 0;
}//ÒßÇéËÀÍöÂÊ