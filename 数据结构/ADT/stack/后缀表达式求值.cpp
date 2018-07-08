#include <iostream>
#include <string>
#include <stack>
#define MAXSIZE 100
#define ERROR 2147483647
using namespace std;
string str="12 3 / 6 4 * +";
bool isNum(char c)
{
    return c>='0'&&c<='9';
}
bool isOp(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/');
}
//注意如果除数为0的情况
int op(int num1,int num2,char c)
{
    int num=0;
    switch(c){
        case '+':num=num1+num2;break;
        case '-':num=num1-num2;break;
        case '*':num=num1*num2;break;
        case '/':{
        	if(num2==0)
        	{
        		cout<<"ERROR";
        		exit(0);//exit(0)表示非正常退出，1表示正常退出
        	}
        	else num=num1/num2;break;
        }
    }
    return num;
}
int fun(string str)
{
	stack<int> s;
    int num1=0;//存数
    int num2;
    
    for(int i=0;i<str.length();++i)
    {
        // cout<<110;
        if(str[i]>='0'&&str[i]<='9')
        {
            num1=num1*10+str[i]-'0';
            if(str[i+1]<'0'||str[i+1]>'9')
            {
                s.push(num1);
                num1=0;
            }
        }
        else if(isOp(str[i]))
        {
            num1=s.top();
            s.pop();
            num2=s.top();
            s.pop();
            s.push(op(num2,num1,str[i]));
            num1=0;
        }
    }
    return s.top();
}
int main()
{
    
    cout<<fun(str);
    return 0;
}
