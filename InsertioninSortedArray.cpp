#include <iostream>
using namespace std;

template<class T>
class Array
{
private:
	 int length;
	 T *a;
public:
	
	Array(int sz)
	{	int i=0;
		length=sz;
		a=new T[length];
		cout<<"enter elements";
		for(i=0;i<length;i++)
		cin>>a[i];
	}
	
	int isSorted()
	{
		int i=0;
		for(;i<length-1;i++)
		{
			if(a[i]>a[i+1])
			{
				return 0;
			}
		}
		return 1;
		}
	
	void Insert(T x)
	{
		int i=length-1;
		while(a[i]>x)
		{	a[i+1]=a[i];
			i--;
		}
		a[i+1]=x;
		length++;
	}
	
	void Display()
	{
		int i;
		for(i=0;i<length;i++)
		cout<<a[i];
	}

	~Array()
	{
		delete []a;
	}
};

int main()
{
	int i,x,sz;
 
 	
 	cout<<"Enter length of array:";
 	cin>>sz;
 	Array<int> b=Array<int> (sz);
 	cout<<"enter element to be added";
 	cin>>x;
 	
	 
	 if(b.isSorted())
	 {
	 	b.Insert(x);
	 	b.Display();
	 	
	}
	 	
	else
		printf("Array is not sorted so can't add directly");
		
	 
}
