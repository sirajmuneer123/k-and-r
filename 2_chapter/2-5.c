/*
Exercise 2-5. Write the function any(s1,s2) , which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 .
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/
#include<stdio.h>
int any(char s1[100],char s2[100]);
main()
{
	char s1[100]="siraj";
	char s2[100]="qqqqqqqqqqqqqqqqqkkdnbdbd";
	int a;
	a=any(s1,s2);
	if(a!=-1)
		printf("the character present in %d position of s1 !!\n",a);
	else
		printf("s1 contains no characters from s2.\n");
}
int any(char s1[],char s2[])
{
	int i,j,k,flag;
	for(i=j=0;s1[i]!='\0';i++){
		flag=0;
		for(k=0;s2[k]!='\0'&&flag==0;k++){
			if(s1[i]==s2[k])
				return i+1;
			
		}	
	}
	return -1;
		

}
