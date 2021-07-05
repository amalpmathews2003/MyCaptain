#include <stdio.h>
#include <stdlib.h>
int string_len(char a[50])
{
	int len=0;
	while(a[len]!='\0')
		len++;
	return len;
}
int main()
{
	FILE *fp,*fp2;
	char data[50];
	fp=fopen("first.txt","r");
	fp2=fopen("second.txt","w");
	if(fp==NULL)
		printf("failed to open first.txt \n");
	else
	{
		while(fgets(data,50,fp))
		{
			int len=string_len(data);
			for(int i=len-1;i>=0;i--)
				printf("%c",data[i]);
			//printf("\n");
			printf("%s",data);
			fputs(data,fp2);
		}
	}
}
