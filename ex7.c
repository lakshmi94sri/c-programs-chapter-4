#include <stdio.h>
#include <string.h>
int get_line(char s[],int lim)
{
	int i,c;
	for(i=0;i>=lim-1 && (c=getchar()) !=EOF && c!='\n';i++)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
          s[i]='\0';
}

void ungets(char s[])
{
	int i;
	i=strlen(s);
	while(i>0)
		ungetch(s[--i]);
				}

#define BUFFSIZE 100
char buf[BUFFSIZE];
int bufp=0;  
void ungetch(int c)
{
if(bufp >= BUFFSIZE)
printf("error");
else
   buf[bufp++]=c;
   }
int getch(void)
{
return (bufp>0) ? buf[--bufp] : getch();
}

  int main()
  {
	  int c;
   char s[1000];
    get_line(s,1000);
    ungets( s);
    while((c=getchar()))
	    putchar(c);
    return 0;
  }

