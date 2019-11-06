#include<iostream>
using namespace std;

class Node
{	private:
		int data;
		Node *next;
		
	public:
	Node(int data)
	{	
		Node *first=NULL;
		first->next=NULL;
	}
	void insert(Node *temp);
	void display();	
};




void Node :: insert(int data)
{	Node *temp=new Node;
	
	if(first)
	{
		Node *ptr=first;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	else
	first=temp;
}

void Node :: display()
{
	Node *ptr=first;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->next;
	}
}

int main()
{
	Node linkedlist;
	int p=1,d;
	while(p)
	{
		cout<<"enter data";
		cin>>d;
		a.insert(d);
		
	}
	a.insert(a);
	a.display();
	
}
