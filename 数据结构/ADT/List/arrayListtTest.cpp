#include <iostream>
#include "arrayList.h"
using namespace std;
int main()
{
	cout<<"----------------------------------------------\n";
	cout<<"initing:generate 10 num that from 0 to 9\n";
	list* l = initList();
	for(int i=0;i<10;i++)
		insert(l,i,i);
	cout<<"----------------------------------------------\n";
	cout<<"output the data and the length of the list:\n";
	for(int i=0;i<10;i++)
		cout<<l->data[i]<<" ";
;	cout<<"length:"<<length(l)<<endl;

	//删除5次
	cout<<"----------------------------------------------\n";
	cout<<"delete the fist-half of the list\n";
	for(int i=5;i<10;i++)
		delete_(l,0);
	cout<<"----------------------------------------------\n";

	cout<<"now output the data and the length of the list:\n";
	for(int i=0;i<length(l);i++)
		cout<<l->data[i]<<" ";
	cout<<"length:"<<length(l)<<endl;
	cout<<"----------------------------------------------\n";

	cout<<"find the position of 8(the index begin with 0):\n";
	cout<<indexOf(l,8)<<endl;
	cout<<"----------------------------------------------\n";
	return 0;
}