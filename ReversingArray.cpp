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
 
 void swap(int *a,int *b)
 {
 	int temp=*a;
 	*a=*b;
 	*b=temp;
 }
 
 void reverse()
 {
 	int i=0,j=length-1;
 	for(;i<j;i++,j--)
 	{
 		swap(&a[i],&a[j]);
	}
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
 {	int i,sz;
 
 	printf("Enter length of array:");
 	cin>>sz;
 	Array<int> b=Array<int> (sz);
 	b.reverse();
 	b.Display();
 	
 }
