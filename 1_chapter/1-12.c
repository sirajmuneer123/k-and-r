/*
Exercise 1-12. Write a program that prints its input one word per line.
*/
#include<stdio.h>
main()
{
int chara,d,f;
while((chara=getchar())!=EOF){
	if(chara==' '){
		putchar('\n');
		if((d=getchar())==' '){
			while((f=getchar())==' ')
				;
			putchar(f);
		}
		else
			putchar(d);
	}
	else if(chara=='\n'||chara=='\t'||chara=='\b'||chara=='.'||chara==','||chara=='\\'){
		putchar('\n');
	
	}
	else
		putchar(chara);

}

}
