// 1013.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int *split(long a) {
	int n = 0;
	while (a / (long)pow(10, n) != 0)
	{
		n++;

	}
	long sum = a;
	int *result = (int *)malloc(sizeof(int)*n);
	while (n != 1) {
		result[n] = sum - sum / (long)pow(10, n - 1)*pow(10, n - 1);
		n--;
	}
	return result;
}
int main()
{
	int a = 12345;
	int *b = split(a);
	for (int i = 0; i < 5; i++) {
		printf("%d ",b[i]);
	}
	getchar();
    return 0;
}

