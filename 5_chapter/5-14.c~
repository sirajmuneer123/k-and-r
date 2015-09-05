/*
Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n .
*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAXLINES 5000
#define MAXLEN 1000
#define INC 1
#define DEC 2

char *lineptr[MAXLINES];
int wnumcmp(void *s1, void *s2);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlinesi,int option);
void qsort1(void *lineptr[], int left, int right,int (*comp)(void *, void *));
int numcmp(const char *,const char *);
char *alloc1(int n);
main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
	int option,c;
	while(--argc>0 && (*++argv)[0] == '-'){
		c=(*argv)[1];
		switch(c){
			case 'n':
				option=INC;
				numeric=1;
				break;
			case 'r':
				option=DEC;
				break;
			default	:
				printf("ERROR!!! invalid sorting option....\n");
				break;
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort1((void**) lineptr, 0, nlines-1,(int (*)(void*,void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines,option);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}


/* qsort: sort v[left]...v[right] into increasing order */
void qsort1(void *v[], int left, int right,int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right)/* do nothing if array contains */
		return;/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort1(v, left, last-1, comp);
	qsort1(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1,const char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[],int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
int getline1(char s[],int lim);
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getline1(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc1(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}


/* getline: read a line into s, return length*/
int getline1(char s[],int lim)
{
        int c, i;

        for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines,int op)
{
	int i;
	if(op==INC)
		for (i = 0; i < nlines; i++)
			printf("%s\n", lineptr[i]);
	else
		for(i=nlines-1;i>=0;i--)
			printf("%s\n",lineptr[i]);
}


#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */
char *alloc1(int n)
/* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else/* not enough room */
	return 0;
}

