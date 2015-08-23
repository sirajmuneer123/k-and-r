/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/
#include<stdio.h>
main()
{
int chara,lw=0,index=0,nw=0,i,j;
int list[20];



while((chara=getchar())!=EOF){
	if ((chara==' ')||(chara=='.')||(chara=='\n')){
		++nw;
		list[index]=lw;
		index=index+1;
		lw=0;
	}
	else{
		++lw;
		
	}	
}
for(i=0;i<nw;i++){
	for(j=0;j<list[i];j++){
		printf("--");
	}
	printf("\n");
}
}
