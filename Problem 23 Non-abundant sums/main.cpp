

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

#define MAX_ABUNDANT_NUM 28123 

bool isAbundantNum(int n)
{
	int limit = (int)n/2;
	int sum = 1;
	for (int i = 2; i <= limit; i++)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}

	if (sum > n)
	{
		return true;
	}

	return false;
}

bool isIntegerWritebyTwoAbundants(int n, bool nums[])
{
	for (int i = 2; i <= n - 1; i++)
	{
		if (nums[i] && nums[n - i])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	bool nums[MAX_ABUNDANT_NUM + 1] = {0,};
	
	for (int i = 1; i <= MAX_ABUNDANT_NUM; i++)
	{
		nums[i] = isAbundantNum(i);


	}

	int sum = 0;
	
	for (int i = 1; i <= MAX_ABUNDANT_NUM; i++)
	{
		if (!isIntegerWritebyTwoAbundants(i, nums))
		{
			sum += i;
			//cout<<"n is: "<<i<<endl;
		}
	}
	
	cout<<sum<<endl;
	return 0;
}