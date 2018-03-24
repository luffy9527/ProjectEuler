// Problem 15 Lattice paths.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


long long C(long n, long m)
{
	if (0 == m)
	{
		return 1;
	}
	
	bool processed[41] = {true, true, false};
	for (long i = n - m + 1; i <= n; i++)
	{
		processed[i] = true;
	}

	long long ret = 1;

	for (long i = m+1; i<=n; i++)
	{
		ret *= i;
		
		for (long j = 2; j <= n-m; j++)
		{
			if ((!processed[j]) && (ret % j == 0))
			{
				ret /= j;
				processed[j] = true;
			}
		}
	}
	
	for (long j = 2; j <= n-m; j++)
	{
		if ((!processed[j]))
		{
			ret /= j;
			processed[j] = true;
		}
	}

	return ret;

}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<C(40, 20)<<endl;

	return 0;
}

