//二叉树
#include<iostream>
#include <queue>
using namespace std;
#define Elem int
typedef struct Node
{
	Elem data;
	Node *left;
	Node *right;
}TNode;
/*
template<class T>
void swap(T &a,T &b)
{
	T c(a);
	a=b;
	b=c;
}
//清空队列
void clear(queue<TNode*> &qu)
{
	queue<TNode*> empty*();
	swap(qu,empty);
}
*/

//使用队列初始化一个完全二叉树
//压入一个空的根节点
//出队一个节点，赋值，压入其左右为空的子节点
TNode* creatBinTree(Elem *arr,int size)
{
	queue<TNode*> qu;
	if(size<=1)
	{
		cout<<"ERROR";
		exit(0);
	}
	TNode *root=NULL;
	qu.push(root);
	
	for(int i=0;i<size;i++)
	{
		TNode *p=qu.front();
		p=new Node;
		p->data=arr[i];
		p->left=p->right=NULL;
		qu.push(p->left);
		qu.push(p->right);		
	}
	//双端队列支持clear操作，队列不支持clear操作
	qu = queue<TNode*>();//清空队列
	return root;
}
bool isEmpty(TNode* Bt)
{
	return Bt==NULL;
}
void traversal(TNode* Bt)
{

}

//遍历的递归实现

//先序遍历，中左右
//中序遍历，左中右
//后序遍历，左右中

//遍历的非递归实现

int main(int argc, char const *argv[])
{
	/* code */
	cout<<"test";
	return 0;
}