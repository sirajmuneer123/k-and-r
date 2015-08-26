/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x . Explain why. Use this observation to write a faster version of bitcount .
*/
#include<stdio.h>
int bitcount(unsigned x);
main()
{
	printf("%d\n",bitcount(10));
}
int bitcount(unsigned x)
{
	int count;
	for(count=0;x!=0;x &=x-1)
		++count;
	return count;
}
