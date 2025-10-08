#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
    double ret = 0, b = 0;
    int ch;//读入
    char op;//存储运算符
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
            continue;//处理输入

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

            b = 0;//重置
        }//分别计算
    }

    printf("%.4f\n", ret);
    return 0;
}
