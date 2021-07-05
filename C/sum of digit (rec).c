#include <stdio.h>
int digi_sum(int n,int sum);
int main()
{
	int n;
	printf("Enter a Number\n");
	scanf("%d",&n);
	printf("Sum of digits of %d =%d",n,digi_sum(n,0));

	return 0;
}
int digi_sum(int n,int sum)
{
	if(n==0)
		return sum;
	digi_sum(n/10,sum+n%10);
}
