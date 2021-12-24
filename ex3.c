#include <stdio.h>
#include <stdlib.h>
#include "math.h"
int gettop(char[]);
void push(double);
double pop(void);
int main()
{
	int type;
	char s[100];
       double op2;
       while((type = gettop(s)) != EOF)
       {
	       switch(type)
	       {
		       case '0':
			       push(atof(s));
			       break;
		  case '+':
			       push(pop() + pop());
			       break;
	          case  '*':
                               push(pop() * pop());
                               break;
	          case  '-':
			       op2 = pop();
			            push(pop()-op2);
                               break;
	          case   '/':
			       op2 = pop();
			       if(op2 != 0.0)
                      push(pop() / op2);
			       else
				       printf("error zero divisor");
                               break;
	           case  '%':
                               op2 = pop();
                                
                               if(op2 != 0.0)
                                push(pop() - op2 * (int) (pop() / op2));
			       else
                                       printf("error zero divisor");

                               break;
	            case   '\n':
                           printf("\t%.8g\n",pop());
                               break;
	        default:
			       printf("error wrong command %s\n",s);
			       break;
	       }
       }
       return 0;
}

#define MAX 100
int sw=0;
double val[MAX];
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
	{
		printf("stack is empty");
		return 0.0;
	}
}
#include <ctype.h>
int getch(void);
void ungetch(int);
int gettop(char s[])
{
	int i,c;
	while((s[0] = c = getch()) == ' ' ||  c =='\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0;
	if(c == '-'  || isdigit(c))
		while(isdigit(s[++i] = c = getch()))
				;
    if(c == '.')
	 while(isdigit(s[++i] = c = getch()))
		 ;
		 s[i] = '\0';
	if(c != EOF)
	  ungetch(c);
	  return '0';
}
#define BUFFERSIZE 100
char buf[BUFFERSIZE];
int bufp = 0;
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if(bufp >= BUFFERSIZE)
		printf("error");
	else
		buf[bufp++] = c;
}
