/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s . Use it to
write a program that reverses its input a line at a time.
*/
#include<stdio.h>
#define MAXLINE 100
int getline1(char line[],int maxline);
void reverse(char line[],int length);
main()
{
	char line[MAXLINE];
	int d;
	while((d=getline1(line,MAXLINE))>0)
			reverse(line,d);	
}
int getline1(char s[],int limit)
{
	int i,c;
	for(i=0;i<limit-2&&(c=getchar())!=EOF&&c!='\n';++i)
		s[i]=c;
	if(c=='\n'){
		s[i]='\n';
		++i;
	}
	s[i]='\0';
	return i;
}
void reverse(char s[],int len)
{
	char temp[MAXLINE];
	int j=0,i;
	for(i=len-2;i>=0;i=i-1){
		temp[j]=s[i];
		j++;
	}
	temp[j]='\n';
	++j;
	temp[j]='\0';
	printf("%s",temp);		

}
