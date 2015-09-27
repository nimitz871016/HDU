// 1019.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
long long GCD(long long a, long long b)
{
	return b == 0 ? a : GCD(b, a%b);
}

long long LCM(long long a, long long b) {
	return a / GCD(a, b) *b;
}

int main()
{
	int n, m;
	long long *a;
	while (scanf("%d", &n) != EOF) {
		while (n--)
		{
			scanf("%d", &m);
			if (m == 1) {
				long long aa;
				scanf("%lld", &aa);
				printf("%d\n", aa);
				continue;
			}
			a = (long long *)malloc(sizeof(long long)*m);
			for (int i = 0; i < m; i++)
			{
				scanf("%lld", &a[i]);
			}
			int tmpResult = LCM(a[0], a[1]);
			for (int i = 2; i < m; i++) {
				tmpResult = LCM(tmpResult, a[i]);
			}
			free(a);
			printf("%d\n", tmpResult);

		}
	}
	return 0;
}

