/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or || .
*/
#include<stdio.h>
#define MAXLINE 1000
main()
{
	int i=0,c,flag=1;
	int lim=MAXLINE;
	char s[MAXLINE];
	while(flag==1){
		if(i<lim-1){
			if((c=getchar())!='\n'){
				if(c!=EOF){
					s[i]=c;
					++i;
				}
				else
					flag=0;
			}
			else
				flag=0;
		}
		else
			flag=0;
					
	}	
	s[i]='\0';
	printf("%s\n",s);


}
