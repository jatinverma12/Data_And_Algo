#include<iostream>
using namespace std;
int main()
{
	int size,*a,i,min,max;
	cout<<"Enter the size of array";
	cin>>size;
	a=new int[size];
	cout<<"Enter the elements";
	for(i=0;i<size;i++)
	cin>>a[i];
	min=max=a[0];
	for(i=1;i<size;i++)
	{
		if(a[i]<min)
		min=a[i];
		else if(a[i]>max)
		max=a[i];
		
	}
	cout<<"maximum is "<<max<<" and minimum is"<<min;
	delete a;
}
