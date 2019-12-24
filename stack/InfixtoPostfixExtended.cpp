#include<iostream>
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



int outstackpre(char x)
{
	if(x=='+'||x=='-')
	return 1;
	else if(x=='*'||x=='/')
	return 3;
	else if(x=='^')
	return 6;
	else if(x=='(')
	return 7;
	else if(x==')')
	return 0;
}

int instackpre(char x)
{
	if(x=='+'||x=='-')
	return 2;
	else if(x=='*'||x=='/')
	return 4;
	else if(x=='^')
	return 5;
	else if(x=='(')
	return 0;
}

int isoperand(char x)
{
	if(x=='('||x==')'||x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
	return 0;
	return 1;
}

int main()
{	Stack s;
	char *infix="((a+b)*c)-d^e^f";
	char *postfix=new char[strlen(infix)+1];
	int i=0,j=0;
	while(infix[i]!='\0')
	{	
		if(isoperand(infix[i]))
		{	
			postfix[j++]=infix[i++];
		}else
		{	
			if(top==NULL||outstackpre(infix[i])>instackpre(top->data))
			{	
				if(infix[i]!=')')
				{
					Node *n=new Node(infix[i++]);
					s.push(n);
				}
				else
				i++;
				
			}
			else{
				char k=s.pop();
				if(k!='(')
				postfix[j++]=k;
				
			}
		}
	}
	while(!s.isEmpty())
	{
		postfix[j++]=s.pop();
	}
	postfix[j]='\0';
	cout<<postfix;
	return 0;
}
