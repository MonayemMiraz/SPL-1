#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	//chcp 65001
	//outout of unicode string
	//chcp 437
	//output in ascii
	int n=s.length();
	int i=0;
	while(i<n)
	{
		if(s[i]==' ')
		{
			cout<<" ";
			i++;
		}
		else
		{
			cout<<s[i];
			i++;
		}
	}
	cout <<s.length()<<endl;
	cout << " দেখুনঃ " << s <<endl;
	cout << " শেষ ";
	return 0;
}