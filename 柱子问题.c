#include <stdio.h>

// 计算接雨水总量的函数
int trap(int* height, int heightSize) {
    if (heightSize == 0) return 0;  // 空数组直接返回0
    int left = 0, right = heightSize - 1;  // 左右指针
    int left_max = 0, right_max = 0;       // 左右最大高度
    int result = 0;                        // 总雨水量
    
    while (left < right) {
        if (height[left] < height[right]) {
            // 左指针移动逻辑：以左最大高度为基准
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                result += left_max - height[left];
            }
            left++;
        } else {
            // 右指针移动逻辑：以右最大高度为基准
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                result += right_max - height[right];
            }
            right--;
        }
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);  // 读取数组长度
    int height[n];    // 定义可变长度数组存储柱子高度
    int i=0;
    for (; i < n; i++) {
        scanf("%d", &height[i]);  // 读取每个柱子的高度
    }
    int total = trap(height, n);  // 计算总雨水量
    printf("%d\n", total);        // 输出结果
    return 0;
}
