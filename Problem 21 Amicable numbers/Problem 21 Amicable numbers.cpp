// Problem 16 Power digit sum.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define MAX_NUM 10000

int D[MAX_NUM] = {0};

int calcD(int n)
{
	int ret = 1;

	for (int i=2; i < n; i++)
	{
		if (n%i==0)
		{
			ret += i;
		}
	}

	return ret;
}

int main()
{
	int sum = 0;
	int d = 0;
	for (int i = 2; i < MAX_NUM; i++)
	{
		if (D[i] == 0)
		{
			D[i] = calcD(i);
		}
	}

	for (int i = 2; i < MAX_NUM; i++)
	{
		if (D[i] == 0)
		{
			continue;
		}

		if (D[i] < MAX_NUM && D[D[i]] == i && (i != D[i]))
		{
			sum += i + D[i];
			
			cout<<i<<":"<<D[i]<<endl;
			cout<<D[i]<<":"<<D[D[i]]<<endl;

			D[i] = 0;
			D[D[i]] = 0;
		}
		else if (D[i] >= MAX_NUM)
		{
			if (i == calcD(D[i]))
			{
				sum += i;

				cout<<i<<":"<<D[i]<<endl;
				cout<<D[i]<<":"<<D[D[i]]<<endl;

			}
		}
	}
	
	cout<<sum<<endl;
	return 0;
}

