// 1023.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void catalan() //求卡特兰数
{
	
}
int main()
{
	int n;
	catalan();

	int a[101][1000], b[101];
	int i, j, len, carry, temp;
	a[1][0] = b[1] = 1;
	len = 1;
	for (i = 2; i <= 100; i++)
	{
		for (j = 0; j < len; j++) //乘法
			a[i][j] = a[i - 1][j] * (4 * (i - 1) + 2);
		carry = 0;
		for (j = 0; j < len; j++) //处理相乘结果
		{
			temp = a[i][j] + carry;
			a[i][j] = temp % 10;
			carry = temp / 10;
		}
		while (carry) //进位处理
		{
			a[i][len++] = carry % 10;
			carry /= 10;
		}
		carry = 0;
		for (j = len - 1; j >= 0; j--) //除法
		{
			temp = carry * 10 + a[i][j];
			a[i][j] = temp / (i + 1);
			carry = temp % (i + 1);
		}
		while (!a[i][len - 1]) //高位零处理
			len--;
		b[i] = len;
	}
	while (scanf("%d",&n)!=EOF)
	{
		for (int i = b[n] - 1; i >=0; i--)
		{
			printf("%d",a[n][i]);
		}
		printf("\n");
		//printf("%I64d\n", Factorial(n) / (n+1));
	}
    return 0;
}

