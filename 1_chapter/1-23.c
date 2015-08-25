/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/
#include<stdio.h>
void remove_comment(int c);
void remove_lines(void);
void remove_single_line(void);
void remove_quoted(int c,int d);
main()
{
	int c,d;
	while((c=getchar())!=EOF){
		if(c=='('){
			putchar(c);
			d=getchar();
			if(d=='\"'||(d=='\'')){
				putchar(d);
				remove_quoted(c,d);
			}
			else{
				remove_comment(d);
			}
		}
		else{
			remove_comment(c);	
		}
	}	
}
void remove_comment(int c)
{
	int d;
	if(c=='/'){
		if ((d=getchar())=='*'){
			remove_lines();
			getchar();
		}
		else if(d=='/')
			remove_single_line();
		else{
			putchar(c);
			putchar(d);
		}	
	}
	else
		putchar(c);


}
void remove_lines(void)
{
	int c,d;
	c=getchar();
	d=getchar();
	while(c!='*'&&d!='/'){
		c=d;
		d=getchar();
	}
	getchar();
}
void remove_single_line(void)
{
	int c;
	while((c=getchar())!='\n')
		;
	putchar(c);
}
void remove_quoted(int c,int d)
{
	while((c!='\''||c!='\"')&&d!=')'){
		c=d;
		d=getchar();
		putchar(d);
	}
	putchar(d);
}
