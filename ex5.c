#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int gettop(char[]);
void push(double);
double pop(void);
void mathfnc(char[]);
int main()
{
	int type;
	double op1,op2;
	char s[100];
	void clearsp(void);
while((type=gettop(s)) != EOF)
{
	switch(type)
	{
		case '0':
			push(atof(s));
			break;
		case 'n':
			mathfnc(s);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
                        push(pop() * pop());
                        break;
		case '-':
			op2=pop();
                        push(pop() - op2);
                        break;
		case '/':
			op2=pop();
                        if(op2!=0.0)
			push(pop() / op2);
			else
				printf("error zero divisior");
			break;
		case '%':
                        op2=pop();
                        if(op2!=0.0)
                        push(pop()-op2 *(int) (pop() / op2));
                        else
                                printf("error zero divisior");
                        break;
		case '\n':
			printf("\t%.8g\n",pop());
			break;
		case '?':
			op2=pop();
			printf("\t%.8g\n",op2);
			push(op2);
                        break;
		case 'c':
			clearsp();
			break;
		case 'd':
			op2=pop();
			push(op2);
			push(op2);
			break;
		case 's':
			op1=pop();
                        op2=pop();
                        push(op1);
                        push(op2);
                        break;
		default:
			printf("wrong command %s",s);
			break;
	}
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
		printf("stack is full %g\n",f);
}
double pop(void)
{
	if(sw > 0)
		return val[--sw];
	else
		printf("stack is empty");
	return 0.0;
}

void clearsp(void)
{
	int sp=0;
}
int getch(void);
void ungetch(int);
int gettop(char s[])
{
	int i,c;
	while((s[0]=c=getch())==' ' || c=='\t')
		;
	s[1]='\0';

	if(!isdigit(c) && c!='.' && c!='-')
		return c;
	i=0;
	if(islower(c))
	{
		while(islower(s[++i]=c=getch()));
				;
			s[i]='\0';

	if(c!=EOF)
	ungetch(c);

	   if(strrlen(s)>1)
	   return 'n';
	   else
	     return s[0];
	}


	if(c=='-')
		if(isdigit(c=getch()) || c=='.')
			s[++i]=c;
		else
		{
			if(c!=EOF)
		ungetch(c);
			return '-';
		}
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
	return (bufp > 0) ? buf[bufp--] : getchar();
}
void ungetch(int c)
{
	if(bufp >= BUFFSIZE)
		printf("error");
	else
		buf[bufp++]=c;
}

void mathfnc(char s[])
{
	double op2;
	if(strcmp(s,"sin")==0)
		push(sin(pop()));
	else if(strcmp(s,"cos")==0)
		push(cos(pop()));
	 else if(strcmp(s,"exp")==0)
                push(exp(pop()));
	  else if(strcmp(s,"pow")==0)
	  {
		  op2=pop();
                push(pow(pop(),op2));
	  }
	else
		printf("%s not supported\n",s);
}








