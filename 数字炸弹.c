#include<stdio.h>
int main() {
    int num, n, guess;
    scanf_s("%d %d", &num, &n);
    for (int i = 1; i <= n; i++) {
        scanf_s("%d", &guess);
        if (guess < 0) {
            break;
        }
        else if (guess > num) {
            printf("Too big\n");
        }
        else if (guess < num && guess >= 0) {
            printf("Too small\n");
        }

        else {
            if (i == 1)
                printf("Bingo!\n");
            else if (i <= 3)
                printf("Lucky You!\n");
            else
                printf("Good Guess!\n");
            return 0;
        }
    }

    printf("Game Over\n");
    return 0;
}