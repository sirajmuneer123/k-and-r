/*
Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.
*/
#include <ctype.h>
#include<stdio.h>
double atof(char s[]);
main()
{
	char s[100]="123.45e+6";
	printf("%f\n",atof(s));
}
/* atof: convert string s to double */
double atof(char s[])
{
	double val, power,result,expo=1.0;;
	int i, sign,esign,n,j;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	result= sign * val / power;
	if(s[i]=='e' || s[i]=='E'){
		i++;
		esign = (s[i] =='-') ? -1 : 1;
		i++;
		for(n=0;isdigit(s[i]);i++)
			n=n*10+s[i]-'0';
		printf("%d\n",n);
		for(j=1;j<=n;j++)
			expo=expo*10.0;
		if(esign==1)
			return result * expo;
		else
			return result / expo;
	}
	else
		return result;
		
}

