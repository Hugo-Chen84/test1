#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int binary_search(int arr[], int k, int sz);
//不可直接计算项数
//数组传值只传首地址

int main() {
	int k = 0;
	int arr[] = { 11,12,13,14,15,16,17,18,19 };//顺序数组
	int sz = sizeof(arr) / sizeof(arr[0]);

	printf("Please enter a number to check if it is in the list:\n");
	scanf("%d", &k);

	if (binary_search(arr, k, sz) == -1) {
		printf("Not Found\n");
	}
	else {
		printf("Found at the index:%d\n", binary_search(arr, k, sz));
	}

	return 0;
}

int binary_search(int arr[], int k, int sz) {
	int left = 0;
	int right = sz - 1;
	int mid = 0;

	while (left <= right) {
		mid = left + (right - left) / 2;
		//防止左右下标之和过大而导致溢出
		
		if (k < arr[mid]) {
			right = mid - 1;
		}
		else if (k > arr[mid]) {
			left = mid + 1;
		}
		else
			return mid;
	}//正常查找结束后在循环中已以mid形式返回下标
	
	return -1;//查找失败时程序在此处终止
}
