// 1040.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
int main()
{
	int i, n;
	char c[10001];
	char result[10001];
	queue<char> a;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", c);
		char prev = c[0];
		int count = 1;
		for (int i = 1; i < strlen(c); i++) {
			if (c[i] == prev) {
				count++;
			}
			else {
				if (count == 1) {
					printf("%c", prev);
				}
				else {
					printf("%d%c", count, prev);
				}
				prev = c[i];
				count = 1;
			}
		}
		if (count == 1) {
			printf("%c", prev);
		}
		else {
			printf("%d%c", count, prev);
		}
		printf("\n");
	}
	return 0;
}
