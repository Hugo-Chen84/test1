#include<stdio.h>
#include<math.h>

int check(int n)
{
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}//�ж���������,��������1����������0

int main() {
    int n, max = 1;
    scanf_s("%d", &n);

    int totalcheck = 0;
    for (int a = 2; a <= n; a++) {
        double num = pow(2, a) - 1.0;
        if (check(num))
            printf("%.0f\n", num);
        totalcheck += check(num);
    }//��ӡ����������

    if (totalcheck == 0)
        printf("None");
    return 0;
}