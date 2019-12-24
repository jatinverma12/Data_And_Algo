#include<iostream>
#include<math.h>
using namespace std;

class Node{
	public:
		
		int coeff;
		int pow;
		Node *next;
};
Node *head=NULL;

class Polynomial
{
	public:
		void create();
		void display();
		void eval(int );
};

void Polynomial::create()
{	int n;
	cout<<"Enter no. of terms";
	cin>>n;
	Node *temp,*last;
	cout<<"Enter coeff and power of each term resp";
	for(int i=0;i<n;i++)
	{
		cin>>temp->coeff>>temp->pow;
		temp->next=NULL;
		if(i==0)
		head=temp=last;
		else{
			last->next=temp;
			last=temp;
		}
	
	}
}
void Polynomial::display()
{
	Node *ptr=head;
	while(ptr)
	{
		cout<<ptr->coeff<<"x"<<ptr->pow<<"+";
	}
}

void Polynomial::eval(int x)
{
	Node *ptr=head;
	int sum=0;
	while(ptr)
	{
		sum+=ptr->coeff*pow(x,ptr->pow);
	}
}
void main()
{
	
}
