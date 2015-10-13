// 1004.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;
int main()
{
	int n;
	map<string,int> a;
	map<string, int>::iterator iterator;
	char temp_s[15];
	while (scanf("%d",&n)!=EOF)
	{
		if (!n)
			break;

		for (int i = 0; i < n; i++)
		{
			scanf("%s",temp_s);
			bool flag = false;
			for (iterator = a.begin(); iterator != a.end(); iterator++)
			{
				
				if (iterator->first == temp_s)
				{
					a[temp_s] = a[temp_s]++;
					flag = true;
				}
			}
			if (!flag)
			{
				a.insert(pair<string,int>(temp_s,0));
			}
		}
		int sum = 0;
		string result;
		for (iterator = a.begin(); iterator != a.end(); iterator++)
		{

			if (iterator->second >= sum)
			{
				sum = iterator->second;
				result = iterator->first;
			}
		}
		printf("%s\n",result.c_str());
		a.clear();
	}
    return 0;
}

