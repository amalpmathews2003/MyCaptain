#include <stdio.h>
int main()
{	
	int n=6;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2*i;j++)
		{
			if(j&1)
				printf("%d",0);
			else
				printf("%d",1);
		}
		//printf("\n");//goto new line
		printf(" ");
	}

	return 0;
}
