#include <stdio.h>
int main() {
    int a = 10;
    int* p = &a; // p ������ a �ĵ�ַ

    printf("a��ֵ��%d\n", a); // ��� 10
    printf("a�ĵ�ַ��%p\n", &a); // ���һ������0x7fff...�ĵ�ַ
    printf("p����ĵ�ַ��%p\n", p); // �������һ����ͬ�ĵ�ַ
    printf("ͨ��p������ֵ�������ã���%d\n", *p); // ��� 10

    *p = 20; // ͨ��ָ�� p �޸� a ��ֵ
    printf("�޸ĺ�a��ֵ��%d\n", a); // ��� 20

    return 0;
}