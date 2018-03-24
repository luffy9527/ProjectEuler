// Problem 2 Even Fibonacci numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX 4000000

unsigned int fibonacci()
{	
	unsigned int a = 1, b = 2, c = 0;
	unsigned int res = b;
	while (true)
	{
		c = a + b;
		//cout<<c<<endl;
		if (c > MAX)
		{
			break;
		}
		if ((c&0x1) == 0)
		{
			res += c;
			//cout<<res<<endl;
		}
		a = b;
		b = c;		
	}

	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int res = fibonacci();
	cout<<res<<endl;
	return 0;
}

