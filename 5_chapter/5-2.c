/*
Exercise 5-2. Write getfloat , the floating-point analog of getint . What type does getfloat
return as its function value?
*/
#include<stdio.h>
#define SIZE 1000
main()
{
	float array[SIZE], getfloat(float *);
	int n,i;
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		printf("a is =%f\n",array[n]);
}
#include <ctype.h>
int getch(void);
void ungetch(int);
/* getint: get next integer from input into *pn */
float getfloat(float *pn)
{
	int c, sign;
	float div;
	while (isspace(c = getch()))
		;			/* skip white space */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if(c=='.')
		c=getchar();
	for(div=1.0;isdigit(c);c=getchar()){
		*pn =10.0 * *pn +(c-'0') ;
		div *= 10.0;

	}
	*pn *= sign/div;
	if (c != EOF)
		ungetch(c);
	return c;
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
void ungetch(int c)
/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
