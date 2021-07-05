#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//windows.h alias in linux
#include <string.h>
#include <time.h>
struct date
{
	int day,month,year;
};
struct account
{
	char name[60];
	int acc_no,age;
	char address[60];
	char citizenship[60];
	char ac_type[10];
	char phone[15]	;
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;
};

void login_window();
void menu();
void new_acc();
void edit();
void see();
void erase();
void transaction();
void view_list();
void transaction_to();
void show_account_details(struct account example);

int main()
{
	login_window();

	return 0;
}
void login_window()
{
	printf("\n\n\t\t........AMAL BANK.........\n\n");
	printf("\n\n\t\tWelcom To Login Page\n\n");
	char pass[10],password[]="amal";
	printf("Enter password to login : ");
	scanf("%s",pass);

	if(strcmp(pass,password)==0)
	{
		//printf("Password Matched");
		menu();
	}
	else
	{
		int choice;
		login_try_agian:
		printf("Enter 1 to try again and 0 to exit");
		scanf("%d",&choice);

		if(choice==1)
		{
			system("clear");
			main();
		}
		else if(choice==0)
		{
			system("clear");
			exit(0);
		}
		else
		{
			printf("Invalid entry");
			system("clear");
			goto login_try_agian;
		}
	}
}

void menu()
{
	int choice;
	system("clear");
	printf("\n\t\t    Bank Mangement System\n");
	printf("\t\t\t    Main Menu\n");
	printf("\t\t\t1.Create New Account\n");
	printf("\t\t\t2.Update Existing Account\n");
	printf("\t\t\t3.Withdraw/Deposit\n");
	printf("\t\t\t4.Show Account Details\n");
	printf("\t\t\t5.Remove account\n");
	printf("\t\t\t6.Customer list\n");
	printf("\t\t\t7.Intra Banking Transaction\n");
	printf("\t\t\t8.Exit\n");
	printf("\t\tEnter your choice  :  ");
	scanf("%d",&choice);

	system("clear");

	switch(choice)
	{
		case 1:
			new_acc();
			break;
		case 2:
			edit();
			break;
		case 3:
			transaction();
			break;
		case 4:
			see();
			break;
		case 5:
			erase();
			break;
		case 6:
			view_list();
			break;
		case 7:
			transaction_to();
			break;
		case 8:
			exit(0);
			break;
		default:
			menu();
	}
}	

void new_acc()
{
	struct account add;
	FILE *ptr;
	ptr=fopen("record.dat","a+");
	system("clear");
	add_acc:
	printf("\t\t\tAdd Record\n");
	printf("Enter todays date (mm/dd/yyyy): ");
	scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
	int acc_no=1000;
	while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n",
		&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,
		&add.age,add.address,add.citizenship,add.phone,add.ac_type,&add.amt,
		&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
		acc_no=add.acc_no;
	}

	add.acc_no=acc_no+1;
	printf("Account No : %d",add.acc_no);
	printf("\nEnter name : ");
	scanf("%s",add.name);
	printf("\nEnter dob (mm/dd/yy) : 	");
	scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
	printf("\nEnter age : ");
	scanf("%d",&add.age);
	printf("\nEnter address : ");
	scanf("%s",add.address);
	printf("\nEnter citizenship : ");
	scanf("%s",add.citizenship);
	printf("\nEnter phone number : ");
	scanf("%s",add.phone);
	printf("\nEnter deposit amt : ");
	scanf("%f",&add.amt);
	printf("\nType of account :");
	printf("\nSavings\nfixed1(for 1 year)\nfixed2(for 2 year)  ");
	scanf("%s",add.ac_type);

	int choice;
	printf("\n\nAre you sure to continue (1/0)");
	scanf("%d",&choice);
	if(choice==0)
		goto add_acc;
	else
	{
		fprintf(ptr,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d \n",
			add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
			add.citizenship,add.phone,add.ac_type,add.amt,
			add.deposit.month,add.deposit.day,add.deposit.year);
		fclose(ptr);
		printf("\nAccount created succesfully");
	}
	invalid:
	printf("\nEnter 1 to go to main menu and 0 to exit :  ");
	scanf("%d",&choice);
	if(choice==1)
	{
		menu();
	}
	else if(choice==0)
	{
		exit(0);
	}
	else
	{
		printf("Invalid entry");
		goto invalid;
	}

}	

