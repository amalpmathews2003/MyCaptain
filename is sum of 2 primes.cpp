#include <iostream>
using namespace std;
bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	int n=34;
	//cin>>n;
	for(int i=2;i<=n/2;i++)
	{
		if(isprime(i))
		{
			if(isprime(n-i))
			{
				printf("%d=%d+%d\n",n,i,n-i);
			}
		}
	}
}