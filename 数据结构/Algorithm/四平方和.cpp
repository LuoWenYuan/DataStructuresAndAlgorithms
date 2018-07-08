//输入N(N<=5000000)升序输出第一个四平方和
#include <cmath>
#include<iostream>
#include <unordered_map>
#define MAX 5000005
using namespace std;

int main()
{
	int N;
	cin>>N;
	int a=sqrt(N/4);
	int b=sqrt(N/3);
	int c=sqrt(N/2);
	int d=sqrt(N);
	int i,j,k,m;
	/*思路一:a,b,c,d都为1000到2000总枚举量10^12,10^8为一秒，超时
	for(i=0;i<=a;i++)
	{
		for(j=0;j<=b;j++)
		{
			for(k=0;k<=c;k++)
			{
				for(m=0;m<=d;m++)
					if (N==i*i+j*j+k*k+m*m)
					{
						cout<<i<<" "<<j<<" "<<k<<" "<<m;
						return 0;
					}
			}
		}
	}
	*/
	/*思路二：只枚举abc值，计算d的值是否合法，10^9超时
	int a_2,b_2,c_2;
	for(i=0;i<=a;i++)
	{
		a_2=i*i;

		for(j=0;j<=b;j++)
		{
			b_2=j*j;
			for(k=0;k<=c;k++)
			{
				c_2=k*k;
				m=N-a_2-b_2-c_2;
				//注意如何判断一个数是不是完全平方数，先开根号再乘回去
				int Y=sqrt(m);
				if(Y*Y==m)
				{
					cout<<i<<" "<<j<<" "<<k<<" "<<Y;
					return 0;
				}
			}
		}
	}
	*/
	/*思路三：只枚举a,b,计算有没有c^2+d^2符合要求的c最小值,用unordered_map来保存*/
	unordered_map<int,int> f;
	int Y;
	/*
	for (int i = 0; i <= N; ++i)
	{
		for(int j=0;j <= i;++j)
		{
			Y=i-j*j;
			m=sqrt(Y);
			if(m*m==Y)
			{
				f.insert(make_pair(i,j));
				break;
			}
		}
	}*/
	for(int i=0;i*i<=N/2;i++)
	{
		for(j=i;i*i+j*j<=N;j++)
		{
			if(f.find(i*i+j*j)==f.end())
			{
				f[i*i+j*j]=i;
			}
		}
	}
	int a_2,b_2,c_2;
	for(i=0;i<=a;i++)
	{
		a_2=i*i;

		for(j=0;j<=b;j++)
		{
			b_2=j*j;
			c_2=N-a_2-b_2;
			
			if(f.find(c_2)!=f.end())
			{
				cout<<i<<" "<<j<<" "<<f[c_2]<<" "<<int(sqrt(N-a_2-b_2-f[c_2]*f[c_2]));//注意这个取int
				return 0;
			}
		}
	}
	return 0;
}