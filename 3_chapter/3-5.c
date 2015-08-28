/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s . In particular, itob(n,s,16) formats s as a
hexadecimal integer in s .
*/
#include<stdio.h>
#include<string.h>
int itob(int n,char s[],int b);
void reverse(char s[]);
main()
{
	char s[100];
	itob(100,s,16);
	reverse(s);

}
int itob(int n,char s[],int b)
{
	int i=0,mode,sign;
	if((sign=n)<0)
		n=-n;
	do{
		mode=n%b;
		if(mode<=9)
			s[i++]=mode+'0';
		else
			s[i++]=mode+'a'-10;
	}
	while((n/=b)>0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0';
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
