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
    TNode *root=new TNode;
    root->data=arr[0];
    root->left=root->right=NULL;
    qu.push(root);
    for(int i=1;i<size;i++)
    {
        TNode *q=qu.front();
        TNode *p=new Node;
        p->data=arr[i];
        p->left=p->right=NULL;
        if(q->left==NULL)
        {
            q->left=p;
        }
        else
        {
            q->right=p;
            //两个孩子节点都赋值后才出队
            qu.pop();
        }
        qu.push(p);
    }
    //双端队列支持clear操作，队列不支持clear操作
//    qu = queue<TNode*>();//清空队列
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
void PreOrderTraversal(TNode *Bt)
{
    if(Bt)
    {
        cout<<Bt->data;
        PreOrderTraversal(Bt->left);
        PreOrderTraversal(Bt->right);
    }
}
//中序遍历，左中右
void InOrderTraversa(TNode *Bt)
{
    if(Bt)
    {
        PreOrderTraversal(Bt->left);
        cout<<Bt->data;
        PreOrderTraversal(Bt->right);
    }
}
//后序遍历，左右中
void PostOrderTraversa(TNode *Bt)
{
    if(Bt)
    {
        PreOrderTraversal(Bt->left);
        PreOrderTraversal(Bt->right);
        cout<<Bt->data;
    }
}
//遍历的非递归实现

//用队列实现先序遍历
void InOrderTraversa_q(TNode *Bt)
{
    
}
int main(int argc, char const *argv[])
{
    /* code */
    int elem[10]={1,2,3,4,5,6,7,8,9};
    cout<<"Let start test:\n";
    TNode* p =creatBinTree(elem,9);
    PreOrderTraversal(p);
    cout<<endl;
    InOrderTraversa(p);
    cout<<endl;
    PostOrderTraversa(p);
    cout<<endl;
    return 0;
}
