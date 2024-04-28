//插入排序：将未排序的数字插入到已排序的序列中
void InsertSort(int *arrs, int length)
{
	//外层循环将每个元素依次遍历，第一个元素默认是有序，所以从第二个开始
	//最后一个元素也需要考虑进去所以是length，注意和前面的length-1的区别
	for (int i = 1; i < length; i++)
	{
		//内层循环将当前正遍历的元素插入到已排序中的对应位置
		for (int j = i - 1; j >= 0; j--)
		{
			//从已排好序的最后一个元素开始比较，若没有找到相应位置，进行交换
			if (arrs[i]<arrs[j])
			{
				int temp = arrs[j];
				arrs[j] = arrs[i];
				arrs[i] = temp;
			}
		}
	}
}