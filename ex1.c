#include <stdio.h>
#include <string.h>
int strrindex(char s[],char t[])
{
	int i,j;
	for(i=strlen(s)-1,j;i>=0;i--)
	{
		for(j=0;s[i+j]==t[j]&&t[j];j++);
		if(!t[j])
			return i;
	}
	return -1;
}
int main()
{
	printf("%d\n",strrindex("i kinglong sriram","long"));
	return 0;
}
			
