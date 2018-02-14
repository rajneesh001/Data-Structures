#include<iostream>
#include<string>
#include<limits>
using namespace std;

int min(int a,int b)
{
return a<b?a:b;
}

// recursive way

int palindrome(string s,int low,int high)
{
	if(low>high)
		return INT_MAX;
	if(low == high)
		return 0;
	if(low == high-1)
		return (s[low] == s[high-1]) ? 0 :1;
	return (s.at(low) == s.at(high)) ?  palindrome(s,low+1,high-1) : min(palindrome(s,low+1,high),palindrome(s,low,high-1))+1;
}

// ierative version

int palin(string str,int n)
{
int dp[n][n],j,len;
memset(dp,0,sizeof(dp));

for(int i=1;i<n;i++)
{
	for(j=0,len = i;len<n;++j,++len)
	{
		dp[j][len] = str[j] == str[len] ? dp[j+1][len-1] : min(dp[j][len-1],dp[j+1][len])+1;
	}
}
return dp[0][n-1];
}
int main()
{
	string s;
	cin>>s;
	cout<<palindrome(s,0,s.length()-1)<<endl;   // for recursive
	cout<<palin(s,s.length())<<endl;  // for iterative
return 0;
}
