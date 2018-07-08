/*
* Author:Leon
* Version:1.0
* Date:2018-7-7
*/
//顺环队列,数组空掉一个数据来解决队列空和满是一样的问题
#include <iostream>
using namespace std;
// 注:define 语句后面不能有分号，有分号报错
#define MAXNUM 6
#define ERROR 2147483647
typedef int elemType;
//数组存储栈,Data存储栈的值，front保存最后一个元素的下标
typedef struct QNode
{
	elemType data[MAXNUM];
	int front;
	int rear;
}queue;

//初始化,返回一个指针,网课是一开始指向-1
queue* initQueue()
{
	queue* s= new queue;
	s->front=s->rear=0;
	return s;
}
// 入队
void push(queue *s,elemType item)//item表示单个元素的数据
{
	//注意判断满的条件
	if (s->front==(s->rear+1)%MAXNUM)
	{
		cout<<"Sorry, the array of the queue is full, so the operation is forbidden\n";
		return;
	}
	else
	{
		s->data[s->rear]=item;
		s->rear=(s->rear+1)%MAXNUM;
		return;
	}
}
//出队,返回该元素
elemType pop(queue *s)
{
	if (s->front==s->rear)
	{
		cout<<"Sorry, the array of the queue is empty, so the operation is forbidden\n";
		return ERROR;
	}
	else
	{
		int flag=s->front;
		s->front=(s->front+1)%MAXNUM;
		return s->data[flag];
	}
}
//返回栈顶元素
elemType top(queue *s)
{
	if (s->front==s->rear)
	{
		cout<<"Sorry, the array of the queue is empty, so the operation is forbidden\n";
		return ERROR;
	}
	else
	{

		return s->data[(s->front)];
	}
}

int queueLength(queue *s)
{
	return s->rear>=s->front?s->rear-s->front:s->rear-s->front+MAXNUM;
}