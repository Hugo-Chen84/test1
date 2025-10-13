#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int)time(NULL));
    //随机数种子

    int ret = rand()%100+1;
    int input=0;
   
    while (1) {
        scanf_s("%d", &input);
        if (ret == input) {
            printf("BINGO!\n");
            break;
        }
        else if (ret > input) {
            printf("Too small\n");
        }
        else {
            printf("Too big\n");
        }
    }

    return 0;
 }