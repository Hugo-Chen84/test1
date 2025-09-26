#include <stdio.h>
int main(void)
{
    int begin, finish;
    int ret1, ret2;
    scanf_s("%d %d", &begin, &finish);
    int hour1 = begin / 100;
    int min1 = begin % 100;
    int hour2 = finish / 100;
    int min2 = finish % 100;
    if (min2 >= min1)
    {
        ret1 = hour2 - hour1;
        ret2 = min2 - min1;
    }
    else {
        ret2 = 60 - min1 + min2;
        ret1 = hour2 - hour1 - 1;
    }
    printf("%02d:%02d", ret1, ret2);
    return 0;
}