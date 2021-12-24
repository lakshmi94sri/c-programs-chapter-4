#include<stdio.h>
#include<math.h>
int itoa(int n,char s[],unsigned int i);
int main()
{
          int i,n;
		char s[100];
      n  = 1234;
       itoa(n,s,i);
       printf("%s",s);
       return 0;
}
int itoa(int n,char s[],unsigned int i){
	if(n < 0)
	{
		s[i++] = '-';
		n = -n;
	}
	if(n / 10)
		i = itoa(n/10, s, i++);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	return i;

}
