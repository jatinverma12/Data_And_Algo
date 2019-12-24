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
		void display();
		void displayRecursive(Node *head);
		void insert(Node *);
		void insertAtindex(int,Node *);
		void deleteAtindex(int);
};

	void LinkedList::display()
		{	Node *ptr=head;
			do{
				cout<<ptr->data<<"->";
				ptr=ptr->next;
				
			}while(ptr!=head);
		}
		
	
	void LinkedList::displayRecursive(Node *head)
	{	Node *ptr=head;
		static int flag=0;
		if(ptr!=head||flag==0)
		{
			flag=1;
			cout<<ptr->data;
			displayRecursive(ptr->next);
		}
	}
	
	void LinkedList::insert(Node *ptr)
	{
		if(head==NULL)
		{
			head=ptr;
			head->next=head;
		}
		else{
			Node *temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=head;
		}
	}
	
	void LinkedList::insertAtindex(int pos,Node *ptr)
	{		Node *temp=head;
		if(pos==0)
		{
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=head;
		}
		else{Node *k;
			for(int i=0;i<=pos-2;i++)
			{
				k=temp;
				temp=temp->next;
			}
			k->next=ptr;
			ptr->next=temp;
			
		}
	}
	
	void LinkedList::deleteAtindex(int pos)
	{	Node *ptr=head,*k;
		if(pos==1)
		{
			
			while(ptr->next!=head)
			ptr=ptr->next;
			
			ptr->next=head->next;
			delete head;
			head=ptr->next;
			
		}
			
		else
		{
		
			for(int i=0;i<pos-2;i++)
			{
				ptr=ptr->next;
			}
			k=ptr->next;
			ptr->next=k->next;
			delete k;
			
		}
		
		
	}
	
int main()
{
	Node *n1=new Node(3);
	Node *n2=new Node(4);
	Node *n3=new Node(5);
	Node *n4=new Node(7);
	LinkedList L;
	L.insert(n1);
	L.insert(n2);
	L.insert(n3);
	L.insert(n4);
	Node *n5=new Node(34);
	L.display();
	L.insertAtindex(3,n5);
	
	L.display();
	L.deleteAtindex(3);
	L.display();}
