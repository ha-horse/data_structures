//冒泡排序 从小到大排序
void BubbleSort(int *arrs, int length)
{
	//外层循环控制排序轮数，最后一个元素肯定是最大的，不用操作，所以是length-1
	for (int i = 0; i < length - 1; i++)
	{
		//最后i个元素已经有序不需要继续排序
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arrs[j] > arrs[j + 1])
			{
				int temp = arrs[j];
				arrs[j] = arrs[j + 1];
				arrs[j + 1] = temp;
			}
		}
	}
}