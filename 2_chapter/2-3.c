/*
Exercise 2-3. Write a function htoi(s) , which converts a string of hexadecimal digits
(including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0
through 9 , a through f , and A through F .
*/
#include<stdio.h>
int htoi(char s[100]);
main()
{
	int i=0;
	char s[1000]="0x123";
	printf("the hex value = %d\n",htoi(s));
}
int htoi(char s[])
{
	int i=0,flag=1,hex,n=0;
	if(s[i]=='0'){
		++i;
		if(s[i]=='x'||s[i]=='X'){
			++i;
			while(flag==1&&s[i]!='\0'){
				if(s[i]>='0' &&s[i]<='9')
					hex=s[i]-'0';
				else if(s[i]>='a'&& s[i]<='f')
					hex=s[i]-'a'+10;
				else if(s[i]>='A'&& s[i]<='F')
					hex=s[i]-'A'+10;
				else
					flag=0;
				if(flag==1){
					n=n*16+10;
					++i;
				}
			}
		}
		else
			printf("not hexadecimal value!!!");
	}
	else
		printf("not a hexadecimal value!!!!");	
	return n;
	
	
}
