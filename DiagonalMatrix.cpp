#include<iostream>
using namespace std;
class Diagonal
{
	private:
		int *a;
		int n;
	public:
		Diagonal()
		{
			n=2;
			a=new int[n];
		}
		Diagonal(int n)
		{
			this->n=n;
			a=new int[n];
		}
		void set(int i,int j,int x);
		int  get(int i,int j);
		void display();
		~Diagonal()
		{
			delete []a;
		}
};
void Diagonal::set(int i,int j,int x)
{
	if(i==j)
	a[i]=x;
}

int Diagonal::get(int k,int l)
{
	if(k==l)
	return a[k];
	return 0;
}
void Diagonal::display()
{	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<get(i,j);
		}
	}
}
int main()
{
	int x,i,j,p;
	cout<<"Enter size of square matrix";
	cin>>x;
	Diagonal d(x);
	for(i=0;i<x;i++)
	{
		for(j=0;j<x;j++)
		{
			cin>>p;
			d.set(i,j,p);
		}
	}
	d.display();
}
