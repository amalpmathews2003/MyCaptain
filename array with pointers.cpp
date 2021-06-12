#include <iostream>
using namespace std;
int main()
{
	int a[5];
	int *p=a;
	cout<<"enter array elements \n";
	for(int i=0;i<5;i++)
	{
		int t;
		cin>>t;
		*(p+i)=t;
	}
	cout<<"Displaying array \n";
	for(int i=0;i<5;i++)
		cout<<*(p+i)<<" "	;
}
