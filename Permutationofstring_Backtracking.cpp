#include<iostream>
using namespace std;
void perm(char s[],int k)
{	int i;
	static int a[10]={0};
	static char res[10];
	
	if(s[k]=='\0')
	{
		res[k]='\0';
		cout<<"\n"<<res;
	}
	for(i=0;s[i]!='\0';i++)
	{
		if(a[i]==0)
		{
			res[k]=s[i];
			a[i]=1;
		
		perm(s,k+1);
		a[i]=0;
		}
	}
}

int main()
{
	char name[10]="abc";
	perm(name,0);
}
