#include<iostream>
using namespace std;

class Node{
	public:
	Node *left;
	int data;
	int height;
	Node *right;
	Node(int x)
	{
		data=x;
		height=1;
		left=right=NULL;
	}
};


class AVL{
	public:
		
		Node *LRRotation(Node *p)
		{
			Node *pl=p->left;
			Node *plr=pl->right;
			pl->right=plr->left;
			p->left=plr->right;
			plr->left=pl;
			plr->right=p;
			
			pl->height=NodeHeight(pl);
			p->height=NodeHeight(p);
			plr->height=NodeHeight(plr);
			
			return plr;
			
		}
		
		Node *LLRotation(Node *p)
		{
			Node* pl=p->left;
			Node *k=pl->right;
			p->left=k;
			pl->right=p;
			pl->height=NodeHeight(pl);
			p->height=NodeHeight(p);
			return pl;
		}
		
		Node *RLRotation(Node *p)
		{
			Node *pl=p->right;
			Node *pll=pl->left;
			p->right=pll->left;
			pl->left=pll->right;
			pll->left=p;
			pll->right=pl;
			
			p->height=NodeHeight(p);
			pl->height=NodeHeight(pl);
			pll->height=NodeHeight(pll);
			
			return pll;
			
		}
		
		Node *RRRotation(Node *p)
		{
			Node* pr=p->right;
			Node* prr=pr->right;
			p->right=prr->left;
			pr->left=p;
			p->height=NodeHeight(p);
			
			return pr;
		}
		
		
		int NodeHeight(Node *p)
		{
			int hl=p&&p->left?p->left->height:0;
			int hr=p&&p->right?p->right->height:0;
			return hl>hr?hl+1:hr+1;
		}
		
		int BalanceFactor(Node *p)
		{
			int hl=p&&p->left?p->left->height:0;
			int hr=p&&p->right?p->right->height:0;
			return hl-hr;
		}
		
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
				
			ptr->height=NodeHeight(ptr);
			
			if(BalanceFactor(ptr)==2&&BalanceFactor(ptr->left)==1)
				return LLRotation(ptr);
				
			else if(BalanceFactor(ptr)==2&&BalanceFactor(ptr->left)==-1)
				return LRRotation(ptr);
			else if(BalanceFactor(ptr)==-2&&BalanceFactor(ptr->right)==-1)
				return RRRotation(ptr);
			else if(BalanceFactor(ptr)==-2 && BalanceFactor(ptr->right)==1)
				return RLRotation(ptr);
			
			return ptr;
				
		}
		
		
		
		void display(Node *h)
		{
			if(h)
			{
				cout<<h->data<<" "<<h->height<<"\n";
				display(h->left);
				display(h->right);
			}
		}
			
		
			
	};
	
	Node *root=NULL;
int main()
{	
	AVL tree;
	root=tree.Insert(root,21);
	root=tree.Insert(root,22);
	root=tree.Insert(root,23);	
	tree.display(root);
}

