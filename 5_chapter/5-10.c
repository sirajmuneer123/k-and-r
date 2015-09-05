/*
Exercise 5-10. Write the program expr , which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).
*/
#include<stdio.h>
#include<math.h>
#define NUMBER '0'
void push(double);
double pop(void);
int getop(char *s);
main(int argc,char *argv[])
{
	int i=1;
	float op2;
	while(--argc>0){
		switch(getop(*++argv)){
			case NUMBER:
				push(atoi(*argv));
				break;
			case '+':
				push(pop()+pop());
				break;
			case '-':
				push(pop()-pop());
				break;
			case '*':
				push(pop()*pop());
				break;
			case '/':
				op2=pop();
				if(op2!=0)
					push(pop()/op2);
				else
					printf("ERROR!! divided by zerooo\n");
				break;
			default:
				printf("error!!!!!unknown character....%s\n",argv[i]);
				break;
		}
		++i;
				
	}
	printf("result=%g\n",pop());
		
}
#define MAXVAL 1000
double val[MAXVAL];
int sp=0;
void push(double f)
{
	if(sp>MAXVAL)
		printf("error: cant push to stack!!\n");	
	else
		val[sp++]=f;
}
double pop(void)
{
	if(sp<0)
		printf("error:stack empty\n");
	else
		return val[--sp];
}
int getop(char s[])
{
	int i=0, c;
	c=s[i];
	if (!isdigit(c) && c != '.')
		return c;
	if (isdigit(s[i]))
		return NUMBER;
}
