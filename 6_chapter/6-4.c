/*
Exercise 6-4. Write a program that prints the distinct words in its input sorted into decreasing
order of frequency of occurrence. Precede each word by its count.
*/

struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 200
#define ALIMIT 1000
struct tnode *talloc(void);
char *strdup1(char *);
struct tnode *addtree(struct tnode *,char *);
void treeprint(void);
int getword(char *,int);
void store(struct tnode *);
struct tnode *list[ALIMIT];
void sort(void);
int in=0;
main()
{
	struct tnode *root;
	char word[MAXWORD];
	while((getword(word,MAXWORD))!=EOF)
		if(isalpha(word[0]))
			root=addtree(root,word);
	store(root);
	sort();
	treeprint();
	return 0;
			
}
void sort(void)
{
	int i,j;
	struct tnode *temp;
	for(i=0;i<in;i++)
		for(j=i+1;j<in;j++)
			if(list[i]->count < list[j]->count){
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}

}
void store(struct tnode *p)
{
	if(p!=0){
		store(p->left);
		if(in<ALIMIT)
			list[in++]=p;
		store(p->right);
	}
		
}
void treeprint(void)
{
	int i;
	for(i=0;i<in;i++)
		printf("%d \t %s\n",list[i]->count,list[i]->word);
}
struct tnode *addtree(struct tnode *p,char *w)
{
	int cm;
	if(p==NULL){
		p=talloc();
		p->word=strdup1(w);
		p->count=1;
		p->left=p->right=NULL;	
	}else if((cm=strcmp(w,p->word))==0)
		p->count++;
	else if(cm<0)
		p->left=addtree(p->left,w);
	else
		p->right=addtree(p->right,w);
	return p;
}
char *strdup1(char *s)
{
	char *p;
	p=(char *)malloc(sizeof(strlen(s)+1));
	if(p!=NULL)
		strcpy(p,s);
	return p;
	
}
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c,d, getch(void);
	void ungetch(int);
	char *w = word;
	while (isspace(c = getch()))
			;
	if(c!=EOF){
		*w++=c;
	}
	if(c=='\n'){
		*w='\0';
		return c;			
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
	if (!isalnum(*w = getch())) {
		ungetch(*w);
		break;
	}
	*w = '\0';
	return word[0];
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
