#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
    double ret = 0, b = 0;
    int ch;//����
    char op;//�洢�����
    while (1) {
        ch = getchar();
        if (ch == '=')
            break;
        if (ch >= '0' && ch <= '9' && ret == 0) {
            ret = ch;
        }
        else if (ch >= '0' && ch <= '9' && ret != 0) {
            b = ch;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            op = ch;
        }
        else
            continue;//��������

        if (ret && b) {
            if (op = '+')
                ret += b;
            else if (op = '-')
                ret -= b;
            else if (op = '*')
                ret *= b;
            else if (op = '/')
                ret /= b;
            else
                ret = pow(ret, b);

            b = 0;//����
        }//�ֱ����
    }

    printf("%.4f\n", ret);
    return 0;
}