// 1029.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <map>

using namespace std;
int main()
{
	int n,j;
	map<int, int> data;
	map<int, int>::iterator it;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i = 0; i < n; i++) {
			scanf("%d",&j);
			if (data.find(j)!=data.end())
			{
				data[j]++;
			}
			else {
				data.insert(pair <int,int>(j,0));
			}
		}
			it = data.begin();
		int num = it->first;
		int sum = it->second;
		it++;
		for (; it != data.end(); it++) {
			if (it->second > sum) {
				num = it->first;
				sum = it->second;
			}
		}
		printf("%d\n",num);
		data.clear();
	}

    return 0;
}

