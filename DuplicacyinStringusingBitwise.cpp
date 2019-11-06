#include<iostream>
using namespace std;
int main()
{	int i;
	char s[]="finding";
	int H=0;
	for(i=0;s[i]!='\0';i++)
	{
		int x=1;
		x=x<<s[i]-97;
		if(H&x)			//MASKING
			cout<<"\n"<<s[i]<<" is duplicate";
		else
			H=H|x;		//MERGING
	}
}
