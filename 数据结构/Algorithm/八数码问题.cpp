//确认初态和末态，然后用UDLR表示上下左右储存答案
//1深度优先搜索遍历，搜索到结果就结束
#include <iostream>
#include<string>
#include <set>
using namespace std;

int start[3][3],final[3][3];
string startString,finalString;//用字符串来表示是否一样，方便比较
set<int[3][3]> ins;//判断该状态是否出现过
int flag=0;//表示空格所在的位置
bool isEqual(int start[3][3],int final[3][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(start[i][j]!=final[i][j]) return false;

	return true;
}


void DFS(int i,int j)
{
	if(isEqual(start,final))
		return;
	else
	{
		int temp;
		//左移操作
		if(i!=0)
		{
			temp=start[i][j];
			start[i][j]=start[i-1][j];
			start[i-1][j]=temp;
			DFS(i-1,j);

		}
	}
}

void input()
{
	//保存空格所在的位置
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			cin>>start[i][j];
			if(start[i][j]!=-1)
				flag++;
		}
		
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>final[i][j];
}
int main()
{
	while(1)
	{
		void input();//输入八数码的初始和结束状态，默认空的位置用-1表示
		DFS(flag/3,flag%3);

	}
	return 0;
}