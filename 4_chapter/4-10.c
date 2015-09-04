/*
Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.
*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAXOP 100
#define NUMBER '0'
#define ALIMIT 1000
/* maxsize of operand or operator */
/* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
int getline1(char line[],int limit);
char line[ALIMIT];
int li=0;
/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];
	if(getline1(line,ALIMIT)==1)
		while ((type = getop(s)) != '\0') {
			switch (type) {
				case NUMBER:
					push(atof(s));
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
				case '\n':
					printf("\t%.8g\n", pop());
					break;
				default:
					printf("error: unknown command %s\n", s);
					break;
			}
		}
		else
			printf("error:line full,can't get line!!\n");
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
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = line[li++]))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = li++))
			;
	s[i] = '\0';
	--li;
	return NUMBER;
}
/*forth part......*/
int getline1(char line[],int limit)
{
	int i=0,c;
	while(0< --limit && (line[i++]=getchar())!='\n')
		;
	line[i]='\0';
	if(limit==0)
		return 0;
	else
		return 1;
}
