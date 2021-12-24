#include <stdio.h>
#include <string.h>
int get_line(char s[],int lim);
void reverse(char s[]);

int main()
{
   char s[100];
    get_line(s,100);
   reverse(s);
    printf("%s",s);
    return 0;
}
int get_line(char s[],int lim)
{
	int c,i;
	for(i=0;i<lim-1&&(c=getchar()) != EOF && c!='\n';i++)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
}
void reverse(char s[])
{
	void reverserecrussion(char s[],int i,int len);
	reverserecrussion(s,0,strlen(s));
}
void reverserecrussion(char s[],int i,int len)
{
	int c,k;
	k=len -(i+1);
	if(i < k)
	{
		c=s[i];
		s[i]=s[k];
		s[k]=c;
	
	reverserecrussion(s,++i,len);
}
}

