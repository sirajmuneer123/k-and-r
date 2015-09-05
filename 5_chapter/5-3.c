/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s .
*/
#include<stdio.h>
void strcat(char *s,char *t);
main()
{
	char s[]="siraj";
	char t[]="muneer";
	strcat(s,t);
	printf("%s\n",s);
}
void strcat(char *s,char *t)
{
	while(*s!='\0')
		*++s;
	while((*s=*t)!='\0'){
		*++s;
		*++t;
	}
}
