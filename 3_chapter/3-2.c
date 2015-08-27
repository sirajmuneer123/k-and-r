/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s . Use a switch . Write a
function for the other direction as well, converting escape sequences into the real characters.
*/
#include<stdio.h>
void escape(char s[],char t[]);
main()
{
	char t[100]="siraj 	muneer";
	char s[100];
	escape(s,t);
	
}
void escape(char s[],char t[])
{
	int c,i,j=0;
	for(i=0;t[i]!='\0';i++){
		switch(t[i]){
			case '\t':
				s[j++]='\\';
				s[j++]='t';
				break;
			case '\n':
				s[j++]='\\';
				s[j++]='n';
				break;
			default:
				s[j++]=t[i];
				break;
			
		}
	}
	s[j]='\0';
	printf("%s\n",s);

}
