class hello_world
{
	public static void main(String[] args)
	{
		int n=10;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)
				System.out.println(i+"is even");
			else
			{
				if(i%3==0)
					System.out.println(i+" is odd and a multiple of 3");
				else
					System.out.println(i+"is odd and not a multiple of 3");
			}
		}
	}
}
