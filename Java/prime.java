import java.util.Scanner;
class hello_world
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter a Number : ");
		int num=sc.nextInt();
		boolean isprime=true;
		for(int i=2;i*i<=num;i++)
		{
			if(num%i==0)
			{
				isprime=false;
				break;
			}
		}
		if(isprime)
			System.out.println(num+" is prime");
		else
			System.out.println(num+" is not prime");
	}
}
