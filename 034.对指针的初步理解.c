#include <stdio.h>
int main() {
    int a = 10;
    int* p = &a; // p 保存了 a 的地址

    printf("a的值：%d\n", a); // 输出 10
    printf("a的地址：%p\n", &a); // 输出一个类似0x7fff...的地址
    printf("p保存的地址：%p\n", p); // 输出和上一行相同的地址
    printf("通过p看到的值（解引用）：%d\n", *p); // 输出 10

    *p = 20; // 通过指针 p 修改 a 的值
    printf("修改后，a的值：%d\n", a); // 输出 20

    return 0;
}
