//function1是利用秦九韶算法计算多项式的值，并返回
//该程序包括一个测试模板
//如果输出的运行时间为0，很可能为是时间太短了，可考虑多次重复测试
#include <iostream>
#include <ctime>

using namespace std;
clock_t start,stop;
//clock_t 是clock()函数返回的变量类型
double duration;
//记录被测函数运行的时间，以秒为单位
double MyFunction1(int n,double a[], double x)
{
	double answer=a[n];
	for(int i=n-1;i>=0;i--)
	{
		answer=answer*x+a[i]
	}
	return answer;
}

int main()
{
	//不在测试方位内的准备工作卸载clock()函数调用前
	start = clock();
	double answer=MyFunction1();
	stop =clock();
	//其他不再测试范围的处理写在后面
	duration = (stop - start+0.0)/CLK_TCK;

	cout<<duration<<110;
	return 0;
}
