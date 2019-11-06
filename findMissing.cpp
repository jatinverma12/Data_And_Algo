#include<iostream>
using namespace std;
void findmissingSorted(int *arr,int size)
{	int i;
	int diff=arr[0]-0;
	for(i=0;i<size;i++)
	{
		if(arr[i]-i!=diff)
		{
			while(diff<arr[i]-i)
			{
				cout<<i+diff<<"\n";
				diff++;
			}
		}
	}
	delete arr;
}

void findmissingUnsorted(int *k,int len)
{
	int max=k[0],i;
	for(i=1;i<len;i++)
	{
		if(k[i]>max)
		max=k[i];
	}
	int *b=new int[max];
	for(i=1;i<max;i++)
	b[i]=0;
	for(i=0;i<len;i++)
	{
		b[k[i]]++;
	}
	for(i=1;i<max;i++)
	{
		if(b[i]==0)
		cout<<"\n"<<i;
	}
	delete k;
}

int isSorted(int *p,int length)
	{
		int i=0;
		for(;i<length-1;i++)
		{
			if(p[i]>p[i+1])
			{
				return 0;
			}
		}
		return 1;
	}
int main()
{
	int *a,len,i;
	cout<<"Enter the size of array";
	cin>>len;
	a=new int[len];
	cout<<"Enter elements";
	for(i=0;i<len;i++)
	{
		cin>>a[i];
	}
	if(isSorted(a,len))
	findmissingSorted(a,len);
	else
	findmissingUnsorted(a,len);
}
