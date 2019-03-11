#include"Tool.h"
#include"SequentialSearch.h"
#include"BinarySearch.h"
#include"InsertionSearch.h"
#include"FibonacciSearch.h"
#include"HashTable.h"
#include"RedBlackTree.h"
int main()
{
	Test_SequentialSearch();
	std::cout << std::endl;

	Test_binarySearch();
	std::cout << std::endl;

	Test_InsertionSearch();
	std::cout << std::endl;

	Test_FibonacciSearch();
	std::cout << std::endl;

	Test_HashTable();
	std::cout << std::endl;

	Test_RedBlackTree();
	std::cout << std::endl;

	getchar();
	return 0;
}