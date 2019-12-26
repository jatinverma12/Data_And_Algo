#include<iostream>
using namespace std;
#include "Queue.cpp"



class BST{
	
	public:
		Node* Insert(Node *ptr,int key)
		{	Node *t=NULL;
			
			if(ptr==NULL)
			{	t=new Node(key);
				return t;
				
			}
			
			else if(key<ptr->data)
				ptr->left=Insert(ptr->left,key);
			else if(key>ptr->data)
				ptr->right=Insert(ptr->right,key);
				
			return ptr;
				
		}
		
		void Preorder(Node *h)
		{
			if(h)
			{
				cout<<h->data<<" "<<"\n";
				Preorder(h->left);
				Preorder(h->right);
			}
		}
		
		void Level_order_display(Node *h)
		{
			Queue q(7);
			q.Enqueue(h);
			while(!q.isEmpty())
			{
				Node *p=q.Dequeue();
				cout<<p->data;
				q.Enqueue(p->left);
				q.Enqueue(p->right);
			}
		}
		
		
};
int main()
{
	BST b;
	Node *root=NULL;
	root=b.Insert(root,8);
	root=b.Insert(root,5);
	root=b.Insert(root,10);
	root=b.Insert(root,7);
	root=b.Insert(root,9);
	b.Preorder(root);
	b.Level_order_display(root);
	return 0;

}
