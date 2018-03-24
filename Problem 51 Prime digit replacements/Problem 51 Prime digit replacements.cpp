// Problem 51 Prime digit replacements.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "stdafx.h"
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

bool isPrime(int n)
{
	if (n& 1 == 0)
	{
		return false;
	}

	int f = sqrt((double)n);
	for (int k = 2; k <= f; k++)
	{
		if (n % k == 0)
		{
			return false;
		}
	}
	return true;
}

string pattern5[] = {
	"***dd",
	"d***d",
	"*d**d",
	"**d*d",
};

string pattern6[] = {
	"***ddd",
	"d***dd",
	"dd***d",
	"*d**dd",
	"*dd**d",	
	"d*d**d",
	"**d*dd",	
	"**dd*d",
	"d**d*d",
	"*d*d*d",
};


int check(const string &pattern, vector<int> digits)
{
	int offset = 0;
	int base = 1;
	vector<int> vi;
	for (int i = 0; i < pattern.size(); i++)
	{
		if (pattern[pattern.size() - 1 - i] == '*')
		{
			offset += base;
		}
		else
		{
			vi.push_back(base);
		}

		base *= 10;
	}
	int n = 0;
	for (int i = 0; i < vi.size(); ++i)
	{
		n += vi[i]*digits[i];
	}
	int cnt = 0;
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		int temp = n + i * offset;
		
		if (isPrime(temp) && temp > 1000)
		{
			cout<<"info: "<<temp<<endl;
			cnt++;
			if (!result)
			{
				result = temp;			
			}
		}
	}
	if (cnt >= 8)
	{
		cout<<"result: "<<result<<endl;
		return true;
	}
	return false;

}

int _tmain(int argc, _TCHAR* argv[])
{
	for (int t = 0; t < 10; t++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < 10; k++)
				{
					vector<int> vi;
					vi.push_back(i);
					vi.push_back(j);
					vi.push_back(k);

					if (check(pattern6[t], vi))
					{
						return 0;
					}
				}
			}
		}
	}
	
	return 0;
}

