/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full generality.)
*/
#include<stdio.h>
void remove_comment(int c);	//funtion to remove comments
void remove_lines(void);	//funtion to remove all line
void remove_single_line(void);	//function to remove single line
void remove_quoted(int c,int d);
void search(char s[]);
char list[10000];
int i;
main()
{
	int c,d,j;
	i=0;
	while((c=getchar())!=EOF){
		if(c=='('){
			list[i]=c;
			++i;
			d=getchar();
			if(d=='\"'||(d=='\'')){
				list[i]=d;
				++i;
				remove_quoted(c,d);
			}
			else{
				remove_comment(d);
			}
		}
		else{
			remove_comment(c);	
		}
	}
	list[i]='\0';
	search(list);
		
}
void remove_comment(int c)
{
	int d;
	if(c=='/'){
		if ((d=getchar())=='*'){
			remove_lines();
			getchar();
		}
		else if(d=='/')
			remove_single_line();
		else{
			list[i]=c;
			++i;
			list[i]=d;
			++i;
		}	
	}
	else{
		list[i]=c;
		++i;

	}
}
void remove_lines(void)
{
	int c,d;
	c=getchar();
	d=getchar();
	while(c!='*'&&d!='/'){
		c=d;
		d=getchar();
	}
	getchar();
}
void remove_single_line(void)
{
	int c;
	while((c=getchar())!='\n')
		;
	list[i]=c;
	++i;
}
void remove_quoted(int c,int d)
{
	while((c!='\''||c!='\"')&&d!=')'){
		c=d;
		d=getchar();
		list[i]=d;
		++i;
	}
	list[i]=d;
	++i;
}
void search(char s[])
{
	int i,brackets,braces;
	brackets=0;
	braces=0;
	for(i=0;s[i]!='\0';++i){
		if (s[i]=='(')
			++brackets;
		else if(s[i]==')')
			--brackets;
		else if(s[i]=='{')
			++braces;
		else if(s[i]=='}')
			--braces;
	}
	if(brackets!=0)	
		printf("ERROR!!! %d brackets missing....\n",brackets);
	if(braces!=0)
		printf("ERRROR!!!! %d breaces missing...\n",braces);
	if((brackets==0)&&(braces==0))
		printf("NO eroor...........\n");
}
