#include "BinarySearch.h"
#include"Tool.h"
#include"QuickSort.h"

int BinarySearchCore(int* nums, int min, int max, int data)
{
	if (min > max) { return -1; }
	int mid;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (nums[mid] == data) { return mid; }
		else if (nums[mid] < data) { min = mid + 1; }
		else { max = mid - 1; }
	}
	return -1;
}

//·Çµİ¹é
int BinarySearch(int* nums, int n, int data)
{
	if (n <= 0) { return -1; }
	return BinarySearchCore(nums, 0, n - 1, data);
}

int BinarySearchRCore(int* nums, int min, int max, int data)
{
	if (min > max) { return -1; }
	int mid = (min + max) / 2;
	if (nums[mid] == data) { return mid; }
	else if (nums[mid] < data) { BinarySearchRCore(nums, mid + 1, max, data); }
	else { BinarySearchRCore(nums, min, mid - 1, data); }
}

//µİ¹é
int BinarySearchR(int* nums, int n, int data)
{
	if (n <= 0) { return -1; }
	return BinarySearchRCore(nums, 0, n - 1, data);
}

void Test_binarySearch()
{
	int nums[9] = { 8,2,4,5,3,10,11,6,9 };
	int n = 9;
	int testNum1 = 20, testNum2 = 10;
	QuickSort(nums, n);

	PrintArray(nums, n);
	std::cout << "BinarySearch:" << std::endl;
	std::cout << testNum1 << " is the " << BinarySearch(nums, n, testNum1)
		<< "th num" << std::endl;
	std::cout << testNum2 << " is the " << BinarySearch(nums, n, testNum2)
		<< "th num" << std::endl;

	std::cout << "BinarySearchR:" << std::endl;
	std::cout << testNum1 << " is the " << BinarySearchR(nums, n, testNum1)
		<< "th num" << std::endl;
	std::cout << testNum2 << " is the " << BinarySearchR(nums, n, testNum2)
		<< "th num" << std::endl;
}
