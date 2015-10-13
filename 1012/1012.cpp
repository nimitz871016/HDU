// 1012.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

double jiechen(int n) {
	int sum = 1;
	if (n == 0)
	{
		return 1.0;
	}
	for (int  i = 1; i <= n; i++)
	{
		sum = sum * i;
	}
	double result = 1.0 / sum;
	return result;
}
int main()
{
	double a[10];
	double sum;
	sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += jiechen(j);
		}
		a[i] = sum;
	}
	printf("n e\n- -----------\n");
	for (int i = 0; i < 10; i++) {
		if (i == 8) {
			printf("%d %.9f\n", i, a[i]);
			continue;
		}
		printf("%d %.10g\n",i,a[i]);
	}
	getchar();
    return 0;
}

