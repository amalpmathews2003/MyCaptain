#include <stdio.h>
int main()
{
	int a,b;// declaring two numbers a and b
	printf("Enter two numbers\n");
	scanf("%d %d",&a,&b);// input numbers from user
	// let the numbers be a=5 b=10 
	a=a+b;//a=5+10 =15
	b=a-b;//b=15-10=5
	a=a-b;//a=15-5=10
	printf("%d %d \n",a,b);//displaying a and b

}
