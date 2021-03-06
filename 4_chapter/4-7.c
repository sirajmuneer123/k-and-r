/*
Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp , or should it just use ungetch ?
*/
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
int getop(char []);
void push(double);
double pop(void);

#include <ctype.h>
int getch(void);
void ungetch(int);
void ungets(char s[]);
/* reverse Polish calculator */
main()
{
	int type,i,lp=0;
	double op2,v;
	char s[MAXOP];
	double variable[26];
	for(i=0;i<26;i++)
		variable[i]=0.0;
	while ((type = getop(s)) != EOF) {
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
			case '=':
				pop();
				if(lp>='A'&&lp<='Z'){
					variable[lp-'A']=pop();
				}
				else
					printf("error :variable\n");
				break;
			case '\n':
				v=pop();
				printf("\t%.8g\n",v);
				break;
			default:
				if(type>='A'&&type<='Z'){
					push(variable[type-'A']);
				}
				else if(type==v)
					push(v);
				else
					printf("error: unknown command %s\n", s);
				break;
		}
		lp=type;
	}
	return 0;
}



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
	if (sp >0){
		return val[--sp];
	
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}


/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c,d,j=0;
	char remain[100];
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
/* not a number */
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	while(c != EOF){
		remain[i++]=c;
		c=getchar();
	}
	remain[i]='\0';
	ungets(remain);
	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)   /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}
#include<string.h>
void ungets(char s[])
{
	int len=strlen(s),i=0;
	printf("len=%d\ts=%s\n",len,s);
	while(i<len)
		ungetch(s[i++]);
}
