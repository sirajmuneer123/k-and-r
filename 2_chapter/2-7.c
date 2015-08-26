/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/
#include<stdio.h>
unsigned invert(unsigned x,int p,int n);
main()
{
	printf("%d\n",invert(10,1,2));
}
unsigned invert(unsigned x,int p,int n)
{
	return x^(~(~0<<n) <<(p+1-n));
}
