#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int gettop(char[]);
void push(double);
double pop(void);
int main()
{
	int type;
	int var=0;
	char s[100];
	double op2,v;
	double variable[26];
	while((type=gettop(s)) != EOF)
	{
		switch(type)
		{
                  case '0':
			  push(atof(s));
			  break;
                  case '+':
			  push(pop()+pop());
			  break;
		case '-':
			  op2=pop();
			  push(pop()-op2);
			  break;
                 case '*':
                          push(pop()*pop());
                          break;
	        case '/':
			  op2=pop();
			  if(op2!=0.0)
			      push(pop()/op2);
			  else
                             printf("errorzero divisior");
			  break;
	        case '=':
			 pop();
			if(var >= 'A' && var <= 'Z')
			       variable[var-'A']=pop();
		break;	
	         case '\n':
		     v=pop();
			  printf("\t%.8g\n",v);
			  break;
		default:
			  if(type>='A' && type<='Z')
				  push(variable[type-'A']);
			  else if(type=='v')
				  push(v);
			  else
			  printf("wrong commands");
			  break;
		}
		var=type;
	}
	return 0;
}

#define MAX 100
double val[MAX];
int sw=0;
void push(double f)
{
	if(sw < MAX)

		val[sw++]=f;
	else
		printf("stack is full %g",f);
}
double pop(void)
{
	if(sw>0)
		return val[--sw];
	else
		printf("stack is empty");
	return 0.0;
}
int getch(void);
void ungetch(int);
int gettop(char s[])
{
	int i,c;
	while((s[0]=c=getch())==' ' || c=='\t')
		;
	s[1]='\0';
	if(!isdigit(c) && c!='.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()))
			;
	if(c=='.')
		while(isdigit(s[++i]=c=getch()))
			;
	s[i]='\0';
	if(c!=EOF)
		ungetch(c);
	return '0';
}

#define BUFFSIZE 100
char buf[BUFFSIZE];
int bufp=0;
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if(bufp >= BUFFSIZE)
		printf("error");
	else
		buf[bufp++]=c;
}
