// Problem 3 Largest prime factor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> primes;

void getPrimes()
{
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	
	long long n = 9ll;
	int k = 5;
	while (k <= 10001)
	{
		int i = primes.size() -1;
		for (; i >= 0; --i)
		{
			if (n % primes[i] == 0)
			{			
				break;
			}
		}
		
		if (i < 0)
		{
			cout<<k<<" : "<<n<<endl;
			k++;
			primes.push_back(n);
		}

		n += 2;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	getPrimes();
	
	long long n = 600851475143ll, temp;
	vector<long long> factors;

	while (true)
	{
		temp = n;
		for (int i = 0; i < primes.size(); ++i)
		{
			if (n % primes[i] == 0)
			{
				factors.push_back(primes[i]);
				n = n / primes[i];
				cout<<"factor : "<<primes[i]<<endl;
			}
		}
		if (temp == n)
		{
			break;
		}
	}

	return 0;
}

