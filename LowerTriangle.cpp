#include<iostream>
using namespace std;
 class Matrices{
 	private:
 		int *a;
 		int n;
 	public:
 		Matrices(int k)
 		{
 			n=k;
 			a=new int[n*(n+1)/2];
		}
	void UpperTriangle(int,int,int);
	void LowerTriangle(int,int,int);
	void display();
 };
 
 void Matrices::LowerTriangle(int i,int j,int x)
 {	if(i>=j)
	 {
	 		int p=i*(i-1)/2;
	 		a[p+j-1]=x;
	 }
 }
 
 void Matrices::UpperTriangle(int i,int j,int x)
 {
 	if(i<=j)
 	{
 		int p=n*(i-1)-(i-1)*(i-2)/2;
 		a[p+j-i]=x;
	 }
 }
 
 void Matrices::display()
 {
 	int i,j;
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
 		{
 			if(i>=j)
 			{
 				int p=n*(i-1)-(i-1)*(i-2)/2;
 				cout<<a[p+j-i];
			 }
			 else
			 cout<<0;
		}
		cout<<"\n";
	 }
 }
 int main()
 {
 	int size,k,i,j;
 	cout<<"enter size of array";
 	cin>>size;
 	Matrices m(size);
 	cout<<"Enter elements";
 	for(i=1;i<=size;i++)
 	{
 		for(j=1;j<=size;j++)
 		{
 			cin>>k;
 		    m.LowerTriangle(i,j,k);
		 }
	 }
	 
	 m.display();
 }
