#include<iostream>
using namespace std;
 class Node
 {	public:
 	
	 	int col;
	 	int ele;
	 	Node *next;
	 	Node(int col,int ele)
	 	{
	 		this->col=col;
	 		this->ele=ele;
	 		this->next=NULL;
	 		
		}
};
 int main()
 {
 	int r,c,element;
 	cout<<"Enter rows and columns of matrix respectively";
 	cin>>r>>c;
 	Node **a=new Node*[r];
 	for(int i=0;i<r;i++)
 	{
 		for(int j=0;j<c;j++)
 		{
		 cin>>element;
 		if(element>0)
 		{
 			Node *n=new Node(j,element);
 			if(!**a[i])
 			a[i]=n;
 			else{
 				Node *temp=a[i];
 				while(temp->next!=NULL)
 				temp=temp->next;
 				temp->next=n;
			 }
		 }
	}
 		
	}
	
	for(int i=0;i<r;i++)
	{
		Node *ptr=a[i];
		for(int j=0;j<c;j++)
		{
			if (ptr->col==j)
			{
				cout<<ptr->ele;
				ptr=ptr->next
				
			}else{
				cout<<"0";
			}
			
		}cout<<"\n"
	}
 }
