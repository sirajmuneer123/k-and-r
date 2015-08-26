/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2 .
*/
#include<stdio.h>
void squeeze(char s1[100],char s2[100]);
main()
{
	char s1[100]="sirajmuneer";
	char s2[100]="siraj";
	squeeze(s1,s2);
}
void squeeze(char s1[],char s2[])
{
	int i,j,k,flag;
	for(i=j=0;s1[i]!='\0';i++){
		flag=0;
		for(k=0;s2[k]!='\0'&&flag==0;k++){
			if(s1[i]==s2[k])
				flag=1;
			
		}
		if(flag==0)
			s1[j++]=s1[i];
			
	}
	s1[j]='\0';
	printf("%s\n",s1);
}
