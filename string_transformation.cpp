#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
string transform(string str)
{
	int len = str.length();
	string str1;
	string s1;
	int count =0;
	str1 = str1 + str[0];
	for(int i=1;i<len;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(str.at(i) == str.at(j))
				count++;
		}	
		int temp = static_cast<int>(str[i]);
		temp = temp + count;
		if(temp>122)
		{
			temp = temp-122 + 96;
		}
		s1 = (char) temp;
		str1 = str1+s1;
		count=0;
	}
	return str1;

}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
	string s;
	cin>>s;
	cout<<transform(s)<<endl;
}
	return 0;
}