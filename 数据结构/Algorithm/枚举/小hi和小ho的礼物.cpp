
//http://hihocoder.com/problemset/problem/1505
//思路1，动态规划保留和的值
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int num[1005];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>num[i];
	//sort函数的使用，默认为非降序排序
	sort(num,num+N);
	int i,j,p,q;//i<p<(N/2)<j<q

	unordered_map<int,int> index;
	for(int i=0;i<N;i++)
	{

		for(j=i+2;j<N;j++)
		{
			if(index.find(num[j]-num[i])!=index.end())
				++index[num[j]-num[i]];
			else
			{
				index[num[j]-num[i]]=1;
			}
		}
	}
	
	int num=0;
	for(unordered_map<int,int>::iterator i=index.begin();i!=index.end();i++)
	{

		// cout<<i->first<<' '<<i->second<<endl;

		num+=2*i->second;
	}
	cout<<num<<endl;
	return 0;
}
