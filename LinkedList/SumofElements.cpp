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

class Linkedlist
{
	public:
		//To insert elements in linked list
		void insert(Node *temp)
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
		
		void InsertAtIndex(Node *ptr,int pos)
		{	Node *temp=head;
			if(temp!=NULL)
			{
				if(pos==0)
				{
					ptr->next=head;
					head=ptr;
				}
				
				else
				{
					for(int i=0;i<pos-1;i++)
					{
						temp=temp->next;
					}
					ptr->next=temp->next;
					temp->next=ptr;
				}
				
			}
		}
		void DeleteAtIndex(int pos)
		{
			Node *temp=head;
			Node *ptr=NULL;
			
			if(pos==0)
			{
				head=head->next;
				delete temp;
			}
			
			else
				{
				
				for(int i=0;i<pos&&temp;i++)
				{
					ptr=temp;
					temp=temp->next;
				}
				ptr->next=temp->next;
				delete temp;
			}
			
		}
		//It removes duplicates from a sorted list
		void RemoveDuplicate(Node *temp)
		{
			Node *ptr=temp->next;
			while(ptr!=NULL)
			{
				if(temp->data!=ptr->data)
				{
					temp=ptr;
					ptr=ptr->next;
				}
				else{
					temp->next=ptr->next;
					delete ptr;
					ptr=temp->next;
				}
			}
		}
		
		// To find sum of elements
		int sum(Node *ptr)
		{	int k=0;
			if(ptr==NULL)
			return 0;
			else
			{
				return ptr->data+sum(ptr->next);
			}
		}
		
		//Finding maximum in linked list
		int find_max(Node *ptr)
		{
			int max=0;
			if(ptr==NULL)
				return -32768;
			max=find_max(ptr->next);
			return max>ptr->data?max:ptr->data;
		}
		
	//Linear Search:= Searching for a given element and setting it to head so when it is searched next time it is found in O(1)
		void LinearSearch(Node *ptr,int key)
		{
			Node *q=NULL;
			while(ptr->next!=NULL)
			{
				if(ptr->data==key)
				{
					q->next=ptr->next;
					ptr->next=head;
					head=ptr;
				}
				
				q=ptr;
				ptr=ptr->next;
			}
			
		}
		
		int CheckifSorted(Node *temp)
		{	int max=-32768;
			while(temp!=NULL)
			{
				if(temp->data>max)
				{
					max=temp->data;
					temp=temp->next;
				}
				
				else
				return 0;
			}
			return 1;
		}
		
	//To display all the elements
		void display()
		{
			Node *ptr=head;
			while(ptr!=NULL)
			{
				cout<<ptr->data<<"->";
				ptr=ptr->next;
			}
		}
};
int main()
{	int d;
	char choice;
	Linkedlist l;
	
// Insertion of data in linked list
	do
	{
		cout<<"Enter data of node";
		cin>>d;
		Node *node=new Node(d);
		l.insert(node);
		cout<<"wanna continue??";
		cin>>choice;
	}while(choice=='y');
	
// finding the sum of elements of linked list	
	cout<<l.sum(head)<<"\n";
	
//finding maximum in linked list
	cout<<l.find_max(head)<<"\n";
// Implementing linear search
	l.LinearSearch(head,9);
	l.display();
//Implementing Insertion at a particular index	
	Node *n4=new Node(67);
	l.InsertAtIndex(n4,3);
	l.display();	
	
//Deletion
	l.DeleteAtIndex(1);
	l.display();
	
	
//Checking whether the list is sorted or not
	if(l.CheckifSorted(head))
	cout<<"list is sorted";
	else
	cout<<"list is not sorted";
	
//Delete Duplicates in a sorted linked list
l.RemoveDuplicate(head);
l.display();


	
}

