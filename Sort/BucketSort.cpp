#include "BucketSort.h"
#include"Tool.h"
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int val = 0) :val(val), next(NULL) {}
};

ListNode* Merge(ListNode* head, ListNode* curHead)
{
	ListNode* tempHead = new ListNode(0);
	ListNode* temp = tempHead;
	while (head != NULL && curHead != NULL)
	{
		if (head->val < curHead->val)
		{
			temp->next = head;
			head = head->next;
		}
		else
		{
			temp->next = curHead;
			curHead = curHead->next;
		}
		temp = temp->next;
	}

	if (head != NULL) { temp->next = head; }
	if (curHead != NULL) { temp->next = curHead; }
	return tempHead->next;
}

void Insert(ListNode*& head, int data)//指针的引用
{
	ListNode* newHead = new ListNode(data);
	newHead->next = head;
	if (head == NULL) { head=newHead; }

	ListNode* pre = newHead;
	ListNode* cur = pre->next;
	while (cur != NULL)
	{
		if (cur->val > data) { break; }
		pre = cur;
		cur = cur->next;
	}

	if (pre == newHead) { head=newHead; }
	pre->next = newHead;
	newHead->next = cur;
}

void BucketSort(int * nums, int n)
{
	if (n <= 1) { return; }

	//先把所有的数据都分到各个桶中
	int bucket_num = 10;
	ListNode** bucket = new ListNode*[bucket_num] {};
	for (int i = 0; i < n; ++i)
	{
		int index = nums[i] / bucket_num;
		Insert(bucket[index], nums[i]);
	}

	//合并
	ListNode* head = bucket[0];
	for (int i = 1; i < bucket_num; ++i)
	{
		Merge(head, bucket[i]);
	}

	//把数字存到数组
	int i = 0;
	ListNode* temp = head;
	while (temp != NULL)
	{
		nums[i++] = temp->val;
		temp = temp->next;
	}
	delete[] bucket;
}

void Test_BucketSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);
	BucketSort(nums, n);
	std::cout << "after BucketSort: ";
	PrintArrayPoint(nums, n);
}
