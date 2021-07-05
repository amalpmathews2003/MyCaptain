#include <stdio.h>
int main()
{
	int n=3;
	int a[n][n];
	printf("Enter the elements of matrix\n");
	for(int i=0;i<n*n;i++)
	{
		scanf("%d",&a[0][0]+i);
	}
	printf("Printng Matrix\n");

	int sum=0;

	for(int i=0;i<n*n;i++)
	{
		if(i%n==0)
			printf("\n");
		printf("%d ",*(&a[0][0]+i));
	}
	for(int i=0;i<n;i++)
	{
		sum+=a[i][i];
	}


	printf("\n\nSum of main diagonal elements is %d ",sum);

	return 0;
}
