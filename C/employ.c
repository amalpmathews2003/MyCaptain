
#include <stdio.h>
struct employ
{
	int empage;
	char empname[20] ;
	int id;
	float salary;
};
void get_emplyees(struct employ a[],int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%s %d %d %f",a[i].empname,&a[i].empage,&a[i].id,&a[i].salary);
	}
}
void put_emplyees(struct employ a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%s %d %d %f\n",a[i].empname,a[i].empage,a[i].id,a[i].salary);
	}
}
int main()
{
	int n=20;
	struct employ a[n];
	printf("Name Age Phone Salary");
	get_emplyees(a,n);
	put_emplyees(a,n);
}
