/*
Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/
#include<stdio.h>
main()
{
int nc=0;
char c;
while((c=getchar())!=EOF){
	if (c=='\n'||c==' '||c=='\t')
		++nc; 
}
printf("%d\n",nc);

}
