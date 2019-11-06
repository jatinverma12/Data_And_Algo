#include<iostream>
using namespace std;

void duplicacy_in_sorted(int *arr,int len)
{
	int i,j;
	for(i=0;i<len-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			j=i+1;
			while(arr[i]==arr[j])
			j++;
			int count=j-i;
			cout<<"\n"<<arr[i]<<"\tappeared\t"<<count<<"\ttimes";
			i=j-1;
		}
		
	}
	delete arr;
}

void duplicacy_in_unsorted(int *a,int len)
{
	int i,count,j;
	for(i=0;i<len-1;i++)
	{	
		if(a[i]>0)
		
		{
			count=1;
			for(j=i+1;j<len;j++)
			if(a[i]==a[j])
			{
				count++;
				a[j]=-1;
			}
			if(count<1)
		    cout<<"\n"<<a[i]<<"\tappeared\t"<<count<<"\ttimes";
		}
	}
	delete a;
}
int main()
{
	int arr[]={4,3,2,4,2,2,9,3};
	duplicacy_in_unsorted(arr,8);
}
