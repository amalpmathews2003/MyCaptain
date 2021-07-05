#include <stdio.h>
int lcm(int a,int b);
int main()
{
	printf("Enter first Number\n");
	int a;
	scanf("%d",&a);
	printf("Enter second Number\n");
	int b;
	scanf("%d",&b);
	printf("LCM(%d,%d)=%d",a,b,lcm(a,b));
	return 0;
}
int lcm(int a,int b)
{
	static int t=1;
	if(t%a==0 && t%b==0)
		return t;
	else
	{
		t++;
		lcm(a,b);
		return t;
	}
}
