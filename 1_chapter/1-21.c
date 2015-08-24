/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab . When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?
*/
#include<stdio.h>
#define TAB 8
main()
{
	int pos,nt=0,nb=0,c;
	for(pos=1;(c=getchar())!=EOF;++pos)
		if(c==' '){
			if (pos%TAB!=0)
				++nb;
			else{
				++nt;
			//	printf("mmmmmmmmmmm=%d",nt);
				nb=0;	
			}
		}
		else{
			for( ;nt>0;--nt){
				putchar('\t');
				printf("ummma");
			}
			if(c=='\t')
				nb=0;
			else
				for( ;nb>0;--nb)
					putchar(' ');
			putchar(c);
//			putchar('\t');
			if(c=='\n')
				pos=0;
			else if(c=='\t')
				pos=pos+(TAB-(pos-1)%TAB)-1;
		}
				
			
}
