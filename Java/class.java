class employee
{
	String name;
	int year_of_joining;
	int salary;
	String address;
	employee(String name,int year_of_joining,int salary,String address)
	{
		this.name=name;
		this.year_of_joining=year_of_joining;
		this.salary=salary;
		this.address=address;
	}
}
	
class hello_world
{
	public static void main(String[] args)
	{
		employee a[]=new employee [3];

		String names[]={"emp1","emp2","emp3"};
		int year_of_joinings[]={2000,2001,2004};
		int salarys[]={10000,10010,11100};
		String addresses[]={"add1","add2","add3"};

		for(int i=0;i<3;i++)
			a[i]=new employee(names[i],year_of_joinings[i],salarys[i],addresses[i])	;
		for(int i=0;i<3;i++)
		{
			System.out.println("Name "+a[i].name);
			System.out.println("year_of_joining "+a[i].year_of_joining);
			System.out.println("salary "+a[i].salary);
			System.out.println("address "+a[i].address);
			System.out.println();
		}

	}
}
