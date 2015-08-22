/*
Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.
*/
#include<stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */
main()
{
float fahr, celsius;
float lower, upper, step;
lower = 0;
upper = 300;
step = 20;
celsius = lower;
printf("TEMPERATURE    FAHRENHEIT\n");
while (celsius <= upper) {
fahr = ((7*celsius)/5)+32.0;
printf("%3.0f\t\t %6.1f\n",celsius,fahr);
celsius=celsius+step;
}
}
