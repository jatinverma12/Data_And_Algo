#include<iostream>
#include<process.h>
#include<string.h>
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

Node *top=NULL;
class Stack
{	
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
		
		char pop()
		{
			if(!isEmpty())
			{
				Node *k=top;
				top=top->next;
				char v=k->data;
				delete k;
				return v;
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

int isoperand(char x)
{
	if(x=='+'||x=='-'||x=='*'||x=='/')
	return 0;
	return 1;
}

int pre(char x)
{	
	if(x=='+'||x=='-')
	return 1;
	else if(x=='*'||x=='/')
	return 2;
}

int main()
{
	char *infix="a+b*c-d/e";
	Stack s;
	char *postfix=new char[strlen(infix)+1];
	int i=0,j=0;
	while(infix[i]!='\0')
	{	
		if(isoperand(infix[i]))
		{	
			postfix[j++]=infix[i++];
			
		}
		else{
			if(top==NULL||pre(infix[i])>pre(top->data))
			{	
				Node *n=new Node(infix[i++]);
				
				s.push(n);
				
			}
			else{
				postfix[j++]=s.pop();
				cout<<7;
			}
		}
	}
	
	while(!s.isEmpty())
	{
		postfix[j++]=s.pop();
	}
	// Null character needs to be added explucitly
	postfix[j]='\0';
	cout<<postfix;
}

