/*
Exercise 5-4. Write the function strend(s,t) , which returns 1 if the string t occurs at the
end of the string s , and zero otherwise.
*/
#include<stdio.h>
int strend(char *s,char *t);
main()
{
	char s[]="muneersiraj";
	char t[]="siraj";
	printf("%d\n",strend(s,t));
}
int strend(char *s,char *t)
{
	char *ss=s;
	char *st=t;
	for( ;*s!='\0';*++s)
		;
	for( ;*t!='\0';*++t)
		;
	for( ;*s==*t;*--s,*--t)
		if(st==t)
			break;
	if(st==t||ss==s)
		return 1;
	else
		return 0;
	
}
