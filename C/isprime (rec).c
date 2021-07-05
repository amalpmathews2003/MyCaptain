#include <stdio.h>
int isprime(int n,int i);

int main()
{
	int n;
	printf("Enter a Number\n");
	scanf("%d",&n);

	if(isprime(n,2))
		printf("%d is a prime number\n",n);
	else
		printf("%d is not a prime number",n);
	
	return 0;
}
int isprime(int n,int i)
{
	if(i>n/2)
		return 1;
	if(n==1)
		return 1;
	if(n%i==0)
		return 0;
	return isprime(n,i+1);

}
