/*
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.

*/
#include<stdio.h>
main()
{
char temp[200];
int i=0,c_count=0,c;
while((c=getchar())!=EOF){
	if(c=='\n'){
		temp[i]='\n';
		++i;
		temp[i]='\0';
		if(c_count>80)
			printf("%s",temp);
		i=0;
		c_count=0; 
	}
	else{
	temp[i]=c;
	i=i+1;
	++c_count;
	}
}
}
