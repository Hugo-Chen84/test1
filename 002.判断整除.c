#include <stdio.h>
int main() {
    int a = 0;
    scanf_s("%d", &a);
    int b = 0;
    b = a % 5;
    if (b == 0)
    {
        printf("%s", "YES");
    }
    else {
        printf("%s", "NO");
    }
    return 0;

}//判断是否被5整除
