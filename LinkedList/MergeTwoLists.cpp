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

Node *first=NULL;
Node *second=NULL;

class LinkedList
{
	public:
		Node* insert(Node *temp,Node *head);
		Node *Merge(Node *first,Node *second);
		void display(Node *head);
};
Node* LinkedList::insert(Node *temp,Node *head)
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
			return head;
	}
	
void LinkedList:: display(Node *head)
{
	Node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
}

Node* LinkedList::Merge(Node *first,Node *second)
{
	Node *third=NULL,*last=NULL;
	if(first->data<second->data)
	{
		third=last=first;
		first=first->next;
		third->next=NULL;
	}
	else
	{
		third=last=second;
		second=second->next;
		third->next=NULL;
	}
	
	while(first && second)
	{
		if(first->data<second->data)
		{
			last->next=first;
			last=first;
			first=first->next;
			last->next=NULL;
		}
		else
		{
			last->next=second;
			last=second;
			second=second->next;
			last->next=NULL;
		}
		
	}
		if(first)
		last->next=second;
		else if(second)
		last->next=first;
		
		return third;
}

int main()
{
	LinkedList L;
	Node *n1=new Node(2);
	Node *n2=new Node(8);
	Node *n3=new Node(10);
	Node *n4=new Node(15);
	first=L.insert(n1,first);
	first=L.insert(n2,first);
	first=L.insert(n3,first);
	first=L.insert(n4,first);
	
	L.display(first);
	
	LinkedList M;
	Node *m1=new Node(4);
	Node *m2=new Node(7);
	Node *m3=new Node(12);
	Node *m4=new Node(14);
	
	
	second=M.insert(m1,second);
	second=M.insert(m2,second);
	second=M.insert(m3,second);
	second=M.insert(m4,second);
	cout<<"\n";
	M.display(second);

	Node *third=L.Merge(first,second);
	cout<<"\n";
	L.display(third);
}
