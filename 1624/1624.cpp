// 1624.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{
	long long n;
	int k;
	long long *a;
	while (scanf("%I64d%d",&n,&k)!=EOF)
	{
		if (n - k - 2 < 0) {
			printf("1\n");
			continue;
		}
		
		a = (long long*)malloc(sizeof(long long)*(n+1));
		a[0] = 0;
		for (int i = 0; i <= k+1; i++) {
			a[i] = 1;
		}
		for (long long i = k + 2; i <= (n + k)/2 + 1; i++) {
			if ((i - k) / 2 * 2 == i - k)
			{
				a[i] = a[(i + k) / 2] + a[(i - k) / 2];
			}
			else {
				a[i] = a[i - (i - k)/2] + a[(i - k) / 2];
			}
		}
		if ((n - k) / 2 * 2 == n - k)
		{
			a[n] = a[(n + k) / 2] + a[(n - k) / 2];
		}
		else {
			a[n] = a[n - (n - k) / 2] + a[(n - k) / 2];
		}
		printf("%I64d\n",a[n]);
		free(a);
	}
    return 0;
}

