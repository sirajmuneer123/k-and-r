/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/
#include<stdio.h>
#include<string.h>
void itoa(int n,char s[],int w);
void reverse(char s[]);
main()
{
	char s[100];
	itoa(-100,s,5);
}
void itoa(int n,char s[],int w)
{
	int i,sign;
	if ((sign=n)<0)
		n=-n;
	i=0;
	do{
		s[i++]= n % 10 + '0';
		
	}while((n /=10)>0);
	if(sign<0)
		s[i++]='-';
	while(i<w)
		s[i++]=' ';
	s[i]='\0';
	reverse(s);
}
void reverse(char s[])
{
	int i,j;
	char temp[100];
	for(i=strlen(s)-1,j=0;i>=0;--i,++j)
		temp[j]=s[i];
	temp[j]='\0';
	printf("%s\n",temp);
}
