/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2 . Allow for letters of either case
and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . Arrange that a
leading or trailing - is taken literally.
*/
#include<stdio.h>
void expand(char s1[],char s2[]);
main()
{
	char s1[100]="siA-Xraja-zmun2-9eer";
	char s2[100];
	expand(s1,s2);
}
void expand(char s1[],char s2[])
{
	char c,d;
	int i=0,j=0;
	while((c=s1[i])!='\0'){
		if(c=='-'&&s1[i+1]>=(d=s1[i-1])){
			printf("%c\n",d);
			while(s1[i+1]!=d){
				s2[j++]=++d;
				
			}
		++i;
		++i;
		}
		else{
			s2[j++]=c;
			++i;
		}

	}
	s2[j]='\0';
	printf("\n%s\n",s2);
}
