//THIS IS A MAX HEAP
#include<iostream>
using namespace std;

class Heap{
	public:
		int size,*a;
		Heap(int size)
		{
			this->size=size;
			a=new int[this->size];
			a[0]=0;
		}
		void Insert(int);
		void CreateHeap();
		void display();
		void remove(int);
};


void Heap::Insert(int n)
{
	//n is index of the element to be added to heap
	int temp,i=n;
	temp=a[n];
	while(i>1 && temp>a[i/2])
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i]=temp;
}


void Heap::CreateHeap()
{
	
	int i;
	for(i=2;i<=size;i++)
	{
		Insert(i);
	}
}

void Heap::display()
{
	int i;
	for(i=1;i<=size;i++)
	cout<<a[i]<<" ";
}

void Heap::remove(int n)
{
	int i,j,x;
	x=a[1];
	a[1]=a[n];
	a[n]=x;
	i=1;j=i*2;
	while(j<n-1)
	{
		if(a[j+1]>a[j])
		j=j+1;
		if(a[j]>a[i])
		{
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			i=j;
			j=2*i;
		}
		else break;
	}
	
}


int main()
{	int size;
	cout<<"Enter size of the heap to be generated";
	cin>>size;
	Heap h(size);
	cout<<"\nEnter elements to be inserted";
	for(int i=1;i<=size;i++)
	cin>>h.a[i];
	h.CreateHeap();
	cout<<"\nHeap generated is: \n";
	h.display();
	//heap sort=when you delete all elements the array get sorted
	int k=size;
	while(k>1)
	{
		h.remove(k);
		k--;
	}
	
	cout<<"\nAfter performing heap sort:\n";
	h.display();
	
}
