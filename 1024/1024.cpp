#include<stdio.h>
int B[1000010], C[1000010], A[1000010], max;
int main()
{
	int m, n, i, j;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		for (i = 1, C[0] = 0; i <= n; i++) {
			scanf("%I64d", &A[i]);
			C[i] = 0;
		}
		for (i = 1; i <= m; i++)
		{
			B[i] = B[i - 1] + A[i];
			max = B[i];
			for (j = i + 1; j <= n - m + i; j++)
			{
				B[j] = B[j - 1]>C[j - 1] ? B[j - 1] + A[j] : C[j - 1] + A[j];
				C[j - 1] = max;
				if (max<B[j])max = B[j];
			}
			C[j - 1] = max;
		}
		for (i = m; i <= n; i++)
			if (max<B[i])max = B[i];
		printf("%d\n", max);
	}
	return 0;
}
