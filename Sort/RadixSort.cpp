#include "RadixSort.h"
#include"Tool.h"
//求数据的最大位数
int MaxBit(int* nums, int n)
{
	if (n <= 0) { return 0; }
	int maxData = nums[0];
	for (int i = 1; i < n; ++i)
	{//求最大数
		if (nums[i] > maxData) { maxData = nums[i]; }
	}

	int maxBit = 0;
	while (maxData != 0)
	{//求最大位数
		maxData /= 10;
		++maxBit;
	}
	return maxBit;
}

void RadixSort(int * nums, int n)
{
	if (n <= 1) { return; }
	int maxBit = MaxBit(nums, n);
	int* temp = new int[n] {};
	int* count = new int[10]{};//记录每一位的某个数字的个数，共十个数字0 1 ... 9
	int radix = 1;
	for (int j = 1; j <= maxBit; ++j)
	{
		//清零数组
		for (int i = 0; i < 10; ++i) { count[i] = 0; }

		//计数
		for (int i = 0; i < n; ++i)
		{
			int curBitNum = (nums[i] / radix) % 10; //该数当前位上的数字
			++count[curBitNum];
		}

		//算出该数字的位置，类似计数排序
		for (int i = 1; i < 10; ++i) { count[i] += count[i - 1]; }

		//排序，从后向前
		for (int i = n - 1; i >= 0; --i)
		{
			int curBitNum = (nums[i] / radix) % 10; //该数当前位上的数字
			temp[count[curBitNum] - 1] = nums[i];
			--count[curBitNum];
		}

		for (int i = 0; i < n; ++i) { nums[i] = temp[i]; }
		radix *= 10;
	}
	delete[] temp;
	delete[] count;
}

void Test_RadixSort()
{
	int n = 8;
	int nums[] = { 24,52,2,4233,6324,4535,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);
	RadixSort(nums, n);
	std::cout << "after RadixSort: ";
	PrintArrayPoint(nums, n);
}
