#include<iostream>
using namespace std;
class Term
{	public:
		int exp;
		int coeff;
};

class Polynomial
{
	private:
		int n;
		Term *t;
	public:
		Polynomial(int n)
		{
			this->n=n;
			t=new Term[this->n];
		}
		
	friend istream & operator>>(istream &is,Polynomial &p);
	
	friend ostream & operator<< (ostream &os,Polynomial &p);
	Polynomial operator +(Polynomial &p2);
};

	istream & operator>>(istream &is,Polynomial &p)
	{	
		
		cout<<"Enter coefficient and exponents of the terms of the polynomial";
		for(int i=0;i<p.n;i++)
		{
			cin>>p.t[i].coeff>>p.t[i].exp;
			
		}
		return is;
	}
	
	ostream & operator<<(ostream &os,Polynomial &p)
	{
	
		for(int i=0;i<p.n;i++)
		{
			cout<<p.t[i].coeff<<"x"<<p.t[i].exp<<"+";
		}
		return os;
	}
	
	Polynomial Polynomial :: operator +(Polynomial &p2)
	{
		int i=0,j=0,k=0;
		Polynomial *sum=new Polynomial(n+p2.n);
		while(i<n && j<p2.n)
		{
			if(t[i].exp>p2.t[j].exp)
				sum->t[k++]=t[i++];
			else if(t[i].exp<p2.t[j].exp)
				sum->t[k++]=p2.t[j];
			
			else
			{
				sum->t[k].exp=t[i].exp;
				sum->t[k++].coeff=t[i++].coeff + p2.t[j++].coeff;
			}
				
		}
		for(;i<n;i++)sum->t[k++]=t[i];
		for(;j<p2.n;j++)sum->t[k++]=p2.t[j];
		
		sum->n=k;
		return *sum;
		
	}
	
	int main()
	{
		Polynomial p1(3),p2(4);
		cin>>p1;
		cin>>p2;
		Polynomial sum=p1+p2;
		cout<<sum;
	}
	
	
