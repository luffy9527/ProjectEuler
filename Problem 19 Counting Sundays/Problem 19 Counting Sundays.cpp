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

class Date
{
public:
	int year;
	int month;
	int day;
	int week;
	int daysnum2base; // 1900/1/1
	
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
		week = 1;
		daysnum2base = 0;
	}

	Date(int y, int m, int d, int w, int days)
	{
		year = y;
		month = m;
		day = d;
		week = w;
		daysnum2base = days;
	}

public:
	bool operator ==(Date d)
	{
		return (year == d.year) && (month == d.month) && (day == d.day);
	}
	
	bool isSunDayOnFirstDay()
	{
		return  (day == 1 && week == 7);		
	}
	void goNextDay()
	{
		//printf("%d-%d-%d %d %d \n", year, month, day, week, daysnum2base);

		day++;
		week++;
		if (week > 7)
		{
			week = 1;
		}
		daysnum2base++;

		if (day > 28)
		{
			switch(month)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day > 31)
				{
					day = 1;
					month++;
					if (month > 12)
					{
						month = 1;
						year++;
					}
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30)
				{
					day = 1;
					month++;
					if (month > 12)
					{
						month = 1;
						year++;
					}
				}
				break;
			case 2:	
				bool leapyear = false;
				if (year % 100 == 0)
				{
					if (year % 400 == 0)
					{
						leapyear = true;
					}
				}
				else if (year % 4 == 0)
				{
					leapyear = true;
				}

				if ((leapyear && day > 29)
					|| (!leapyear && day > 28))
				{
					day = 1;
					month++;				
				}
				break;
			}
		}
	}
};

int calcSundays()
{
	Date from(1901, 1, 1, 2, 365);
	Date to(2000, 12, 31, 7, 36889);

	int cnt = 0;

	while (!(from == to))
	{
		from.goNextDay();
		if (from.isSunDayOnFirstDay())
		{
			cnt++;
		}
	}
	return cnt;
}

void calsDay(Date &date)
{
	Date curDate(1900, 1, 1);
	
	while (!(curDate == date))
	{
		curDate.goNextDay();
	}
	date = curDate;
}



int main()
{
	Date date(1901, 1, 1);

	calsDay(date);
	printf("%d-%d-%d %d %d \n", date.year, date.month, date.day, date.week, date.daysnum2base);

	date.year = 2000;
	date.month = 12;
	date.day = 31;
	calsDay(date);
	printf("%d-%d-%d %d %d \n", date.year, date.month, date.day, date.week, date.daysnum2base);

	cout<<calcSundays();

	return 0;
}

