#include<iostream>
int gcd(int a,int b)
{
	if(a==0)
	return b;
	else{
		return gcd(b%a,a);
	}
}
int main(){
	std::cout<<gcd(25,125);
	return 0;
}
