/*
Exercise 4-13. Write a recursive version of the function reverse(s) , which reverses the
string s in place.
*/
#include<stdio.h>
#include<string.h>
int reverse(char s[],char rs[]);
main()
{
	char rs[100];
	char s[100]="nihal123456789";
	printf("len= %d\n",strlen(s));
	reverse(s,rs);
	printf("%s\n",rs);
}
int reverse(char s[],char rs[])
{
	
	static int i=0,k=0;
	static int j=0;
	if(s[i++]!='\0')
		reverse(s,rs);
	if(i-2>=2){
	rs[j++]=s[i-2];
	--i;
	}
	else{
		s[j]='\0';
	}		
}
