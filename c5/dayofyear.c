/* 
Exercise 5-8. 
There is no error checking in day_of_year or month_day. 
Remedy this defect.
*/

#include <stdio.h>

#define ERROR -1

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int , int , int);
int month_day(int, int, int *, int *);

void main(void) {
	int month, day, year, retval;
	char months[][4] = {"\0", "Jan", "Fev", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};

	retval = month_day(2021, 45, &month, &day);

	if (!retval)
		printf("%s, %d\n", months[month], day);
	else
		printf("ERROR\n");

	retval = day_of_year(2021, 2, 14);

	if (retval)
		printf("%d\n", retval);
	else
		printf("ERROR\n");
}

int day_of_year(int year, int month, int day) {
	if (month <= 0 || month > 13)
		return ERROR;

	int i, leap;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	
	if (day > daytab[leap][month])
		return -1;
	
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday) {
	if (yearday > 366 || yearday < 1)
		return ERROR;

	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	
	*pmonth = i;
	*pday = yearday;
	return 0;
}