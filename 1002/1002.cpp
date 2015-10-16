// 1002.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
void bigNumber_add(char *c, char *d) {
	char e[1000];
	e[0] = 48;
	int strlenc = strlen(c);
	int strlend = strlen(d);
	if (strlenc < strlend) {
		//将位数高的转给c；
		char temp[1000];
		memcpy(temp, d, strlend);
		memcpy(d, c, strlenc);
		memcpy(c, temp, strlend);
		d[strlend] = '\n';
		int tempd;
		tempd = strlenc;
		strlenc = strlend;
		strlend = tempd;
	}
	int j = 0;
	int i;
	for (i = strlend - 1; i  >= 0 ; i--,j++) {
		e[j] = c[i + strlenc - strlend] + d[i] - 48;
	}
	for (i = strlenc - strlend - 1; i >= 0 ; i--)
	{
		e[j] = c[i];
		j++;
	}
	int num = strlenc;
	
	for (i = 0; i < strlenc - 1; i++)
	{
		e[i + 1] += (e[i] - 48) / 10;
		e[i] -= (e[i] - 48)/10 * 10;
	}
	if (e[i] > 58)
	{
		num++;
		e[i + 1] = 49;
		e[i] -= (e[i] - 48) / 10 * 10;;
	}
	for (int i = num - 1; i >= 0; i--)
	{
		printf("%d",e[i] - '0');
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d",&n);
	char c[1000], d[1000],e[1000];
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s",c,d);
		printf("Case %d:\n", i + 1);
		printf("%s + %s = ",c,d);
		bigNumber_add(c, d);
		if (i!=n-1)
		{
			printf("\n");
		}
	}
    return 0;
}

