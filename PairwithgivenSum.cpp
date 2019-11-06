#include<iostream>
using namespace std;

void Pair(int *a,int len,int sum)
{
	int max=a[0],i;
	for(i=1;i<len;i++)
		if(a[i]>max)
			max=a[i];
	int *b=new int[max];
	for(i=0;i<max;i++)
	b[i]=0;
	
	for(i=0;i<len;i++)
	{
		b[a[i]]=1;
		if(b[sum-a[i]]==1)
		{
			cout<<"\n("<<a[i]<<","<<sum-a[i]<<")";
		}
	}
	delete a;
}
int main()
{
	int sum=10,i;
	int arr[]={1,3,6,7,4,9};
	Pair(arr,6,sum);
	return 0;
}
