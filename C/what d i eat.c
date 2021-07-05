  
#include <stdio.h>
void start()
{
	freopen("/home/amal/Desktop/programming/c++/practise/input_cpp.txt","r",stdin);
	freopen("/home/amal/Desktop/programming/c++/practise/error_cpp.txt", "w", stderr);
	freopen("/home/amal/Desktop/programming/c++/practise/output_cpp.txt", "w", stdout); 
}
int main()
{
	start();
	printf("List\n");
	printf("1.Pasta, Rs 400\n");
	printf("2.Pizza, Rs 450\n");
	printf("3.Burger, Rs 500\n");
	printf("4.Sandwich, Rs 350\n");
	printf("5.French Fries, Rs 300\n");

	printf("\nEnter the corresponding code\n");
	int food;
	scanf("%d",&food);
	switch(food)
	{
		case 1:
			printf("Food item-Pasta\n");
			printf("Price-400");
			break;
		case 2:
			printf("Food item-Pizza\n");
			printf("Price-450");
			break;
		case 3:
			printf("Food item-Burger\n");
			printf("Price-500");
			break;
		case 4:
			printf("Food item-Sandwich\n");
			printf("Price-350");
			break;
		case 5:
			printf("Food item-French Fries\n");
			printf("Price-300");
			break;
		default:
			printf("Invalid Entry");

	}

}
