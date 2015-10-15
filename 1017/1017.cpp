// 1017.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int local() {
	int N;
	while (scanf("%d", &N) != EOF) {
		int m, n;
		int num = 0;
		while (N--) {
			num = 0;
			while (scanf("%d %d", &n, &m) != EOF && (n || m))
			{
				num++;
				int sum = 0;
				for (int i = 1; i < n; i++)
				{
					for (int j = i + 1; j < n; j++) {
						//double result = (1.0 * i*i + j*j + m) / i / j;
						double result = (1.0 * (j - i) * (j - i) + m) / i / j;
						const double eps = 1e-10;  // ¾«¶È·¶Î§
						if (result - (double)((int)result) < eps) {
							sum++;
						}
					}
				}
				printf("Case %d: %d\n", num, sum);
			}
			if (N)
			{
				printf("\n");
			}
		}
	}
	return 0;
}

int main()
{
	local();
    return 0;
}

