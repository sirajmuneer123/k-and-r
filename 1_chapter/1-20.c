/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
*/
#include<stdio.h>
#define TAB 8
main()
{
	int c,pos=1;
	int ns=0;  //number of space to be added
	while((c=getchar())!=EOF){
		if(c=='\t'){
			ns=TAB-(pos-1)%TAB;
			while(ns>0){
				putchar(' ');
				++pos;
				--ns;
			}
		}
		else if (c=='\n'){
			putchar(c);
			pos=1;
		}
		else{
			putchar(c);
			++pos;
		}
	}
}
