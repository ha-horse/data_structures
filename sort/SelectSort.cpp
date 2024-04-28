//简单选择排序
//首先在未排序序列中找到最小元素，存放到排序序列的起始位置，
//再从剩余未排序元素中寻找最小元素，然后放到已排序序列的末尾，重复操作。
void SelectSort(int *arrs, int length)
{
	//外层循环控制排序轮数，最后一个元素肯定是最大的，不用操作，所以是length-1
	for (int i = 0; i < length - 1; i++)
	{
		int min_index = i;//找到未排序的最小数的索引
		//前i个数已经是有序的，所有从1+i开始遍历
		for (int j = 1 + i; j < length; j++)
		{
			if (arrs[j]<arrs[min_index])
			{
				min_index = j;
			}
			int temp = arrs[i];
			arrs[i] = arrs[min_index];
			arrs[min_index] = temp;
		}
	}
}