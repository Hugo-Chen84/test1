#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void sequenceprint(int num) {
	if (num > 9) {
		sequenceprint(num / 10);
	}

	printf("%d ",num % 10);
}

int main() {
	int num = 0;
	scanf("%d", &num);
	sequenceprint(num);
	return 0;
}
