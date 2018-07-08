//自己简单实现一个简单的栈来实现括号匹配,一下用法适用于快速实现一个简单的栈和队列的操作
#include <iostream>
#include<string>
#define MAXSIZE  10000
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	//栈的初始化
	char stack[MAXSIZE];
	int top=-1;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
		{
			stack[++top]='(';//入栈
		}
		else
		{
			if(top==-1)
			{
			cout<<"error";
			return 0;
			}
			else
			{
				--top;//出栈
			}
		}
	}
	if(top==-1)
	{
		cout<<"right";
		return 0;
	}
	else
	{
		cout<<"error";
		return 0;
	}
	return 0;
}

/*
//栈的基本应用，使用STL模板库实现
//输入：一个包含左括号和右括号的字符串如(())
//输出：判断该字符串是否为合法的括号匹配的字符串
#include <iostream>
#include<string>
#include <stack>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	stack<char> st;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
			st.push('(');
		else if(str[i]==')')
		{

			if (st.empty()||st.top()==')')
			{
				cout<<"error";
				return 0;
			}
			else{
				st.pop();
			}
		}
		else
		{
			cout<<"error";
			return 0;
		}
	}
	if(st.empty())
	{
		cout<<"right";
			return 0;
	}
	else
	{
		cout<<"error";
		return 0;
	}
	return 0;
}
*/