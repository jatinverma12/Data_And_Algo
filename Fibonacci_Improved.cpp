#include<iostream>
#include<vector>

int main(){
	int n,t;
	std::cin>>n;
	std::vector <int> numbers(n);
	numbers[0]=0;
	numbers[1]=1;
	for(int i=2;i<n;i++)
	{
		numbers[i]=numbers[i-1]+numbers[i-2];
	}
	std::cout<<numbers[n-1];
	
	
	
}
