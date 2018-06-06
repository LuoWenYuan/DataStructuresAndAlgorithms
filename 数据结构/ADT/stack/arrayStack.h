/*
* Author:Leon
* Version:1.0
* Date:2018-5-15
*/
#include <iostream>
using namespace std;
// 注:define 语句后面不能有分号，有分号报错
#define MAXNUM 100
typedef int elemType;

//数组存储栈,Data存储栈的值，top保存最后一个元素的下标
typedef struct SNode
{
	elemType data[MAXNUM];
	int top;
}stack;

//初始化,返回一个指针，top等于-1表示没有栈为空
stack* initstack()
{
	stack* s= new stack;
	s->top=-1;
	return L;
}
// 压栈
void push(stack *s,elemType item)//item表示单个元素的数据
{
	if (s->top>=MAXNUM-1)
	{
		cout<<"Sorry, the array of the stack is full, so the operation is forbidden\n";
	}
	else
	{
		// s->data[s->top]=item;
		// s->top++;
		s->data[++(s->top)]=item
	}
}
//出栈,返回该元素
elemType pop(stack *s,elemType item)
{
	if (s->top==-1)
	{
		cout<<"Sorry, the array of the stack is empty, so the operation is forbidden\n";
		return;
	}
	else
	{
		// s->top--;
		// return s->data[s->top+1];
		return s->data[(s->top)--];
	}
}

bool isFull(stack *s)
{
	if (s->top==MAXNUM-1)	return true;
	else	return false;
}

bool isEmpty(stack *s)
{
	if (s->top==-1)	return true;
	else	return false;
}
