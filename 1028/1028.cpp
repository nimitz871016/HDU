// 1028.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<math.h>
int getLastDigit(long a) {
	int n = 0;
	while (a / (long)pow(10,n)!=0)
	{
		n++;
	}
	long result = a;
	while (n!=1) {
		result = result - result / (long)pow(10, n - 1)*pow(10, n - 1);
		n--;
	}
	return result;
} 

int main()
{
	long a;
	int b[10][4] = { 0,0,0,0,1,1,1,1,
				   2,4,8,6,
				3,9,7,1,
				4,6,4,6,
				5,5,5,5,
				6,6,6,6,
				7,9,3,1,
				8,4,2,6,
				9,1,9,1 };
	int n;
	scanf("%d", &n);
		while (n--)
		{

			scanf("%ld", &a);
			printf("%d\n", b[getLastDigit(a)][a % 4 == 0 ? 3 : a % 4 - 1]);
		}
	return 0;
}

