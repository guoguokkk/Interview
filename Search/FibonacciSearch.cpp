#include"FibonacciSearch.h"
#include"QuickSort.h"
#include"Tool.h"
void Fibonacci(int* F, int max_size)
{
	F[0] = 0;
	F[1] = 1;
	int k = 2;
	while (k < max_size)
	{
		F[k++] = F[k - 1] + F[k - 2];
	}
}
int FibonacciSearch(int* nums, int n, int data)
{
	if (n <= 0) { return -1; }

	int low = 0, high = n, fibonacciSize = 20;
	int* f = new int[fibonacciSize];//初始化一个斐波那契数列
	Fibonacci(f, fibonacciSize);

	int k = 0;
	while (n > f[k]-1) { ++k; }//找到比n大的第一个数

	int* temp = new int[f[k]-1];//扩充后的数组
	memcpy(temp, nums, n * sizeof(int));
	for (int i = n; i < f[k] - 1; ++i) { temp[i] = nums[n - 1]; }

	int mid;
	while (low <= high)//查找
	{
		mid = low + f[k - 1] - 1;
		if (temp[mid] == data)
		{
			if (mid >= n) { return n - 1; }
			else { return mid; }
		}
		else if (temp[mid] < data)
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			high = mid - 1;
			k -= 1;
		}
	}
	delete[] f;
	delete[] temp;
	return -1;
}
void Test_FibonacciSearch()
{
	int nums[9] = { 8,2,4,5,3,10,11,6,9 };
	int n = 9;
	int testNum1 = 20, testNum2 = 10;
	QuickSort(nums, n);

	PrintArray(nums, n);
	std::cout << "InsertionSearch:" << std::endl;
	std::cout << testNum1 << " is the " << FibonacciSearch(nums, n, testNum1)
		<< "th num" << std::endl;
	std::cout << testNum2 << " is the " << FibonacciSearch(nums, n, testNum2)
		<< "th num" << std::endl;
}
