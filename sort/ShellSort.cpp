//希尔排序，是插入排序的一种更高效的改进版本。
//但是希尔排序是不稳定的，它是将已排序的数列插入到另一个已排序的数列中。
void ShellSort(int *arrs, int length)
{
	int temp, j;
	int gap = length >> 1;
	while (gap != 0)
	{
		cout << "gap=" << gap << endl;
		for (int i = gap; i < length; i++)
		{
			temp = arrs[i];//保存待排序的第一个数，即待插入的数
			for (j =  i - gap; j >= 0 && temp < arrs[j]; j -= gap)
			{
				arrs[j + gap] = arrs[j];
			}
			arrs[j + gap] = temp;
		}
		gap = gap >> 1;
	}
}