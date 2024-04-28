//快速排序
void QuickSort(int *arrs, int left, int right)
{
	int i, j;
	//排除left=right时，只有一个元素的情况
	if (left < right)
	{
		i = left;
		j = right;
		while (i < j)
		{
			//开始寻找比key小的数
			while (i < j && arrs[j] >= arrs[i])//从右往左找第一个小于arrs[left]的数
				j--;
			//开始寻找比key大的数
			while (i < j && arrs[i] < arrs[i])//从左向右找第一个大于等于arrs[left]的数
				i++;
			//如果找到，则将arrs[i]与arrs[j]互换位置
			if (i < j)
			{
				int temp = arrs[j];
				arrs[j] = arrs[i];
				arrs[i] = temp;
			}
		}

		QuickSort(arrs, left, i - 1);//排左边
		QuickSort(arrs, i + 1, right);//排右边
	}
}