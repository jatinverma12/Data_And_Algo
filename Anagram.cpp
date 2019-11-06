#include<iostream>
using namespace std;
int main()
{	//for strings having only small letters
	char a[]="verqa";
	char b[]="aervm";
	int hash[26]={0};
	int i,j;
	for(i=0;a[i]!='\0';i++);
	for(j=0;b[j]!='\0';j++);
	int p=0;
	if(i==j)
	{
		for(i=0;a[i]!='\0';i++)
		{
			hash[a[i]-97]++;
		}
		for(j=0;b[j]!='\0';j++)
		{
			hash[b[j]-97]--;
		}
		
		for(i=0;a[i]!='\0';i++)
		{
			if(hash[a[i]-97]!=0)
			{	p=1;
				cout<<"the strings are not anagram";
				break;
			}
			
		}
		if(p==0)
		cout<<"The strings are anagram";
		
	}
	else
	cout<<"The strings are not anagram";
	return 0;
	
}
