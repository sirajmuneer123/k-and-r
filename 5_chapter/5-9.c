/*
Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
indexing.
*/
#include<stdio.h>
int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);
static char daytab[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
main()
{
	int s;
	int day=3;
	int month=10;
	s=day_of_year(2014,12,10);
	month_day(2014,s,&month,&day);
	printf("%d  %d\n",day,month);
}
int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p=daytab[leap];
	while(--month){
		day +=*p++;
	}	
	return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	char *p;
	if(year<1){
		*pmonth=-1;
		*pday=-1;
		return ;
	}	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p=daytab[leap];
	for (i = 1; yearday > *p; p++,i++)
		yearday -= *p;
	*pmonth = i;
	*pday = yearday;
}
