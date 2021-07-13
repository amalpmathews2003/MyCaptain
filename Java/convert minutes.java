import java.util.*;
class temp
{
	public static void main(String[] args) {
	Scanner sc=new Scanner(System.in);
	int minutes=sc.nextInt();
	int c1=60*24*365,c2=60*24;
	//c1 minutes in a year
	//c2 minutes in a day
	int years,days;
	years=minutes/c1;
	days=(minutes-years*c1)/c2;
	System.out.println(years);
	System.out.println(days);
	System.out.println(minutes+" minutes is approximately "+years+" years and "+days+" days");
	}
}
