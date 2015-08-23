/*
Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input.
*/
#include<stdio.h>
main()
{
int chara,i;
int count[96];
for(i=0;i<96;i++)
	count[i]=0;
while((chara=getchar())!=EOF){
	if(chara>=32&&chara<=128){
		++count[chara-32];
	}
}
printf("CHARACTORS   FREQUENCIES\n");
for(i=0;i<96;i++)
	printf("%c  ---------  %d\n",i+32,count[i]);
}
