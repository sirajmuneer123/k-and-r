/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.
*/
#include<stdio.h>
#define MAXLINE 100
int getline1(char line[],int maxline);
int remove1(char line[]);
main()
{
	int d;
	char line[MAXLINE];
	while((d=getline1(line,MAXLINE))>0)
		if(remove1(line)>0)
			printf("%s",line);
			


}
int getline1(char s[],int limit)
{
	int c,i=0;
	for(i=0;i<limit-1&&(c=getchar())!=EOF&&c!='\n';++i)
		s[i]=c;
	if(c=='\n'){
		s[i]='\n';
		++i;
	}
	s[i]='\0';
	return i;
}
int remove1(char s[])
{
	int i=0;
	while(s[i]!='\n')
		++i;
	--i;
	while(i>=0&&(s[i]==' '||s[i]=='\t'))
		--i;
	if(i>=0){
		++i;
		s[i]='\n';
		++i;
		s[i]='\0';
	}	
	return i;
}
