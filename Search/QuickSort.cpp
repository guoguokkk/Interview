#include "QuickSort.h"
void QuickSortR(int* nums, int start, int end)
{
	if (start >= end) { return; }//一个数或者0个数不需要排序
	int first = start, last = end;
	int key = nums[first];
	while (first < last)
	{
		while (first < last&&nums[last] >= key) { --last; }
		if (first < last) { nums[first++] = nums[last]; }

		while (first < last&&nums[first] <= key) { ++first; }
		if (first < last) { nums[last--] = nums[first]; }
	}
	nums[first] = key;

	QuickSortR(nums, start, first - 1);//左半部分排序
	QuickSortR(nums, first + 1, end);//右半部分排序
}

void QuickSort(int * nums, int n)
{
	if (n <= 1) { return; }
	QuickSortR(nums, 0, n - 1);
}