void edit()
{
	struct account update;
	int choice,test=0,acc_no;
	FILE *old,*temp;
	old=fopen("record.dat","r");
	temp=fopen("temp.dat","w");
	printf("\n Enter the account no of the customer whose info you want to change : ");
	scanf("%d",&acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n",
		&update.acc_no,update.name,&update.dob.month,&update.dob.day,&update.dob.year,
		&update.age,update.address,update.citizenship,update.phone,update.ac_type,&update.amt,
		&update.deposit.month,&update.deposit.day,&update.deposit.year)!=EOF)
	{
		if(update.acc_no==acc_no)
		{
			test=1;
			printf("\nAccount Number : %d",update.acc_no);
			printf("\nName : %s",update.name);
			printf("\nDOB : %d/%d/%d",update.dob.month,update.dob.day,update.dob.year);
			printf("\nAge : %d",update.age);
			printf("\nAddress : %s",update.address);
			printf("\nCitizenship : %s",update.citizenship);
			printf("\nPhone : %s",update.phone);
			printf("\nAccount type : %s",update.ac_type);
			printf("\n Which information you want to change \n");
			printf("1.Address\n");
			printf("2.Phone\n");
			printf("%d",choice);
			if(choice==1)
			{
				printf("\nEnter new address : ");
				scanf("%s",update.address);
				printf("Changes saved");
			}
			else if(choice==2)
			{
				printf("\nEnter new phone no : ");
				scanf("%s",update.phone);
				printf("Changes saved");
			}
		}
		fprintf(temp,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d \n",
			update.acc_no,update.name,update.dob.month,update.dob.day,
			update.dob.year,update.age,update.address,
			update.citizenship,update.phone,update.ac_type,update.amt,
			update.deposit.month,update.deposit.day,update.deposit.year);
	}
	if(test==0)
		printf("Account not found!");
	fclose(old);
	fclose(temp);
	remove("record.dat");
	rename("temp.dat","record.dat");
	printf("\nEnter 1 to return to main menu and 0 to exit:");
	scanf("%d",&choice);
	system("clear");
	if(choice==1)
	{
		menu();
	}
	else if(choice==0)
		exit(0);
	return;
}

void see()
{
	struct account check;
	FILE *ptr;
	int test=0;
	int choice;
	ptr=fopen("record.dat","r");
	see_invalid:
	printf("Do you want to check by \n 1.Account Number \n 2.Name \nEnter your choice : ");
	scanf("%d",&choice);
	if(choice==1)
	{
		int ac_no;
		printf("Enter acc_no : ");
		scanf("%d",&ac_no);

		while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n",
			&check.acc_no,check.name,&check.dob.month,&check.dob.day,&check.dob.year,
			&check.age,check.address,check.citizenship,check.phone,check.ac_type,&check.amt,
			&check.deposit.month,&check.deposit.day,&check.deposit.year)!=EOF)
		{
			if(check.acc_no==ac_no)
			{
				system("clear");
				test=1;
				printf("\nAccount Number : %d",check.acc_no);
				printf("\nName : %s",check.name);
				printf("\nDOB : %d/%d/%d",check.dob.month,check.dob.day,check.dob.year);
				printf("\nAge : %d",check.age);
				printf("\nAddress : %s",check.address);
				printf("\nCitizenship : %s",check.citizenship);
				printf("\nPhone : %s",check.phone);
				printf("\nAccount type : %s",check.ac_type);
				printf("\nAmount : %f\n",check.amt);

			}
		}
	}
	else if(choice==2)
	{
		char name[60];
		printf("Enter name : ");
		scanf("%s",name);

		while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n",
			&check.acc_no,check.name,&check.dob.month,&check.dob.day,&check.dob.year,
			&check.age,check.address,check.citizenship,check.phone,check.ac_type,&check.amt,
			&check.deposit.month,&check.deposit.day,&check.deposit.year)!=EOF)
		{
			if(strcmp(check.name,name)==0)
			{
				system("clear");
				test=1;
				printf("\nAccount Number : %d",check.acc_no);
				printf("\nName : %s",check.name);
				printf("\nDOB : %d/%d/%d",check.dob.month,check.dob.day,check.dob.year);
				printf("\nAge : %d",check.age);
				printf("\nAddress : %s",check.address);
				printf("\nCitizenship : %s",check.citizenship);
				printf("\nPhone : %s",check.phone);
				printf("\nAccount type : %s",check.ac_type);
				printf("\nAmount : %f\n",check.amt);

			}
		}
	}
	else 
		goto see_invalid;
	fclose(ptr);
	choice=0;
	if(test!=1)
	{
		system("close");
		printf("%s\n","Record not found" );
		invalid:
		printf("\nEnter 0 to try again and 1 to return to main menu :");
		scanf("%d",&choice);
		system("clear");
		if(choice==1)
		{
			menu();
		}
		else if(choice==0)
			exit(0);
		else
			goto invalid;
	}
	else
	{
		printf("Enter 1 to goto main menu and 0 to exit : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			system("clear");
			menu();
		}
		else
			exit(0);
	}
}

