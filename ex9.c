#include <stdio.h>
#define BUFFSIZE 100
char buf[BUFFSIZE];
int bufp=0;
int getch(void)
{
	return (bufp>0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if(bufp >= BUFFSIZE)
		printf("error");
	else
		buf[bufp++]=c;
}
int main()
{
	int c;
	c = '&hjjjxj';
	ungetch(c);
	while((c=getch()) != EOF)
		putchar(c);
	return 0;
}

