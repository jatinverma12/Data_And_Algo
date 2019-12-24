#include<iostream>
using namespace std;



class Node
{
	public:
		int data;
		Node *next;
		
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};


class Queue
{
	public:
		Node *front,*rear;
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		void insert(Node *temp);
		int pop();
		int isEmpty();
};
void Queue::insert(Node *temp)
	{
		if(!front)
		{
			front=rear=temp;
		}
		else{
			Node *k=rear;
			while(k->next)
			k=k->next;
			k->next=temp;
			rear=k->next;
		}
		
	}
	
int Queue::pop()
	{
		Node *ptr=front;
		front=front->next;
		return ptr->data;
	}
	

int Queue::isEmpty()
{
	return front==NULL;
}

void BFS(int G[][7],int start,int n)
{
	int i=start,j;
	Queue q;
	int	visited[7]={0};
	
	cout<<i;
	visited[i]=1;
	q.insert(new Node(i));
	while(!q.isEmpty())
	{
		i=q.pop();	
		for(j=1;j<n;j++)
		{
			if(G[i][j]==1 && visited[j]==0)
			{
				cout<<j;
				visited[j]=1;
				q.insert(new Node(j));
			}
		}
	}
}

void DFS(int G[][7],int start,int n)
{	int j;
	static int visited[7]={0};
	if(visited[start]==0)
	{
		cout<<start;
		visited[start]=1;
		for(j=1;j<n;j++)
		{
			if(G[start][j]==1&& visited[j]==0)
			DFS(G,j,n);
		}
	}
}
int main()
{
	int G[7][7]={{0,0,0,0,0,0,0},
				 {0,0,1,1,0,0,0},
				 {0,1,0,0,1,0,0},
				 {0,1,0,0,1,0,0},
				 {0,0,1,1,0,1,1},
				 {0,0,0,0,1,0,0},
				 {0,0,0,0,1,0,0},
				 };
				 
	BFS(G,5,7);
	cout<<"\n";
	DFS(G,1,7);
	return 0;
	
}
