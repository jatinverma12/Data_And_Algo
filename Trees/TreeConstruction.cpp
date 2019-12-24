#include<iostream>
using namespace std;
#include "Queue.cpp"

class Tree{
	public:
		Node *root;
		Tree(){root=NULL;}
		void CreateTree();
		void Preorder(Node *p);
		void Postorder(Node *p);
		void Inorder(Node *p);
		void Levelorder(Node *root);
		int Height(Node *root);
};

void Tree::CreateTree()
{
	Node *p,*t;
	int x;
	Queue q(100);
	cout<<"Enter root value";
	cin>>x;
	root=new Node(x);
	q.Enqueue(root);
	while(!q.isEmpty())
	{
		p=q.Dequeue();
		cout<<"Enter left child of "<<p->data;
		cin>>x;
		if(x!=-1)
		{
			t=new Node(x);
			q.Enqueue(t);
			p->left=t;	
		}
		cout<<"Enter right child of "<<p->data;
		cin>>x;
		if(x!=-1)
		{
			t=new Node(x);
			q.Enqueue(t);
			p->right=t;
		}
		
		
	}
	
	
}

void Tree::Preorder(Node *p)
{
	if(p)
	{
		cout<<p->data<<"->";
		Preorder(p->left);
		Preorder(p->right);	
	}
}

void Tree::Postorder(Node *p)
{
	if(p)
	{
		Postorder(p->left);
		Postorder(p->right);
		cout<<p->data<<"->";
	}
}
void Tree::Inorder(Node *p)
{
	if(p)
	Inorder(p->left);
	cout<<p->data<<"->";
	Inorder(p->right);
}
void Tree::Levelorder(Node *root)
{	Node *k=NULL;
	Queue Q(100);
	cout<<root->data<<"->";
	Q.Enqueue(root);
	while(!Q.isEmpty())
	{
		k=Q.Dequeue();
		if(k->left)
		{
			cout<<k->left->data;
			Q.Enqueue(k->left);
		}
		
		if(k->right)
		{
			cout<<k->right->data;
			Q.Enqueue(k->right);
		}	
	}

	
}

int Tree::Height(Node *root)
{
	int x=0,y=0;
	if(root==NULL)
	return 0;
	else{
		x=Height(root->left);
		y=Height(root->right);
		if(x>y)
		return x+1;
		else
		return y+1;
	}
}

