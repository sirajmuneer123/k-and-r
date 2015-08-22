/*
Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t , each
backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an
unambiguous way.
*/
#include<stdio.h>
main()
{
int chara;
while((chara=getchar())!=EOF){
	if (chara=='\t' ||chara=='\b' ||chara=='\\'){
		if(chara=='\t'){
			putchar('//');
			putchar('t');
		}
		else if(chara=='\b'){
			putchar('//');
			putchar('b');
		}
		else{
			putchar('\\');
			putchar('\\');
		}

	}
	else
		putchar(chara);
}

}
