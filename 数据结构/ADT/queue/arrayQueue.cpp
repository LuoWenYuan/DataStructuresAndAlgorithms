#include "arrayQueue.h"
int main(int argc, char const *argv[])
{
	queue *q = initQueue();
	for(int i=0;i<7;i++)
	{
		push(q,i);
	}
	
	cout<<pop(q)<<endl;
	cout<<pop(q)<<endl;
	cout<<pop(q)<<endl;
	push(q,5);
	push(q,6);
	push(q,7);
	push(q,8);
	for(int i=0;i<7;i++)
	{
		cout<<pop(q)<<endl;
	}
	cout<<queueLength(q);
	return 0;
}
