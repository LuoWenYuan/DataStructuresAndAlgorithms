//基本策略，将中缀表达式转换为后缀表达式，然后求值
//需要一个优先级表
#include <iostream>
#include <string>
#include <unordered_map>
#include "arrayStack.h"
using namespace std;
unordered_map<char,int> opPriority;//优先级表
void initOpPriority()//初始化优先级表
{
	opPriority.insert(make_pair('(',1));
	opPriority.insert(make_pair('*',2));
	opPriority.insert(make_pair('/',2));
	opPriority.insert(make_pair('%',2));
	opPriority.insert(make_pair('+',3));
	opPriority.insert(make_pair('-',3));
	opPriority.insert(make_pair(')',4));
}
double Op(double a,double b,char op)
{
	//switch语句的用法
	switch(op){
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}

}
int main()
{
	/* code */
	initOpPriority();
	stack *numSt = initStack();
	stack *opSt = initStack();
	string str;
	getline(cin,str);//输入带有空格的字符串
	double answer=0.0;
	int num=0;//保存连续的多个字符组成的数字
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!=' ')
		{
			if(str[i]<'9'&&str[i]>'0')
			{
				num+=num*10+str[i]-'0';
			}
			else
			{
				push(numSt,num);
				num=0;
				if (!isEmpty(opSt))
				{
					char op1=opSt
				}

		}
	}  
	return 0;
}