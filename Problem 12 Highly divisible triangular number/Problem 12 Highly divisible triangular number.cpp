// Problem 12 Highly divisible triangular number.cpp : Defines the entry point for the console application.
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


vector<long long> primes;

#define max_num  100000000

bool isPrime[max_num] = {0};

void sumPrimes(long long n)
{	
	int i = 2;

	memset(isPrime, 1, sizeof(isPrime));
	isPrime[1] = false;
	while (i < n)
	{
		if (!isPrime[i])
		{
			i++;
			continue;
		}
		
		primes.push_back(i);

		int k = 2;
		while (k*i < n)
		{
			isPrime[k*i] = false;
			k++;
		}
		i++;		
	}

}

int getNum(long long n)
{
	long root = (long)sqrt((double)n);
	int ret = 0;
	for (long i = 1; i < root; i++)
	{	
		if (n % i == 0)
		{
			ret++;
		}
	}
	ret *= 2;
	
	if (root * root == n)
	{
		ret++;
	}
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*sumPrimes(max_num);
	cout<<"end of prime"<<endl;*/

	int n = 2;	
	int factor = 1;
	long long triangle = 1;
	while (factor < 500)
	{
		triangle = (n * (n + 1)) >> 1;
		factor = getNum(triangle);
		++n;
	}
	cout<<"the answer is: "<<triangle<<endl;
//	while (true)
//	{
//		long long triangle = (n * (n + 1)) >> 1;
//		n++;
//
//		if (triangle >= max_num)
//		{
//			cout<<"Ops"<<endl;
//			return -1;
//		}
//		
//// 		if (isPrime[triangle])
//// 		{
//// 			continue;
//// 		}
//
//		int f = 1;
//		long long t = triangle;
//		int j = 0;
//		while (t)
//		{
//			int x = 1;
//			
//			if (t < primes[j])
//			{
//				break;
//			}
//			while ((t % primes[j] == 0))
//			{
//				++x;
//				t /= primes[j];
//			}
//			f *= x;
//			j++;
//		}
//		cout<<triangle<<"   "<<f<<endl;
//		if (f > 500)
//		{
//			break;
//		}
//	}

	return 0;
}

