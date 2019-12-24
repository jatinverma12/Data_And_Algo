#include<iostream>
using namespace std;

class Node
{	public:
		Node *prev;
		int data;
		Node *next;
		
		Node(int data)
		{
			this->prev=NULL;
			this->next=NULL;
			this->data=data;
		}
};
Node *head=NULL;

class LinkedList
{
	public:
		void insert(Node *ptr);
		void reverse(Node *);
		void display();
};

void LinkedList::insert(Node *ptr)
{
	if(head==NULL)
	{
		head=ptr;
		
	}
	else
	{
		Node *temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		
		temp->next=ptr;
		ptr->prev=temp;
	}
}

void LinkedList::display()
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}

void LinkedList::reverse(Node *temp)
{
	
	while(temp!=NULL)
	{
		Node *k=temp->prev;
		temp->prev=temp->next;
		temp->next=k;
		temp=temp->prev;
		
		if(temp!=NULL && temp->next==NULL)
		head=temp;
	}
}
int main()
{
	LinkedList L;
	Node *n1=new Node(2);
	Node *n2=new Node(8);
	Node *n3=new Node(10);
	Node *n4=new Node(15);
	
	L.insert(n1);
	L.insert(n2);
	L.insert(n3);
	L.insert(n4);

	
	L.display();
	L.reverse(head);
	L.display();
}


