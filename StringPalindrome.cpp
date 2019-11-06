#include<iostream>
using namespace std;
CheckPalindrome(char a[],char b[])
{
	int i=0;
	for(;a[i]!='\0';i++)
	{
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
	
}
int main()
{	int i,j;
	char a[]="madam";
	for(i=0;a[i]!='\0';i++);
	i=i-1;
	char b[i+1];
	for(j=0;i>=0;i--,j++)
	{
		b[j]=a[i];
	}
	b[j]='\0';
	if(CheckPalindrome(a,b))
		cout<<"It is a palindrome";
	else
		cout<<"It is not a palindrome";

}
