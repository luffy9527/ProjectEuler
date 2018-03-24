// Problem 10 Summation of primes.cpp : Defines the entry point for the console application.
//

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

using namespace std;

vector<long long> primes;

bool isPrime[2000000] = {0};

long long sumPrimes2(long long n)
{
	long long sum = 0;
	int i = 2, j = 2;

	memset(isPrime, 1, sizeof(isPrime));
	isPrime[1] = false;
	while (i < n)
	{
		if (!isPrime[i])
		{
			i++;
			continue;
		}

		sum += i;
		
		int k = 2;
		while (k*i < n)
		{
			isPrime[k*i] = false;
			k++;
		}
		i++;		
	}

	return sum;
}

long long sumPrimes(long long n)
{
	long long sum = 2;
	
	primes.clear();
	primes.push_back(2);
	
	long long k = 3;
	while (k < n)
	{
		int i = primes.size() -1;
		for (; i >= 0; --i)
		{
			if (k % primes[i] == 0)
			{			
				break;
			}
		}

		if (i < 0)
		{
			cout<<k<<endl;
			primes.push_back(k);
			sum += k;
		}

		k += 2;
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<sumPrimes2(2000000)<<endl;
	return 0;
}

