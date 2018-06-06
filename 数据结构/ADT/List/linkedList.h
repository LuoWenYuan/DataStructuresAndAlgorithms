/*
* Author:Leon
* Version:1.0
* Date:2018-5-8
*/
#include <iostream>
using namespace std;
#define MAXNUM 100
typedef int elemType;

//链表存储线性表,Data存储节点的值，next指针指向元素的下一个位置
typedef struct LNode
{
	elemType data;
	struct LNode *next;
}list;

//初始化,返回一个头结点
list* initList()
{
	list* L= new list;
	L->next=NULL;
	return L;
}
//查找,接受两个参数，L指针指向线性表，x为需要查找的数据，返回一个整型，为x在线性表的位置，返回-1时表示没有找到该数据
int indexOf(list *L,elemType x)
{
	int flag=0;
	list *LN=L->next;
	while(LN)
	{
		if(LN->data==x)
			return flag;
		flag++;
		LN=LN->next;
	}
	return -1;
}

//按序号查找,返回该序号的顺序,返回节点的好处是在删除和插入操作可以直接调用这个节点，而返回elemType就不行
list* findKth(list *L,int position)
{
	int flag=0;
	list* LN=L;

	while(LN)
	{
		if(flag==position)
			return LN;
		flag++;
		LN=LN->next;
	}
	//没找到返回NULL；
	return NULL;
}

//插入，接受三个参数，L指针指向线性表，x为需要插入的数据,P为要插入的位置（从0开始）
void insert(list *L,int p,elemType x)
{
	int flag = 0;
	list* LN = findKth(L,p);
	if(!LN)
	{
		cout<<"位置错误";
		return;
	}

	list* node = new list;
	node->data=x;
	node->next=LN->next;
	LN->next=node;	
}

//删除,接受两个参数，L指针指向线性表，y为需要删除的位置
void delete_(list *L,int p)
{
	int flag = 0;
	list* LN = findKth(L,p);
	if(!LN)
	{
		cout<<"位置错误";
		return;
	}
	list* node = LN->next;
	LN->next=LN->next->next;
	delete node;
}

//返回长度，接受一个常数，L指向线性表
int length(list *L)
{
	int flag=0;
	list *LN=L;
	while(LN->next)
	{
		flag++;
		LN=LN->next;
	}
	return flag; 
}

void Print(list *L)
{
	list *LN=L->next;
	while(LN)
	{
		cout<<LN->data<<" ";
		LN=LN->next;
	}
	cout<<endl;
}