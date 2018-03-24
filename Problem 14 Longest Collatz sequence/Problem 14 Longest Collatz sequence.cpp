// Problem 14 Longest Collatz sequence.cpp : Defines the entry point for the console application.
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


#define ONE_MILLION 1000000

int arr[ONE_MILLION + 1] = {0};


unsigned int calc(int n)
{
	if (n == 1)
	{
		return 1;
	}
	unsigned int cnt = 1;
	int k = n;
	cout<<k<<endl;
	while ((k != 1))
	{
		if (k%2 == 0)
		{
			k = k/2;
		}
		else
		{
			k = 3*k+1;
		}

		cnt++;

		if ((k < ONE_MILLION) && (arr[k] != 0))
		{
			break;
		}
		
	}
	arr[n] = cnt + arr[k];
	return cnt;
}
int _tmain(int argc, _TCHAR* argv[])
{
	arr[1] = 1;
	arr[2] = 2;
	unsigned int longestn, longest, k, n, cnt;
	n = 3;
	longest = 0;
	while (n < ONE_MILLION)
	{
		k = n;
		cnt = 1;
		//cout<<n<<endl;
		while ((k > n) || (arr[k] == 0))
		{
			if (k%2 == 0)
			{
				k = k/2;
			}
			else
			{
				k = 3*k+1;
			}

			cnt++;
		}
		arr[n] = cnt + arr[k];

		if (longest < arr[n])
		{
			longestn = n;
			longest = arr[n];

			cout<<n<<"  "<<longest<<endl;
		}

		n++;
	}


	return 0;
}

