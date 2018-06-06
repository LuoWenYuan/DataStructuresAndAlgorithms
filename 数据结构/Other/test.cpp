struct GNode
{
	int Tag;//标志域：0表示节点是单元素，1表示节点是广义表
	union{
		elemType data;
		gList *subList;//子表指针域subList与单元素数据域data复用，即共用存储空间
	}region;
	gList *next;//指向后继结点
	
};