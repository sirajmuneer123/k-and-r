/*
Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.
*/
#include<stdio.h>
main()
{
int c,d,f;
while((c=getchar())!=EOF){
	if (c!=' ')
	    putchar(c);
	else{	
		if ((d=getchar())!=' '){
			putchar(c);
			putchar(d);
		}
		else{	
			while((f=getchar())==' '){
				;	
			}
			putchar(' ');
			putchar(f);
		}
	}
}
}
