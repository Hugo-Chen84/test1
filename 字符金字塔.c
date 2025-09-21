#include <stdio.h>

void CharPyramid(int n, char ch)
{
    int i = 1;
    while (i <= n)
    {
        int a = 1;
        for (a = n; a > i; a--)
        {
            printf(" ");
        }
        for (a = 1; a <= i; a++)
        {
            printf("%c ", ch);
        }
        printf("\n");
        i++;
    }
}

int main()
{
    int n;
    char ch;

    scanf_s ("%d %c", &n, &ch);
    CharPyramid(n, ch);

    return 0;
}