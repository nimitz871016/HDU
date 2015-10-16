// 1023.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char *split(long a, int *count = 0) {
	int n = 0;
	while (a / (long)pow(10, n) != 0)
	{
		n++;
	}
	*count = n;
	long sum = a;
	char *result = (char *)malloc(sizeof(char)*n);
	while (n != 0) {
		result[n - 1] = sum / (long)pow(10, n - 1) + 48;
		sum = sum - sum / (long)pow(10, n - 1)*pow(10, n - 1);
		n--;
	}
	return result;
}
char *bigNumberAdd(long n1,long n2,int num){
	//如果num=0,就计算位数，否则已num+1为结果的位数
	//计算a和b的位数，决定最长位数。

	int a, i, n = 0, m, b, f = 1;
	int g, h, j, k, l;
	char *c, *d, *e;
	c = (char *)malloc(sizeof(char)*num);
	d = (char *)malloc(sizeof(char)*num);
	e = (char *)malloc(sizeof(char)*num);
	e[0] = 48;
	c = split(n1);
	d = split(n2);
		a = strlen(c);
		b = strlen(d);
		j = a;
		k = b;
		m = a > b ? a : b;
		if (a >= b)
		{
			for (i = b - 1; i >= 0; i--)
			{
				e[a] = c[a - 1] + d[b - 1] - 48;
				a--;
				b--;
				if (b == 0)
					break;
			}
			for (i = a - b - 1 - n; i >= 0; i--)
			{
				e[i + 1] = c[i];
			}
		}
		else
		{
			for (i = a - 1; i >= 0; i--)
			{
				e[b] = c[a - 1] + d[b - 1] - 48;
				a--;
				b--;
				if (a == 0)
					break;
			}
		}
		for (i = b - a - 1 - n; i >= 0; i--)
		{
			e[i + 1] = d[i];
		}
		for (i = m; i >= 1; i--)
		{
			if (e[i] >= 58)
			{
				e[i] = e[i] - 10;
				e[i - 1] = e[i - 1] + 1;
			}
			if (e[0] == 49)
				f = 0;
		}
		char *result = (char *)malloc(sizeof(char)*(m - f + 1));
		int resulti = 0;
		for (l = f; l <= m; l++) {
			result[resulti] = e[l];
			resulti++;
		}
		return result;
}
__int64 Factorial(int num) {
	double sum = 1;
	double sum1 = 1;
	int j = 1;
	for (int i = num+1; i <= 2*num; i++)
	{
		sum *= i / j;
		j++;
	}
	/*
	for (int i = 2; i <= num ; i++) {
		sum1 *= i;
	}
	*/
	return (__int64)sum;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		printf("%I64d\n", Factorial(n) / (n+1));
	}
    return 0;
}