void erase()
{
	struct account remove_;
	int acc_no;
	FILE *old,*temp;
	int test=0;
	old=fopen("record.dat","r");
	temp=fopen("temp.dat","w");
	printf("Enter the account number of customer you want to delete : ");
	scanf("%d",&acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n",
			&remove_.acc_no,remove_.name,&remove_.dob.month,&remove_.dob.day,&remove_.dob.year,
			&remove_.age,remove_.address,remove_.citizenship,remove_.phone,remove_.ac_type,&remove_.amt,
			&remove_.deposit.month,&remove_.deposit.day,&remove_.deposit.year)!=EOF)
	{
		if(remove_.acc_no==acc_no)
		{
			test=1;
			printf("Deleted succesfully\n");
		}
		else
		{
			fprintf(temp,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d \n",
				remove_.acc_no,remove_.name,remove_.dob.month,remove_.dob.day,remove_.dob.year,remove_.age,remove_.address,
				remove_.citizenship,remove_.phone,remove_.ac_type,remove_.amt,
				remove_.deposit.month,remove_.deposit.day,remove_.deposit.year);
		}

	}
	fclose(old);
	fclose(temp);
	remove("record.dat");
	rename("temp.dat","record.dat");

	if(test==0)
	{
		printf("\n Record not found\n");
	}
	erase_invalid: ;
	int choice;
	printf("Enter 1 to return main menu and 2 to exit");
	scanf("%d",&choice);

	if(choice==1)
		menu();
	else if(choice==2)
		exit(0);
	else
	{
		printf("%s\n","Invalid entry" );
		goto erase_invalid;
	}	
}

void transaction()
{
	struct account update;
	int choice,test=0,acc_no;
	FILE *old,*temp;
	old=fopen("record.dat","r");
	temp=fopen("temp.dat","w");
	transaction_again:
	printf("\n Enter the Account Number of customer : ");
	scanf("%d",&acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n",
		&update.acc_no,update.name,&update.dob.month,&update.dob.day,&update.dob.year,
		&update.age,update.address,update.citizenship,update.phone,update.ac_type,&update.amt,
		&update.deposit.month,&update.deposit.day,&update.deposit.year)!=EOF)
	{
		if(update.acc_no==acc_no)
		{
			test=1;
			if(strcmp(update.ac_type,"fixed1")==0||
				strcmp(update.ac_type,"fixed2")==0||strcmp(update.ac_type,"fixed3")==0)
			{
				printf("You cannot deposit or withdraw cash in fixed account\n");
			}
			transaction_invalid:
			printf("\n\n Do you want to deposit or withdraw money\n");
			printf("Enter your choice(1 for deposit and 2 for withdrawal) : ");
			scanf("%d",&choice);
			if(choice==1)
			{
				printf("Enter the amount you want to deposit : ");
				float amt;
				scanf("%f",&amt);
				update.amt+=amt;
				printf("Deposited succesfully\n");
				printf("New balance : %f\n",update.amt);
			}
			else if(choice==2)
			{
				printf("enter the amount you want to withdraw : ");
				float amt;
				scanf("%f",&amt);
				update.amt-=amt;
				printf("withdrawed succesfully\n");
				printf("New balance : %f\n",update.amt);
			}
			else 
				goto transaction_invalid;
		}
		fprintf(temp,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d \n",
				update.acc_no,update.name,update.dob.month,update.dob.day,
				update.dob.year,update.age,update.address,
				update.citizenship,update.phone,update.ac_type,update.amt,
				update.deposit.month,update.deposit.day,update.deposit.year);
	}
	choice=0;
	fclose(temp);
	fclose(old);
	remove("record.dat");
	rename("temp.dat","record.dat");
	if(test==0)
	{
		printf("\nAccount not found\n");
		printf("Enter 1 to try again 2 to return to main menu 0 to exit : ");
		scanf("%d",&choice);
		if(choice==1)
			goto transaction_again;
		else if(choice==2)
			menu();
		else 
			exit(0);
	}
}

