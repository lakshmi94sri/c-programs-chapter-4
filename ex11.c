#include <stdio.h>
#include <ctype.h>
int getch(void);
int gettop(char s[])
{
	int i,c;
	static int var=0;
	if(var==0)
	{
		c=getch();
	}
	else
	{
		c=var;
		var=0;
	}
	while((s[0]=c=getch()) == ' ' || c=='\t')
		;
	s[1]=' ';
	i=0;
	if(!isdigit(c) && c!='.')
		return c;
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()))
			;
	if(c=='.')
		while(isdigit(s[++i]=c=getch()))
				;
				s[i]=' ';
				if(c!=EOF)
				var=c;
				return '0';
				}
