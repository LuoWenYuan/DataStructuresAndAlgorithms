/*
* Author:Leon
* Version:1.0
* Date:2018-5-8
*/
#include <iostream>
using namespace std;
// 注:define 语句后面不能有分号，有分号报错
#define MAXNUM 100
typedef int elemType;

//数组存储线性表,Datac存储线性表的值，Last保存最后一个元素的下标
typedef struct LNode
{
	elemType data[MAXNUM];
	int last;
}list;

//初始化,返回一个指针，last等于-1表示没有线性表里面没有数据
list* initList()
{
	list* L= new list;
	L->last=-1;
	return L;
}
//查找,接受两个参数，L指针指向线性表，x为需要查找的数据，返回一个整型，为x在线性表的位置，返回-1时表示没有找到该数据
int indexOf(list *L,elemType x)
{
	for(int i=0;i<=L->last;i++)
	{
		if(L->data[i]==x)
			return i;
	}
	return -1;
}

//插入，接受三个参数，L指针指向线性表，x为需要插入的数据,P为要插入的位置（从0开始）
void insert(list *L,int p,elemType x)
{
	if(L->last==MAXNUM-1)
	{
		cout<<"表满";
		return;
	}
	/*跳坑，p为last后的一个位置还是可以的
	if(p>L->last||p<0)
	{
		cout<<"要插入的位置不存在";
		return;
	}
	*/
	//以下为正确代码
	if(p>L->last+1||p<0)
	{
		cout<<"要插入的位置不存在";
		return;
	}

	for(int i=L->last;i>p;i--)
	{
		L->data[i]=L->data[i-1];
	}

	L->data[p]=x;
	L->last++;
}

//删除,接受两个参数，L指针指向线性表，y为需要删除的位置
void delete_(list *L,int p)
{
	if(p>L->last||p<0)
	{
		cout<<"要删除的位置不存在";
		return ;
	}
	for(int i=p;i<L->last;i++)
	{
		L->data[i]=L->data[i+1];
	}

	L->last--;
}

//返回长度，接受一个常数，L指向线性表
int length(list *L)
{
	return L->last+1;
}