/*
Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.
*/
#include<stdio.h>
int conversion(int fahr);
main()
{
int i;
for(i=0;i<=300;i=i+20)
	printf("%d\t%d\n",i,conversion(i));
return 0;
}
int conversion(int fahr)
{
	return 5*(fahr-32)/9;
}
