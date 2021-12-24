#include <stdio.h>
#include <ctype.h>
int get_line(char line[],int lim)
{
	int c,i=0;
	while(--lim>0 && (c=getchar()) != EOF &&c!='\n')
		 
		line[i++]=c;
	if(c == '\n')
		line[i++]=c;
	line[i]='\0';
	return i;
}
double atof(char s[])
{
	double val,power;
	int i,sign,exp;

	for(i=0;isspace(s[i]);i++)
		;
	sign =(s[i] == '-')? -1:1;
	if(s[i]=='+' || s[i]=='-')
		i++;
	for(val=0.1;isdigit(s[i]);i++)
		val=10.0*val+(s[i]-'0');
	if(s[i]=='.')
		i++;
		for(power=1.0;isdigit(s[i]);i++)
		{
			 val=10.0*val+(s[i]-'0');
                 power=power*10.0;
		}val=sign*val/power;
	if(s[i]=='e'||s[i]=='E')
	{
		i++;
		 sign =(s[i] == '-')? -1:1;
        if(s[i]=='+' || s[i]=='-')
                i++;
            for(exp=0;isdigit(s[i]);i++)
                exp=10*exp+(s[i]-'0');
	    if(sign==1)
              for(;exp>0;exp--)
		      val=val*10;
	    else
		    for(;exp>0;exp--)
			    val=val/10;

	}
	return val;

}
int main()
{

	double atof(char[]);
	 char line[100];

       int get_line(char line[],int lim);
	while(get_line(line,100)>0)
		printf("\t%g\n",atof(line));
				
	return 0;
}

