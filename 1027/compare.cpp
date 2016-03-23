#if 0
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int *resultnewmethod;

int* newMethod(int n,int m) {
		int  i;
		int* result = (int *)malloc(sizeof(int) *n);
			int a[1005];
			for (i = 1; i <= n; i++)
				a[i] = i;
			for (i = 1; i < m; i++)
				next_permutation(a + 1, a + n + 1);
			int tempi = 0;
			for (i = 1; i <= n; i++) {
				result[tempi++] = a[i];
				printf(i == n ? "%d\n" : "%d ", a[i]);
			}
		return result;
}

int* otherMethod(int n,int m) {
	int a[9] = { 1,1,2,6,24,120,720,5040,40320 };
	
	if (n < 9)
	{
		if (m > a[n])
		{
			m = m % a[n] == 0 ? a[n] : m% a[n];
		}

	}
	
		int i = 9;
		while (i--)
		{
			if (a[i] < m) {
				m -= a[i];
				break;
			}
			else if (a[i] == m) {
				m -= a[i];
				i--;
				break;
			}
		}
		int *b = (int *)malloc(sizeof(int)*(i));
		int *c = (int *)malloc(sizeof(int)*(i));
		for (int j = 0, k = n - i; j <= i; j++)
		{
			b[j] = k++;
		}
		int tempi = i;
		int j = 0;
		while (m)
		{
			if (j == 0)
			{
				c[j++] = b[m % a[i] == 0 ? m / a[i] : m / a[i] + 1];
				b[m % a[i] == 0 ? m / a[i] : m / a[i] + 1] = 9999;
			}
			else
			{
				if (m / a[i] * a[i] == m)
				{
					c[j++] = b[m / a[i] - 1];
					b[m / a[i] - 1] = 9999;
				}
				else
				{
					c[j++] = b[m / a[i]];
					b[m / a[i]] = 9999;
				}
			}
			if (m % a[i] == 0)
			{
				sort(b, b + i + 1);
				i--;
				break;
			}
			m = m % a[i];
			sort(b, b + i + 1);
			i--;
		}
		//提前结束，还有位子没排，这是因为m% =0了，这说明是处于每种情况的最后一种，这时候要确定之后，填上
		c[j] = b[i--];
		for (int k = j + 1; k < tempi + 1; k++)
		{
			c[k] = b[i--];
		}
		int *result = (int *)malloc(sizeof(int)*n);
		int tempj = 0;
		for (int j = 0; j < n - tempi - 1; j++)
		{
			result[ tempj++ ] = j + 1;
			//printf("%d ", j + 1);
		}
		for (int j = 0; j < tempi; j++)
		{
			result[tempj++] = c[j];
			//printf("%d ", c[j]);
		}
		result[tempj++] = c[tempi];
		//printf("%d\n", c[tempi]);
		//getchar();
	
	return result;
}

bool compare(int *a, int *b, int n) {
	for (int i = 0; i < n; i++)
	{
		if (a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
int main() {
	int aa[9] = { 1,1,2,6,24,120,720,5040,40320 };
	int count = 0;
	while (true)
	{
		int n, m;
		//n = rand() % 999 + 1;
		//m = rand() % 9999 + 1;
		//scanf("%d %d", &n, &m);
		for (int n = 1; n < 1001; n++)
		{
			n = 10;
			for (int m = 40320; m < 100001; m++)
			{


				int *a = newMethod(n, m);
				int *b = otherMethod(n, m);
				if (compare(a, b, n)) {
					//printf("Match\n");
				}
				else {
					printf("UnMatch! n:%d m:%d\n", n, m);
					getchar();
				}
				printf("%d\n", count++);
			}
		}
	}
	return 0;
}
#endif