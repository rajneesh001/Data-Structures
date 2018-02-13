#include <iostream>
#include <utility>
#include<map>
#include<cmath>
using namespace std;

int distance(int p,int q,int min_of_levels,int base_level)
{
	int mid = pow(2,min_of_levels)/2;

	if((p<mid && q>=mid) || (p>=mid && q<mid))
			return 2*(min_of_levels-base_level);
	
	if((p<=mid && q<=mid)||(p>=mid && q>=mid))
	 return distance(p,q,min_of_levels,base_level+1);		
}

int find_level(int x)
{
	int k=1;
	int p = 2;
	while(x>p-1)
	{
		++k;
		p = pow(2,k);
	}
	return k;
}

int find_position(int x)
{
	int level = find_level(x);
	int count=1;
	for(int i=pow(2,level-1);i<=pow(2,level)-1;i++)
	{
		if(x==i)
			break;
		else
			count++;
	}
	return count;

}

int main()
{
	int tc;
	cin>>tc;
	int x,y;
	while(tc--)
	{
		cin>>x>>y;

	if(x==y){
		cout<<0<<endl;
		continue;
	}

	int level_for_x = find_level(x);
	cout<<"level_for_x"<<level_for_x<<endl;
	int level_for_y = find_level(y);
	cout<<"level_for_y"<<level_for_x<<endl;
	int position_for_x = find_position(x);
	cout<<"position_for_x"<<level_for_x<<endl;
	int position_for_y = find_position(y);
	cout<<"position_for_y"<<level_for_x<<endl;

	int level_diff = (level_for_x > level_for_y) ? level_for_x - level_for_y : level_for_y - level_for_x;
	int min_of_levels = position_for_x < position_for_y ? position_for_x : position_for_y;

	int p = level_for_x > level_for_y ? x : y; 
	int q =  level_for_x < level_for_y ? x :y;

		for(int i=level_diff;i >0;i--)
		{
			p = p/2;
		}

		int dis = distance(p,q,min_of_levels,1);

		cout<< dis + level_diff<<endl;
	}

return 0;	
}