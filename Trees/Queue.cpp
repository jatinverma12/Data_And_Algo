#include<iostream>
using namespace std;

class Node
{	public:
	Node *left;
	int data;
	Node *right;
	Node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;	
	}	
};

class Queue{
	public:
	
	int front;
	int rear;
	int size;
	Node **Q;
		Queue(int size)
		{
			front=rear=-1;this->size=size;
			Q=new Node*[this->size];
		}
	public:
		void Enqueue(Node *ptr);
		Node* Dequeue();
		int isEmpty();
};

void Queue::Enqueue(Node *ptr)
{
	if(rear==size-1)
	cout<<"queue is full";
	else{
		rear++;
		Q[rear]=ptr;
	}
}

Node* Queue::Dequeue()
{
	Node *k=NULL;
	if(front==rear)
	cout<<"queue is empty";
	else{
		k=Q[front+1];
		front++;
		
	}
	return k;
}
int Queue::isEmpty()
{
	if(front==rear)
	return 1;
	return 0;
}




