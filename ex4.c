#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int gettop(char[]);
void push(double);
double pop(void);
int main()
{
	int type;
      char s[100];
    double op1,op2;
   void clearsp(void);
  while((type=gettop(s)) != EOF)
  {
switch(type)
{
	case '0':
	   push(atof(s));
           break;
        case  '*':
           push(pop() * pop());
           break;
        case  '+':
           push(pop() + pop());
           break;
        case  '-':
	   op2=pop();
           push(pop() - op2);
           break;
	 case  '/':
	   op2=pop();
	   if(op2!=0.0)
           push(pop() / op2);
	   else
		   printf("error zero divisior");
           break;
	  case  '%':
           op2=pop();
           if(op2!=0.0)
           push(pop()-op2 * (int) (pop() / op2));
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
		printf("error wrong command %s\n",s);
}
}
return 0;
}


void clearsp(void)
{
	int sp=0;
}

#define MAX 100
double val[MAX];
int sw=0;
void push (double f)
{
	if(sw < MAX)
           val[sw++]=f;
	else
		printf("stack is full %g\t",f);
}
double pop(void)
{
	if(sw > 0)
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
	while((s[0]=c=getch()) == ' ' || c == '\t')
		;
	s[1]='\0';
	i=0;
	if(!isdigit(c) && c!='.' && c!='-')
	       return c;
  
   if(c=='-')
	 if(isdigit(c=getch()) || c=='.')
		       s[++i]=c;
		       else 
		       {
	      if( c != EOF)
               
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
if( c!=EOF)
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

