#include <stdio.h>
int main()
{
    int check, finish;
    scanf_s("%d %d", &check, &finish);
    int fir1 = check / 100;
    int fir2 = check / 1000;
    int fir3 = finish / 100;
    int fir4 = finish / 1000;
    if (check > finish || fir1 == 0 || fir2 != 0 || fir3 == 0 || fir4 != 0 || check < 0 || finish < 0)
    {
        printf("Invalid Value.");
    }
    else
    {
        for (; check <= finish; check++)
        {
            int a = check / 100;
            int b = check / 10 % 10;
            int c = check % 10;
            int d = check / 1000;
            if (a * a * a + b * b * b + c * c * c == check)
            {
                printf("%d\n", check);
            }
        }
    }
    return 0;
}