void view_list()
{
	struct account add;
	FILE *ptr;
	ptr=fopen("record.dat","r");
	int test=0;
	system("clear");
	printf("Acc_no name address phone\n");
	while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n",
		&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,
		&add.age,add.address,add.citizenship,add.phone,add.ac_type,&add.amt,
		&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
		printf("%d %s %s %s\n",add.acc_no,add.name,add.address,add.phone);
		test++;
	}
	fclose(ptr);
	if(test==0)
	{
		system("clear");
		printf("Account not found");
	}

	view_list_invalid: ;

	int choice;
	printf("Enter 1 to goto  main menu and 0 to exit");
	scanf("%d",&choice);
	system("clear");
	if(choice==1)
		menu();
	else if(choice==0)
		exit(0);
	else
		goto view_list_invalid;

}
void transaction_to()
{
	struct account update;
	FILE *old,*temp;
	old=fopen("record.dat","r");
	temp=fopen("temp.dat","w");
	int acc_no1,acc_no2;
	float amt;
	transaction_to_invalid:
	printf("Enter your account no : ");
	scanf("%d",&acc_no1);
	printf("Enter benificiars account no : ");
	scanf("%d",&acc_no2);
	printf("Enter the amount : ");
	scanf("%f",&amt);

	int test=0;
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n",
		&update.acc_no,update.name,&update.dob.month,&update.dob.day,&update.dob.year,
		&update.age,update.address,update.citizenship,update.phone,update.ac_type,&update.amt,
		&update.deposit.month,&update.deposit.day,&update.deposit.year)!=EOF)
	{
		if(update.acc_no==acc_no1)
		{
			test++;
			update.amt-=amt;
		}
		else if(update.acc_no==acc_no2)
		{
			test+=2;
			update.amt+=amt;
		}
		fprintf(temp,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d \n",
				update.acc_no,update.name,update.dob.month,update.dob.day,
				update.dob.year,update.age,update.address,
				update.citizenship,update.phone,update.ac_type,update.amt,
				update.deposit.month,update.deposit.day,update.deposit.year);
	}
	fclose(temp);
	fclose(old);
	remove("record.dat");
	rename("temp.dat","record.dat");
	if(test==0)
	{
		printf("Both accounts not found");
		goto transaction_to_invalid;
	}
	if(test==1)
	{
		printf("Benificiars account not found");
	}
	if(test==2)
	{
		printf("Your account not found");
	}
	if(test==3)
	{
		printf("Transaction succesfull");
	}
	int choice;
	printf("\n\nEnter 1 to retry 2 to return to menu and 0 to exit : " );
	scanf("%d",&choice);
	if(choice==1)
	{
		system("clear");
		goto transaction_to_invalid;
	}
	else if(choice==2)
		menu();
	else if(choice==0)
		exit(0);
}

void show_account_details(struct account example)
{
	printf("\nAccount Number : %d",example.acc_no);
	printf("\nName : %s",example.name);
	printf("\nDOB : %d/%d/%d",example.dob.month,example.dob.day,example.dob.year);
	printf("\nAge : %d",example.age);
	printf("\nAddress : %s",example.address);
	printf("\nCitizenship : %s",example.citizenship);
	printf("\nPhone : %s",example.phone);
	printf("\nAccount type : %s",example.ac_type);
	printf("\nAmount : %f\n",example.amt);
}
