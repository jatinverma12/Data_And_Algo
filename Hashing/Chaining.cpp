#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *link;
	Node(int x)
	{
		data=x;
		link=NULL;
	}
};

class Chaining{
		public:
			
		void Insert(Node *hash[10],int size)
		{
			int n,t;
			Node *k;
			for(int i=0;i<10;i++)
			hash[i]=NULL;
			
			cout<<"Enter the number of elements you want to enter.";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cin>>t;
				Node *temp=new Node(t);
				if(hash[t%size])
				{
					Node *ptr=hash[t%size];
					if(t<ptr->data)
					{
						temp->link=ptr;
						hash[t%size]=temp;
							
					}
					else{
						while(t>ptr->data)
						{	k=ptr;
							ptr=ptr->link;
						}
						k->link=temp;
						temp->link=ptr;
						
					}
					
				
				}
				hash[t%size]=temp;
			}
			
		}
		
		void search(Node *hash[10],int key)
		{
			int index=key%10;
			Node *ptr=hash[index];
			int found=0;
			while(ptr&&key<=ptr->data)
			{
				if(ptr->data==key)
				{
					found=1;
					cout<<"Element found";
					break;
				}
				ptr=ptr->link;
			}
			if(found==0)
			cout<<"Element not found";
		}
		
		void display(Node *hash[10])
		{
			for(int i=0;i<10;i++)
			{
				Node *ptr=hash[i];
				while(ptr)
				{
					cout<<ptr->data<<" ";
					ptr=ptr->link;
				}
			}
		}
};

int main()
{	// I am designing this algo for modulo 10 hash funtion that's why i took size=10.
	Chaining c;
	Node *hash[10];
	c.Insert(hash,10);
	c.display(hash);
	c.search(hash,50);
	
	
	return 0;
}
