#if 1
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int n, m;
	int a[9] = { 1,1,2,6,24,120,720,5040,40320 };
	while (scanf("%d%d", &n, &m) != EOF) {
		int i = 9;
		if (n < 9)
		{
			if (m > a[n])
			{
				m = m % a[n] == 0 ? a[n] : m% a[n];
			}

		}
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
		int *b = new int[i];
		int *c = new int[i];
		//int *b = (int *)malloc(sizeof(int)*(i));
		//int *c = (int *)malloc(sizeof(int)*(i));
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
				b[m % a[i] == 0 ? m / a[i] : m / a[i] + 1] = 99999;
			}
			else
			{
				if (m / a[i] * a[i] == m)
				{
					c[j++] = b[m / a[i] - 1];
					b[m / a[i] - 1] = 99999;
				}
				else
				{
					c[j++] = b[m / a[i]];
					b[m / a[i]] = 99999;
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
		for (int j = 0; j < n - tempi - 1; j++)
		{
			printf("%d ", j + 1);
		}
		for (int j = 0; j < tempi; j++)
		{
			printf("%d ", c[j]);
		}
		printf("%d\n", c[tempi]);
		//getchar();
	}
	return 0;
}
#endif
