#include "RadixSort.h"
#include"Tool.h"
//�����ݵ����λ��
int MaxBit(int* nums, int n)
{
	if (n <= 0) { return 0; }
	int maxData = nums[0];
	for (int i = 1; i < n; ++i)
	{//�������
		if (nums[i] > maxData) { maxData = nums[i]; }
	}

	int maxBit = 0;
	while (maxData != 0)
	{//�����λ��
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
	int* count = new int[10]{};//��¼ÿһλ��ĳ�����ֵĸ�������ʮ������0 1 ... 9
	int radix = 1;
	for (int j = 1; j <= maxBit; ++j)
	{
		//��������
		for (int i = 0; i < 10; ++i) { count[i] = 0; }

		//����
		for (int i = 0; i < n; ++i)
		{
			int curBitNum = (nums[i] / radix) % 10; //������ǰλ�ϵ�����
			++count[curBitNum];
		}

		//��������ֵ�λ�ã����Ƽ�������
		for (int i = 1; i < 10; ++i) { count[i] += count[i - 1]; }

		//���򣬴Ӻ���ǰ
		for (int i = n - 1; i >= 0; --i)
		{
			int curBitNum = (nums[i] / radix) % 10; //������ǰλ�ϵ�����
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
