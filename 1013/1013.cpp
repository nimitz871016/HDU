// 1013.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int *split(long a,int *count) {
	int n = 0;
	while (a / (long)pow(10, n) != 0)
	{
		n++;    

	}
	*count = n;
	long sum = a;
	int *result = (int *)malloc(sizeof(int)*n);
	while (n != 0) {
		result[n - 1] = sum / (long)pow(10, n - 1);
		sum = sum - sum / (long)pow(10, n - 1)*pow(10, n - 1);
		n--;
	}
	return result;
}
int main()
{
	char s[1010];
	while (scanf("%s",s)!=EOF)
	{
		if (strlen(s)==1 && s[0] == '0')
		{
			break;
		}
		int *b = (int *)malloc(sizeof(int)*strlen(s));
		for (int i = 0; i < strlen(s); i++)
		{
			b[i] = s[i] - '0';
		}
		int sum = 0;
		int number;
			for (int i = 0; i < strlen(s); i++) {
				sum += b[i];
			}
			while(sum >= 10)
			{
				sum %= 9;
			}
			if (sum == 0) {
				sum = 9;
			}
		printf("%d\n", sum);
	}
	
    return 0;
}

