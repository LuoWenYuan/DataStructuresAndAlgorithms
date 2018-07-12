//二叉树
#include<iostream>
#include <queue>
#include <stack>
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
    queue<TNode*> qu,qTest;
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
            qTest.push(qu.front());
            qu.pop();
        }
//        cout<<p->data;
        qu.push(p);
    }
    //双端队列支持clear操作，队列不支持clear操作
    //    qu = queue<TNode*>();//清空队列
    
//    while(!qTest.empty())
//    {
//        cout<<qTest.front()->data;
//        qTest.pop();
//    }
//    while(!qu.empty())
//    {
//        cout<<qu.front()->data;
//        qu.pop();
//    }
//    cout<<"test";
    
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
void InOrderTraversal(TNode *Bt)
{
    if(Bt)
    {
        InOrderTraversal(Bt->left);
        cout<<Bt->data;
        InOrderTraversal(Bt->right);
    }
}
//后序遍历，左右中
void PostOrderTraversal(TNode *Bt)
{
    if(Bt)
    {
        PostOrderTraversal(Bt->left);
        PostOrderTraversal(Bt->right);
        cout<<Bt->data;
    }
}
//遍历的非递归实现
//用栈实现前序遍历，基本思想先压入右子树，再压入左子树
void PreOrderTraversal_Stack(TNode *Bt)
{
    stack<TNode*> St;
    TNode * p = Bt;
    St.push(p);
    while(!St.empty())
    {
        p=St.top();
        cout<<p->data;
        St.pop();
        if(p->right)
        {
            St.push(p->right);
        }
        if(p->left)
        {
            St.push(p->left);
        }
    }
    /*另一种先序遍历，与下面中序遍历差不多的代码
    stack<TNode*> St;
    TNode * T = Bt;
    while(T||!St.empty())
    {
        while (T)//一直沿途将做节点压栈
        {
            cout<<St.top();//将左节点压入之前先做输出
            St.push(T);
            T=T->left;
        }
        if(!St.empty())
        {
     
            St.pop();
            T=T->right;//转向右子树
        }
    }
     */
    
}
//中序遍历
void InOrderTraversal_Stack(TNode *Bt)
{
    stack<TNode*> St;
    TNode * T = Bt;
    while(T||!St.empty())
    {
        while (T)//一直沿途将左节点压栈
        {
            St.push(T);
            T=T->left;
        }
        if(!St.empty())
        {
            cout<<St.top()->data;
            T=St.top();
            St.pop();
//            if(T->right)//不是有右子树才转向右子树，而是直接转向右子树，否则到最左边的叶子节点的时候，查不到有右子树，会无限压栈
            T=T->right;//转向右子树，不管右子树有没有，没有的话会再出栈
        }
    }
    
}
//后序遍历,难点
/*
 因为后序非递归遍历二叉树的顺序是先访问左子树，再访问右子树，最后访问根节点。当用堆栈来存储节点，必须分清返回根节点时，是从左子树返回的，还从右子树返回的。所以，使用辅助指针r，其指向最近访问过的节点。也可以在节点中增加一个标志域，记录是否已被访问。
*/
void PostOrderTraversal_Stack(TNode *Bt)
{
    stack<TNode*> St;
    TNode * T = Bt;
    TNode *pre=NULL;
    while(T||!St.empty())
    {
        if(T)//走到最左边
        {
            St.push(T);
            T=T->left;
        }
        else
        {
            T=St.top();
            if(T->right&&T->right!=pre)//右子树存在，且未被访问
            {
                T=T->right;
            }
            else
            {
                St.pop();
                cout<<T->data;
                pre=T;//记录最近访问的节点
                T=NULL;//节点访问后，重新置空，为什么？
            }
                
        }
    }
    
}
/*后序遍历2
 对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，直到搜索到没有左孩子的结点，此时该结点出现在栈顶，但是此时不能将其出栈并访问， 因此其右孩子还为被访问。所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在栈顶，此时可以将其出栈并访问。这样就 保证了正确的访问顺序。可以看出，在这个过程中，每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，才能访问它。因此需要多设置一个变量标识该结点是 否是第一次出现在栈顶。
 void postOrder2(BinTree *root)    //非递归后序遍历
 {
 stack<BTNode*> s;
 BinTree *p=root;
 BTNode *temp;
 while(p!=NULL||!s.empty())
 {
 while(p!=NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点
 {
 BTNode *btn=(BTNode *)malloc(sizeof(BTNode));
 btn->btnode=p;
 btn->isFirst=true;
 s.push(btn);
 p=p->lchild;
 }
 if(!s.empty())
 {
 temp=s.top();
 s.pop();
 if(temp->isFirst==true)     //表示是第一次出现在栈顶
 {
 temp->isFirst=false;
 s.push(temp);
 p=temp->btnode->rchild;
 }
 else                        //第二次出现在栈顶
 {
 cout<<temp->btnode->data<<" ";
 p=NULL;
 }
 }
 }
 }
 
 */
/*后序遍历3
 要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；或者P存 在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了 每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
 */
//用队列实现层序遍历，注意以下是层序遍历代码，而不是前序遍历

void LayerOrderTraversal(TNode *Bt)
{
    queue<TNode*> q;
    q.push(Bt);
    while(q.front())
    {
        cout<<q.front()->data;
        q.push(q.front()->left);
        q.push(q.front()->right);
        q.pop();
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    int elem[10]={1,2,3,4,5,6,7,8,9};
    cout<<"Let‘s start test:\n";
    TNode* p =creatBinTree(elem,9);
    //测试递归调用
    PreOrderTraversal(p);
    cout<<endl;
    InOrderTraversal(p);
    cout<<endl;
    PostOrderTraversal(p);
    cout<<endl;
    //测试非递归调用
    cout<<"---------分隔线"<<endl;
    PreOrderTraversal_Stack(p);
    cout<<endl;
    InOrderTraversal_Stack(p);
    cout<<endl;
    PostOrderTraversal_Stack(p);
    cout<<endl;
    
    //层序遍历
    LayerOrderTraversal(p);
    return 0;
}

