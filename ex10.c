#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int gettop(char []);
void push(double);
double pop(void);
int main()
{
	int type;
	double op2;
	char s[100];
	while((type=gettop(s)) != EOF)
	{
switch(type)
{
	case '0':
	     push(atof(s));
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
		      push(pop()/op2);
	      else
		      printf("zero divisior");
	      break;
        case '\n':
	      printf("\t%.8g\n",pop());
	      break;
	   default:
	       printf("error wrong commands %s\n",s);
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
		printf("stack is full%g",f);
}
double pop(void)
{
	if(sw > 0)
		return val[--sw];
	else
		printf("stack is empty");
	return 0.0;
}
int get_line(char line[],int num);
int num=0;
char line[100];

int gettop(char s[])
{
	int c,i;
	if(line[num]=='\0')
			if(get_line(line,100)==0)
			    return EOF;
       else
            num=0;
	    while((s[0]=c=line[num++])==' ' || c=='\t')
	    ;
	    s[1]='\0';
	    if(!isdigit(c) && c!='.')
	      return c;
	      i=0;
	      if(isdigit(c))
	      while(isdigit(s[++i]=c=line[num++]))
	      ;
	      if(c=='.')
	      while(isdigit(s[++i]=c=line[num++]))
	      ;
	      s[i]='\0';
	      num--;
	      return '0';
}

	int get_line(char s[],int lim)
{
	int i,c;
	for(i=0;i<lim-1&&(c=getchar()) != EOF && c!='\n';i++)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}



      
