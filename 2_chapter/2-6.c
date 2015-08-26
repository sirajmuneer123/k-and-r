/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y , leaving the other bits unchanged.

*/
#include<stdio.h>
unsigned int setbits(unsigned int x,int p,int n,unsigned int y);
main()
{
	printf("%d\n",setbits(8,2,3,6));
}
unsigned int setbits(unsigned int x,int p,int n,unsigned int y)
{
	
	return x & ~(~(~0<< n)<<(p+1-n)) | (y & ~(~0 << n)) <<(p+1-n);

}
