#include<stdio.h>
#include<stdlib.h>
#define YES 1
#define NO 0
struct tnode {
	char *word;
	struct tnode *left;
	struct tnode *right;
};
#include<ctype.h>
#include<string.h>
#define MAXWORD 100

struct tnode *addtree(struct tnode *,char *,int pos);
void treeprint(struct tnode *);
int getword(char *,int);
struct tnode *talloc(void);
char *strdup1(char *);
int firstcmp(char *x,char *y,int pos);

/* word frequency count*/
main(int argc,char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int pos;
	if(--argc)
		pos=atoi(argv[1]);
	else
		pos=6;
	root=NULL;
	while((getword(word,MAXWORD)!=EOF))
		if(isalpha(word[0]) && (strlen(word))>=pos)
			root=addtree(root,word,pos);
	treeprint(root);
	return 0;

}
/*checking the strings suitable for compair   */
int firstcmp(char *x,char *y,int pos)
{

        int i;
        for(i=pos;pos>0;pos--){
                if(*x++!=*y++)
                        return 0;
        }
        return 1;
}


/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w,int pos)
{
	int cond,cmp;
	if (p == NULL) {/* a new word has arrived */
		p = talloc();/* make a new node */
		p->word = strdup1(w);
		p->left = p->right = NULL;
	} else if ((cmp = firstcmp(w,p->word,pos))==1 &&(cond = strcmp(w, p->word)) < 0)
		p->left = addtree(p->left, w,pos);
	else if(cmp==1 && cond>0)/* grea5ter than into right subtree */
		p->right = addtree(p->right, w,pos);
	return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	static int i=0;
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\n", p->word);
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
	while (isspace(c = getch()))
			;
	if(c=='/'){
		if((c=getch())=='*'){
			c=getch();
			while(c!='*'&&(d=getch())!='/')
				c=d;
			getch();
			while(isspace(c=getch()))
				;
		}else if(c=='/'){
			while((c=getch())!='\n')
				;
			c=getch();
		}
	}
	if(c=='"'){
		while((c=getch())!='"')
			;
		c=getch();
	}	
	if(c!=EOF){
		*w++=c;
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

