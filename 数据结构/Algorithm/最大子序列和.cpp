/*
Author:LuoWenyuan
Date:2018-1-21
Description:Max Subsequence Sum Problem
*/
#include <iostream>
#include<algorithm>
using namespace std;
typedef int elem;
#define MAX 100005

/*
Function:sum1
Description:a native solution of the problem.Complex rate n^3
Param:
	begin,the first index of the array.
	end,the last index of the array.
	num,the pointer of the array.
return: the answer of the problem.
*/
elem sum1(int begin,int end,elem *num)
{
	elem maxSum=0;
	for(int i = begin;i < end;i++)
	{
		for(int j=i;j<end;j++)
		{
			elem sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=num[k];
			}
			if(sum>maxSum) maxSum=sum;
		}
	}
	return maxSum;
}
/*
Function:sum2
Description:a improvement solution of the sum1.Complex rate n^2
Param:
	begin,the first index of the array.
	end,the last index of the array.
	num,the pointer of the array.
return: the answer of the problem.
*/
elem sum2(int begin,int end,elem *num)
{
	elem maxSum=0;
	for(int i = begin;i < end;i++)
	{
		elem sum=0;
		for(int j=i;j<end;j++)
		{
			sum+=num[j];
			if(sum>maxSum) maxSum=sum;
		}
	}
	return maxSum;
}
/*
Function:sum3
Description:divide and conquer algorithm.Complex rate N*logN
Param:
	begin,the first index of the array.
	end,the last index of the array.
	num,the pointer of the array.
return: the answer of the problem.
*/
elem sum3(int begin,int end,elem *num)
{
	if(begin==end)
	{
		if(num[begin]<0)
			return 0;
		else
			return num[begin];
	}
	else if(begin>end)
	{
		return 0;
	}
	int mid = (begin+end)/2;
	elem sumMidPre=0;
	elem maxMidPre=0;
	for(int i = mid;i>=0;i--)
	{
		sumMidPre+=num[i];
		if(maxMidPre<sumMidPre) maxMidPre=sumMidPre;
	}
	elem sumMidLater=0;
	elem maxMidLater=0;
	for(int i = mid+1;i<end;i++)
	{
		sumMidPre+=num[i];
		if(maxMidLater<sumMidLater) maxMidLater=sumMidLater;
	}
	return max(max(sum3(begin,mid,num),sum3(mid+1,end,num)),maxMidPre+maxMidLater);
}
/*
Function:sum4
Description:Online manage.Complex rate N
Param:
	begin,the first index of the array.
	end,the last index of the array.
	num,the pointer of the array.
return: the answer of the problem.
*/
elem sum4(int begin,int end,elem *num)
{
	elem thisSum,maxSum;
	thisSum=maxSum=0;
	for(int i=begin;i<end;i++)
	{
		thisSum+=num[i];//向右累加
		if(thisSum>maxSum)
			maxSum=thisSum;//发现更大的和则更新当前结果
		if(thisSum<0)//如果当前子列和为负
			thisSum=0;//则不可能使后面的部分和增大，抛弃之
	}
	return maxSum;
}
int main()
{
	int n;
	cin>>n;
	elem *num = new elem [n];
	for (int i=0;i<n;i++)
		cin >> num[i];
	cout<<sum4(0,n,num);
	return 0;
}
