#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int n;
    int arr[10][10] = { 0 };
    scanf("%d", &n);
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (num <= n * n) {
        // 从左到右填充上边界
        for (int i = left; i <= right; i++) {
            arr[top][i] = num++;
        }
        top++;

        // 从上到下填充右边界
        for (int i = top; i <= bottom; i++) {
            arr[i][right] = num++;
        }
        right--;

        // 从右到左填充下边界
        for (int i = right; i >= left; i--) {
            arr[bottom][i] = num++;
        }
        bottom--;

        // 从下到上填充左边界
        for (int i = bottom; i >= top; i--) {
            arr[i][left] = num++;
        }
        left++;
    }

    // 输出方阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
