#include <stdio.h>

int sign(int x)
{
    int ret = 0;
    if (x > 0)
    {
        ret = 1;
    }
    else if (x == 0)
    {
        ret = 0;
    }
    else
    {
        ret = -1;
    }
    return ret;
}
int main()
{
    int x;

    scanf_s ("%d", &x);
    printf("sign(%d) = %d\n", x, sign(x));

    return 0;
}