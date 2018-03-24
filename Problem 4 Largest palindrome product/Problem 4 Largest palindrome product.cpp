// Problem 4 Largest palindrome product.cpp : Defines the entry point for the console application.
//

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

using namespace std;

bool isPalindrome(int x)
{
	vector<int> digits;
	while (x)
	{
		digits.push_back(x%10);
		x /= 10;
	}
	
	int k = digits.size() / 2;
	for (int i = 0, j = digits.size() - 1; i < k; ++i, j--)
	{
		if (digits[i] != digits[j])
		{
			return false;
		}
	}

	return true;
}
int getMaxPalindrome()
{
	int max = 0;
	for (int i = 999; i > 100; i--)
	{
		for (int k = 999; k >= i; k--)
		{
			int x = i * k;
			if (x < max)
			{
				continue;
			}
			if (x & 1 == 0)
			{
				//continue;
			}
			cout<<i <<" * "<<k<<endl;
			if (isPalindrome(x))
			{
				
				if (max < x)
				{
					max = x;
				}
				//return x;
			}
		}
	}
	cout<<"max palindrome is : "<<max<<endl;
	return max;
}

int _tmain(int argc, _TCHAR* argv[])
{
	getMaxPalindrome();
	return 0;
}

