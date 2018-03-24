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

vector<int> digits;

void display(vector<int> &digits)
{
	for (int j = 0; j < digits.size(); j++)
	{
		cout<<digits[digits.size() - j - 1];
	}
	cout<<endl;
}
int calcPowerDigit(int n)
{
	digits.push_back(1);
	int c = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < digits.size(); j++)
		{
			digits[j] *= i;
			digits[j] += c;

			c = digits[j] / 10;
			digits[j] = digits[j] % 10;
		}

		while (c)
		{
			digits.push_back(c % 10);
			c /= 10;
		}
		cout<<i << ":";
		display(digits);
	}

	int ret = 0;
	for (int j = 0; j < digits.size(); j++)
	{
		ret += digits[j];
	}
	return ret;
}

int main()
{
	cout<<calcPowerDigit(100)<<endl;
	return 0;
}

