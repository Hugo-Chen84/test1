#include<stdio.h>
#include<math.h>
int main() {

    double n = 1.0;
    double mother = 1.0;
    int flag = 1;
    double res = 0.0;
    int x;
    double e;
    scanf_s("%d %le", &x, &e);
    double pow = x;
    while (1) {
        res += flag * x / mother;
        if (fabs(x / mother) <= e) {
            break;
        }
        x = x * pow * pow;
        flag = -flag;
        n += 2;
        mother = mother * n * (n - 1);
    }
    printf("sin(%lf) = %.4f\n", pow, res);
    return 0;
}