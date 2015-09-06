/*
Exercise 6-3. Write a cross-referencer that prints a list of all words in a document, and for
each word, a list of the line numbers on which it occurs. Remove noise words like ``the,''
``and,'' and so on.
*/
#include<stdio.h>
#include<stdlib.h>
struct tnode {
	char *word;
	int count;
	int list[50];
	struct tnode *left;
	struct tnode *right;
};
#include<ctype.h>
#include<string.h>
#define MAXWORD 100

struct tnode *addtree(struct tnode *,char *,int len);
void treeprint(struct tnode *);
int getword(char *,int);
struct tnode *talloc(void);
char *strdup1(char *);
int firstcmp(char *x,char *y,int pos);
int bs(char *);
main()
{
	int len=1;
	struct tnode *root;
	char word[MAXWORD];
	root=NULL;
	while((getword(word,MAXWORD)!=EOF))
		if(isalpha(word[0])){
			if(bs(word)==1)
				root=addtree(root,word,len);
		}
		else if(word[0]=='\n')
			++len;
	treeprint(root);
	return 0;

}
int bs(char *word)
{
	int i;
	struct noise{
		char *key;
	}keytab[11]={"and","are","a","an","in","is","of","or","the","to","this"};

	for(i=0;i<11;i++)
		if((strcmp(keytab[i].key,word))==0)
			return 0;
	return 1;	
}
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w,int len)
{
	int cond,cmp;
	if (p == NULL) {/* a new word has arrived */
		p = talloc();/* make a new node */
		p->word = strdup1(w);
		p->count=1;
		p->list[p->count]=len;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) ==0){
		p->count++;
		p->list[p->count]=len;
	}
	else if(cond<0)
		p->left = addtree(p->left, w,len);
	else
		p->right = addtree(p->right, w,len);
	return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	int i;
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\t\t", p->word);
		for(i=1;i<=p->count;i++)
			printf("%d ",p->list[i]);
			printf("\n");
		treeprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
 	return (struct tnode *) malloc(sizeof(struct tnode));
}
char *strdup1(char *s)
{
	char *p;
	p=(char *)malloc(strlen(s)+1);
	if(p!=NULL)
		strcpy(p,s);
	return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c,d, getch(void);
	void ungetch(int);
	char *w = word;
	while (isspace(c = getch())&& c!='\n')
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


