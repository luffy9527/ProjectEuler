// Problem 16 Power digit sum.cpp : Defines the entry point for the console application.
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

vector<string> namelist;

int worth(string &name)
{
	int value = 0;
	
	for (int i =0; i < name.length(); i++)
	{
		value += name[i] - 'A' + 1;
	}

	return value;
}

int main()
{
	int sum = 0;
	
	string input;
	cin>>input;
	
	int offset = input.find("\"", 0);

	while (offset != -1)
	{
		int next = input.find("\"", offset+1);
		
		if (next == -1)
		{
			break;
		}
		string name = input.substr(offset + 1, next - offset - 1);

		offset = input.find("\"", next + 1);

		cout<<name<<endl;;

		namelist.push_back(name);
	}
	
	sort(namelist.begin(), namelist.end());

	int namevalue = 0;
	for (int i = 0; i < namelist.size(); i++)
	{	
		namevalue += (i + 1) * worth(namelist[i]);
	}

	cout<<namevalue<<endl;
	return 0;
}

