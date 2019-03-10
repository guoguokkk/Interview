# Contents  
- [Sort](#Sort)


# Sort
## 1 排序
### 1.1  [冒泡排序](https://github.com/guoguokkk/Interview/blob/master/Sort/BubbleSort.cpp)
（无序区，有序区）。从无序区通过交换找出最大元素放到有序区前端。
冒泡排序思路：
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

### 1.2 [选择排序](https://github.com/guoguokkk/Interview/blob/master/Sort/SelectionSort.cpp)
（有序区，无序区）。在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少。
选择排序思路：
1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
3. 以此类推，直到所有元素均排序完毕

### 1.3 [插入排序](https://github.com/guoguokkk/Interview/blob/master/Sort/InsertSort.cpp)
（有序区，无序区）。把无序区的第一个元素插入到有序区的合适的位置。对数组：比较得少，换得多。
插入排序思路：
1. 从第一个元素开始，该元素可以认为已经被排序
2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
5. 将新元素插入到该位置后
6. 重复步骤2~5

### 1.4 [快速排序](https://github.com/guoguokkk/Interview/blob/master/Sort/QuickSort.cpp)
（小数，基准元素，大数）。在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。
快速排序思路：
1. 选取第一个数为基准
2. 将比基准小的数交换到前面，比基准大的数交换到后面
3. 对左右区间重复第二步，直到各区间只有一个数

### 1.5 [堆排序](https://github.com/guoguokkk/Interview/blob/master/Sort/HeapSort.cpp)
堆排序：（最大堆，有序区）。从堆顶把根卸出来放在有序区之前，再恢复堆。

- 空间复杂度：堆排序数据交换时需要一个辅助空间，故空间复杂度是O（1） 
- 在构建堆(初始化大顶堆)的过程中，完全二叉树从最下层最右边的非终端结点开始构建，将它与其孩子进行比较和必要的互换，对于每个非终端结点来说，其实最多进行两次比较和一次互换操作，因此整个构建堆的时间复杂度为: O(n)。大概需进行n/2 * 2 = n次比较和n/2次交换。 
- 在正式排序时，n个结点的完全二叉树的深度为⌊log2n⌋+1，并且有n个数据则需要取n-1次调整成大顶堆的操作，每次调整成大顶堆的时间复杂度为O(log2n)。因此，重建堆的时间复杂度可近似看做: O(nlogn)。

### 1.6 [归并排序](https://github.com/guoguokkk/Interview/blob/master/Sort/MergeSort.cpp)
归并排序：把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行
#### 1.6.1 递归
![](https://github.com/guoguokkk/Interview/blob/master/img/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F_%E9%80%92%E5%BD%92.png)

#### 1.6.2 迭代
![](https://github.com/guoguokkk/Interview/blob/master/img/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F_%E8%BF%AD%E4%BB%A3.png)

### 1.7 [希尔排序](https://github.com/guoguokkk/Interview/blob/master/Sort/shell_sort.cpp)
希尔排序：每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小，最后一次一定要是1
![](https://github.com/guoguokkk/Interview/blob/master/img/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F.png)

### 1.8 [计数排序](https://github.com/guoguokkk/Interview/blob/master/Sort/CountSort.cpp)

计数排序：统计小于等于该元素值的元素的个数i，于是该元素就放在目标数组的索引i位（i≥0）

计数排序基于一个假设，待排序数列的所有数均为整数，且出现在（0，k）的区间之内。
- 如果 k（待排数组的最大值） 过大则会引起较大的空间复杂度，一般是用来排序 0 到 100 之间的数字的最好的算法，但是它不适合按字母顺序排序人名。
- 计数排序不是比较排序，排序的速度快于任何比较排序算法。
- 时间复杂度为 O（n+k），空间复杂度为 O（n+k）

算法的步骤如下：
1. 找出待排序的数组中最大和最小的元素
2. 统计数组中每个值为 i 的元素出现的次数，存入数组 C 的第 i 项
3. 对所有的计数累加（从 C 中的第一个元素开始，每一项和前一项相加）
4. 反向填充目标数组：将每个元素 i 放在新数组的第 C[i] 项，每放一个元素就将 C[i] 减去 1

### 1.9 [桶排序](https://github.com/guoguokkk/Interview/blob/master/Sort/BucketSort.cpp)
桶排序：将值为i的元素放入i号桶，最后依次把桶里的元素倒出来

桶排序序思路：
1. 设置一个定量的数组当作空桶子。
2. 寻访序列，并且把项目一个一个放到对应的桶子去。
3. 对每个不是空的桶子进行排序。
4. 从不是空的桶子里把项目再放回原来的序列中。
假设数据分布在[0，100)之间，每个桶内部用链表表示，在数据入桶的同时插入排序，然后把各个桶中的数据合并。

### 1.10 基数排序
基数排序：一种多关键字的排序算法，可用桶排序实现

### [返回目录](#Contents)

# Design pattern
