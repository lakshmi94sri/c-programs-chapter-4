#include <stdio.h>
char buf=0;
int getch(void)
{
	int c;
	if(buf != 0)
		c=buf;
	else
		c=getchar();
	buf =0;
	return c;
}
void ungetch(int c)
{

	if(buf !=0)
		printf("error");
	else
		buf=c;
}
int main()
{
	int c;
	c='h';
	ungetch(c);
	while((c=getch())!=EOF)
		putchar(c);
	return 0;
}
