#include<iostream>
using namespace std;
#include "TreeConstruction.cpp"

count_nodes(Node* ptr)
{
	if(ptr)
	{
		int x=count_nodes(ptr->left);
		int y=count_nodes(ptr->right);
		return x+y+1;
	}
	return 0;
}

int main()
{
	Tree t;
	t.CreateTree();
	cout<<"Total number of nodes is: "<<count_nodes(t.root);
}
