// 2203.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N, K, A;
bool checkLeftandRight(int *y, int pos) {
	int i = pos - 1;
	int countLeft = 0;
	int countRight = 0;
	while (i-1 && !y[i])
	{
		i--;
		countLeft++;
	}
	i = pos + 1;
	while (i != N+1 && !y[i])
	{
		i++;
		countRight++;
	}
	

	if (countLeft < A && countRight < A )
	{
		return false;
	}
	else if(countLeft >= A && countRight >= A)
	{
		if (countLeft > countRight)
		{
			for (int i = pos - 1; i >= pos - A; i--)
			{
				y[i] = 1;
			}
		}
		else
		{
			for (int i = pos + 1; i <= pos + A; i++)
			{
				y[i] = 1;
			}
		}
		return true;
	}
	else if (countLeft >= A)
	{
		for (int i = pos - 1; i >= pos - A; i--)
		{
			y[i] = 1;
		}
	}
	else if (countRight >= A)
	{
		for (int i = pos + 1; i <= pos + A; i++)
		{
			y[i] = 1;
		}
	}
	return true;
}
int main()
{
	int M;
	int *x;
	int *y;
	while (scanf("%d%d%d",&N,&K,&A)!=EOF)
	{
		scanf("%d",&M);
		x = new int[M+1];
		y = new int[N+1];
		for (int i = 1; i <= N; i++)
		{
			y[i] = 0;
		}
		for (int i = 1; i <= M; i++)
		{
			scanf("%d",&x[i]);
			y[x[i]] = 1;
		}
		bool flag = false;
		for (int i = 1; i < K; i++)
		{

			if (!checkLeftandRight(y, x[i])) {
				printf("%d\n",i);
				flag = true;
				break;
			}
			K--;
		}
		if (!flag)
		{
			printf("-1\n");
		}
		delete x;
		delete y;
	}
    return 0;
}

