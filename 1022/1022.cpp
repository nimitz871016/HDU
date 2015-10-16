// 1022.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;
int main()
{
	int n;
	stack<int> a;
	queue<int> b;
	char *c,*d;
	while (scanf("%d",&n)!=EOF)
	{
		c = (char *)malloc(sizeof(char)*n);
		d = (char *)malloc(sizeof(char)*n);
		scanf("%s",c);
		scanf("%s",d);
		a.push(c[0]);
		b.push(1);
		int i, j;
		i = 1;
		j = 0;
		while (true)
		{
			bool flag = false;
			if (a.top() != d[j] && i !=n) {
				a.push(c[i]);
				b.push(1);
				i++;
				flag = true;
				//continue;
			}
			else if(a.top()== d[j]){
				a.pop();
				b.push(-1);
				j++;
				flag = true;
			}
			if (!flag) {
				break;

			}
			if (a.empty() && i !=n)
			{
				a.push(c[i]);
				b.push(1);
				i++;
			}
			if (i == n&&j == n) {
				break;
			}
		}
		if (a.empty())
		{
			printf("Yes.\n");
			while (!b.empty())
			{
				if (b.front()==1)
				{
					printf("in\n");
				}
				else {
					printf("out\n");
				}
				b.pop();
			}
			printf("FINISH\n");
		}
		else {
			printf("No.\nFINISH\n");
		}
		
		//free(c);
		//free(d);
		while (!a.empty())
		{
			a.pop();
		}
		while (!b.empty())
		{
			b.pop();
		}
	}

    return 0;
}

