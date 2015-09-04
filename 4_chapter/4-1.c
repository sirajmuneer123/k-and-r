/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s , or -1 if there is none.
*/
#include<stdio.h>
#include<string.h>
int strindex(char s[],char t);
main()
{
	char s[100]="siraj muneerk";
	char t='d';
	printf("%d\n",strindex(s,t));
}
int strindex(char s[],char t)
{
	int i;
	for(i=strlen(s)-1;i>=0;--i)
		if(s[i]==t)
			return i+1;
	return -1;
}
