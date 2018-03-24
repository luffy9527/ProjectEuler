// Problem 17 Number letter counts.cpp : Defines the entry point for the console application.
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

string digits_1_9[10] = { 
"one",
"two",
"three",
"four",
"five",
"six",
"seven",
"eight",
"nine",
"ten"
};
string digits_11_19[10] = 
{
"eleven", 
"twelve",
"thirteen",
"fourteen",
"fifteen",
"sixteen",
"seventeen",
"eighteen",
"nineteen",
};

string digits10[10] = {
	"",
	"",// 1x
	"twenty",// 2x
	"thirty",// 3x
	"forty", // 4x
	"fifty", // 5x
	"sixty", // 6x
	"seventy", // 7x
	"eighty", // 8x
	"ninety", // 9x
};

void translatenum(int n, string &result)
{
	if (n <= 10)
	{
		result = digits_1_9[n - 1];
	}
	else if (n < 20)
	{
		result = digits_11_19[n - 11];
	}
	else if (n < 100)
	{
		result = digits10[n/10];
		if (n % 10 != 0)
		{
			result = result + "-" + digits_1_9[n%10 - 1];
		}
	}
	else if (n < 1000)
	{
		result = digits_1_9[n/100 - 1] + " hundred ";
		if (n % 100 != 0)
		{
			string x;
			translatenum(n%100, x);
			result = result + "and " + x;
		}		
	}
	else if (n == 1000)
	{
		result = "one thousand";
	}

}

int calclength(string& s)
{
	int ret = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && s[i] != '-')
		{
			ret++;
		}
	}
	return ret;
}

int main()
{
	string s;
	int count = 0;
	for (int i = 1; i <= 1000; i++)
	{
		translatenum(i, s);
		count += calclength(s);
	}
	cout<<count<<endl;

	return 0;
}

