/*
Exercise 5-5. Write versions of the library functions strncpy , strncat , and strncmp , which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s . Full descriptions are in Appendix B.
*/
#include<stdio.h>
void strncpy(char *s,char *t,int n);
void strncat(char *s,char *t,int n);
int strncmp(char *s,char *t,int n);
main()
{
	char s[]="ksirajk";
	char t[]="ksiraj";
	printf("%d\n",strncmp(s,t,4));
}
void strncpy(char *s,char *t,int n)
{
	int i;
	for(i=0;i<n&&(*s=*t)!='\0';*++s,*++t,++i)
			;
	*s='\0';
}
strncat(char *s,char *t,int n)
{
	int i=0;
	for(;*t!='\0';*++t)
		;
	for(i=0;i<n&&(*t=*s)!='\0';*++t,*++s,++i)
		;
	*t='\0';
}
int strncmp(char *s, char *t,int n)
{
	int i;
	for (i=0;i<n && *s == *t; s++, t++,i++)
		printf("equal...%d--->%d\n",*s,*t);
	printf("%d-->%d\n",*s,*t);
	if(i==n)
		return *(--s) - *(--t);
	else
		return *s-*t;
}
