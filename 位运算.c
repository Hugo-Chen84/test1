#include<stdio.h>
void print_bits(unsigned n) {
    for (int i = 31; i >= 0; i--) {
        int a = (n >> i) & 1;
        printf("%d", a);
        if (i % 8 == 0)
            printf(" ");
    }
}
int main() {
    unsigned n, k;
    char c;
    scanf_s("%u %u %c", &n, &k, &c);
    switch (c) {
    case 'P':print_bits(n); break;
    case 'L':n = n << k; print_bits(n); break;
    case 'R':n = n >> k; print_bits(n); break;
    case 'F':n ^= (1 << k); print_bits(n); break;
    case 'S':n |= (1 << k); print_bits(n); break;
    case 'Z':n &= ~(1 << k); print_bits(n); break;
    default: printf("Input Error\n");
    }
    return 0;
}