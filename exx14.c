#include <stdio.h>
#define swap(t,x,y) {t=x;x=y;y=t;}
int main()
{
	int x=10;
	int y=30;
	int t;
	int swap;
	swap(t,x,y);
	printf("%d=x,%d=y",x,y);
	return 0;
}
