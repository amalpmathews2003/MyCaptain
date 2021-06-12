#include <iostream>
using namespace std;
class Time
{
private:
	int h,m,s;
public:
	Time()
	{
		h=0;
		m=0;
		s=0;
	}
	void set_time(int h,int m,int s)
	{
		this->h=h;
		this->m=m;
		this->s=s;
	}
	void get_time()
	{
		cout<<h<<" "<<m<<" "<<s<<endl;
	}
	int get_seconnds()
	{	
		int ts=0;
		ts+=s;
		ts+=m*60;
		ts+=h*60*60;

		return ts;
	}
};
int main()
{
	Time t;
	t.get_time();
	t.set_time(01,01,06);
	t.get_time();
	cout<<t.get_seconnds();
}