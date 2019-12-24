#include<iostream>
#include<process.h>
using namespace std;

class Node
{	public:
	char data;
	Node *next;	
	Node(char c)
	{
		data=c;
		next=NULL;
	}
};


class Stack
{	Node *top;
	public:
		Stack()
		{
			top=NULL;
		}
		void push(Node *temp)
		{	Node *i=new Node('u');
			if(i==NULL)
			cout<<"stack is full";
			
			else{
				temp->next=top;
				top=temp;
			}
		}
		
		int isEmpty()
		{
			if(top==NULL)
			return 1;
			return 0;
		}
		
		void pop()
		{
			if(!isEmpty())
			{
				Node *k=top;
				top=top->next;
				delete k;
			}
		}
		void display()
		{
			Node *t=top;
			while(t!=NULL)
			{
				cout<<t->data<<"->";
				t=t->next;
			}
		}
};

int main()
{	Stack s;
	char *a="((a+b)*(c+d)))";
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='(')
		s.push(new Node('('));
		else if(a[i]==')')
		{
			if(!s.isEmpty())
			s.pop();
			else
			{
				cout<<"not balanced";
				exit(0);
			}
		}
		
		
	}
	if(s.isEmpty())
	cout<<"paranthesises are balanced";
	else
	cout<<"paranthesises are not balanced";
}
