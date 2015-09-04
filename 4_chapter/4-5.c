/*
Exercise 4-5. Add access to library functions like sin , exp , and pow . See <math.h> in
Appendix B, Section 4.
*/
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include<math.h>
#include<string.h>
#define MAXOP 100
#define NUMBER '0'
#define MATH '1'
/* maxsize of operand or operator */
/* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
void clear(void);
void library(char s[]);
/* reverse Polish calculator */
main()
{
	int type;
	double op2,temp;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case MATH:
				library(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2=pop();
				if(op2!=0.0)
					push(fmod(pop(), op2));
				else
					printf("error :zero diviser\n");
				break;
			case '?':
				op2=pop();
				printf("the top value of the stack is: %g\n ",op2);
				push(op2);
				break;
			case 'd':
				op2=pop();
				push(op2);
				push(op2);
				break;
			case 's':
				op2=pop();
				temp=pop();
				push(op2);
				push(temp);
				break;
			case 'c':
				clear();
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

/*second part....*/
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
/* maximum depth of val stack */
/* next free stack position */
/* value stack */
/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL){
		val[sp++] = f;
	}
	else
		printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
	return 0.0;
}
}
/*third part.........*/
#include <ctype.h>
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i=0;
	if(islower(c)){
		while(islower(c=getchar()))
			s[++i]=c;
		if(strlen(s)>1)
			return 	MATH;
		else
			return c;	
	}
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
/*forth part......*/
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
void clear(void)
{
	sp=0;
}
void library(char s[])
{
	double op1,op2;
	op1=pop();
	if(strcmp("sin",s)==0)
		push(sin(op1));
	else if(strcmp("pow",s)==0){
		op2=pop();
		push(pow(op2,op1));
	}
	else if(strcmp("exp",s))
		push(exp(op1));
	else
		printf("error : not a math library function \n");
}
