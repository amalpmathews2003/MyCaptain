#include <stdio.h>
int main()
{
	printf("Enter your marks\n");
	int mark;
	scanf("%d",&mark);
	if(mark>=85 && mark<=100)
		printf("Grade A");
	else if(mark>=70 && mark<=84)
		printf("Grade B");
	else if(mark>=55 && mark<=69)
		printf("Grade C");
	else if(mark>=40 && mark<=54)
		printf("Grade D");
	else if(mark>=0 && mark<40)
		printf("Grade F");
	else
		printf("Enter a valid mark");

	return 0;
}
