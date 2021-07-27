class hello_world
{
	public static void main(String[] args)
	{
		int a[][]={{1,3,4},
				   {2,4,3},
				   {3,4,5}};
		int b[][]={{1,3,4},
	               {2,4,3},
	           	   {1,2,4}};
	    int[][] c=new int[a.length][a[0].length];
	    int[][] d=new int[a.length][b[0].length];
	    //imatrix addition
	    for(int i=0;i<a.length;i++)
	    {
	    	for(int j=0;j<a[0].length;j++)
	    	{
	    		c[i][j]=a[i][j]+b[i][j];
	    	}
	    }
	    //matrix multiplication
	    for(int i=0;i<a.length;i++)
	    {
	    	for(int j=0;j<b[0].length;j++)
	    	{
	    		for(int k=0;k<b.length;k++)
	    		{
	    			c[i][j]+=a[i][k]*b[k][j];
	    		}
	    	}
	    }
	    for(int i=0;i<c.length;i++)
	    {
	    	for(int j=0;j<c[0].length;j++)
	    	{
	    		System.out.print(c[i][j]+" ");
	    	}
	    	System.out.println();
	    }
	    System.out.println();
	    for(int i=0;i<d.length;i++)
	    {
	    	for(int j=0;j<d[0].length;j++)
	    	{
	    		System.out.print(c[i][j]+" ");
	    	}
	    	System.out.println();
	    }
	}
}
