// Problem 9 Special Pythagorean triplet.cpp : Defines the entry point for the console application.
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
#include <cmath>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 2, b = 2, c = 0;

	for (int a = 2; a < 1000; a++)
	{
		for (int b = 500 - a + 1; b < 1000; b++)
		{
			if ((a*b)%1000 != 0)
			{
				continue;
			}

			if ((1000*(a+b) - a*b) == 500000)
			{
				c = 1000 - a - b;
				cout<<a<<"  "<<b<<" "<<sqrt(double(a*a+b*b))<<endl;
				cout<<a*b*c<<endl;
				return 0;
			}
		}
	}
	return 0;
}

