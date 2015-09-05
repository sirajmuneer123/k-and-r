/*
Exercise 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
*/
#include<stdio.h>
#include<stdio.h>
main(int argc,char *argv[])
{
        int c,pos=1;
        int ns=0;  
	while((c=getchar())!=EOF){
                if(c=='\t'){
                        ns=int(argv[1])-(pos-1)%TAB;
                        while(ns>0){
                                putchar(' ');
                                ++pos;
                                --ns;
                        }
                }
                else if (c=='\n'){
                        putchar(c);
                        pos=1;
                }
                else{
                        putchar(c);
                        ++pos;
                }
        }
}

