// Problem 18 Maximum path sum I.cpp : Defines the entry point for the console application.
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

#define MAXSIZE 100

int triangle[MAXSIZE][MAXSIZE] = {0};

int sum[MAXSIZE][MAXSIZE] = {0};

int calcMaxPathSum()
{	
	for (int i = 0; i < MAXSIZE; i++)
	{
		sum[MAXSIZE - 1][i] = triangle[MAXSIZE - 1][i];
	}

	for (int i = MAXSIZE - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			sum[i][j] = triangle[i][j] + max(sum[i+1][j], sum[i+1][j+1]);
		}
	}

	return sum[0][0];
}

int main()
{
	int d = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &triangle[i][j]);			 
		}
	}

	cout<<calcMaxPathSum()<<endl;
	return 0;
}

