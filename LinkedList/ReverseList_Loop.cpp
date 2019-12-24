#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};

Node *head=NULL;

class LinkedList
{
	public:
		void insert(Node *temp);
		void ReversingElemets(Node *temp);
		void ReversingLinks();
		void RecursionReverse(Node *q,Node *temp);
		 int Loop(Node *ptr);
		void display();
};

void LinkedList::insert(Node *temp)
	{
		if(head)
		{
			Node *ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=temp;
			}
		else
			head=temp;
	}
void LinkedList::ReversingElemets(Node *temp)
{	int i=0,a[20];
	while(temp!=NULL)
	{
		a[i]=temp->data;
		i++;
		temp=temp->next;
	}
	temp=head;
	i=i-1;
		while(temp!=NULL)
	{
		temp->data=a[i];
		i--;
		temp=temp->next;
	}
	
}

void LinkedList:: display()
{
	Node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
}

void LinkedList::ReversingLinks()
{
	Node *p=head;
	Node *q=NULL,*r=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	head=q;
}
void LinkedList::RecursionReverse(Node *q,Node *temp)
{	
	if(temp==NULL)
	{
			head=q;
	}
	 else
	{
		RecursionReverse(temp,temp->next);
		temp->next=q;
		q->next=NULL;
	}
	
}

int LinkedList::Loop(Node *ptr)
{
	Node *temp=ptr;
	while(ptr!=NULL)
	{
		temp=temp->next;
		ptr=ptr->next->next;
		if(ptr==temp)
		return 1;
		else
		return 0;
	}
}

int main()
{
	Node *n1=new Node(4);
	Node *n2=new Node(5);
	Node *n3=new Node(6);
	LinkedList l;
	l.insert(n1);
	l.insert(n2);
	l.insert(n3);
	//Implementation using recursion
	l.RecursionReverse(head,head->next);
	//Implementation using reversing links
	l.ReversingLinks();
	//Implementation using reversing elements
	l.ReversingElemets(head);
	l.display();
	// Checking if loop exists
	if(l.Loop(head))
	cout<<"Loop exists";
	else
	cout<<"Loop does not exist";
}
