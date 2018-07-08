//题目地址http://hihocoder.com/problemset/problem/1494
//注意：1、思路是建立直角坐标系，保存对应X位置的缝隙个数2、注意map是怎么遍历的
#include <unordered_map>
#include<iostream>
#define MAX 100000
using namespace std;

int N,num,t,sum;
unordered_map<int,int> cnt;//保存位置为x的缝隙有多少个
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {   
        sum=0;
        cin>>num;
        for(int j=1;j<=num;j++)
        {
            cin>>t;
            sum+=t;
            if(j!=num) cnt[sum]++;
        }
    }

    int mx=0;
    for(unordered_map<int,int>::iterator i=cnt.begin();i!=cnt.end();i++)
    {
        if(i->second>mx)mx=i->second;
    }
    cout<<N-mx<<endl;
    return 0;
}