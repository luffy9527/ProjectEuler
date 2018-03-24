// Problem 6 Sum square difference.cpp : Defines the entry point for the console application.
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



int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0, b = 0;
	for (int i = 1; i <= 100; i++)
	{
		a += i*i;

		b += i;
	}
	
	b *= b;
	cout<<b - a<<endl;
	return 0;
}

