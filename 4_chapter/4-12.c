/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa ; that is, convert
an integer into a string by calling a recursive routine.
*/
#include<stdio.h>
#include<string.h>
void aitoa(int n,char s[]);
main()
{
	char s[100];
	aitoa(123456,s);
	printf("%s\n",s);
}
void aitoa(int n,char s[])
{
	static int i;
	int sign;
	if(n<0)
		sign=n;
	i=0;
	if(n/10){
		aitoa(n/10,s);
	}
	else if(sign<0)
			s[i++]='-';
	s[i++]=abs(n)%10+'0';
	s[i]='\0';


}
