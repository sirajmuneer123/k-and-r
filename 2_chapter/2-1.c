/*
Exercise 2-1. Write a program to determine the ranges of char , short , int , and long
variables, both signed and unsigned , by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.

*/
#include<stdio.h>
#include<limits.h>
#include<float.h>
main()
{
	
	printf("the minimum value of INT= %d\n",INT_MIN);
	printf("the maximum value of INT= %d\n",INT_MAX);
	printf("the minimum value of SHORT INT= %d\n",SHRT_MIN);
	printf("the maximum value of SHORT INT= %d\n",SHRT_MAX);
	printf("the minimum value of CHAR= %d\n",CHAR_MIN);
	printf("the maximum vakue of CHAR= %d\n",CHAR_MAX);
	printf("the minimum value of signed CHAR= %d\n",SCHAR_MIN);
	printf("the maximum value of signed CHAR= %d\n",SCHAR_MAX);
	printf("the maximum value of unsigned CHAR= %d\n",UCHAR_MAX);
	printf("the minimum value of LONG= %1d\n",LONG_MIN);
	printf("the maximum value of LONG= %1d\n",LONG_MAX);
	
}
