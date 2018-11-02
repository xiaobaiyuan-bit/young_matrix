//1.调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。
#include <stdio.h>
#include <windows.h>
#include <assert.h>

void put_Odd_Even(int arr[], int sz)
{
	assert(arr);
	int *pleft = arr;
	int *pright = arr + sz - 1;
	while (pleft < pright)
	{
		while (*pleft % 2 != 0)
		{
			pleft++;
		}
		while (*pright % 2 == 0)
		{
			pright--;
		}
		if (pleft < pright)//不要忘记了这个判断条件
		{
			*pleft ^= *pright;
			*pright ^= *pleft;
			*pleft ^= *pright;
		}
			pleft++;
			pright--;
	}
}

int main()
{
	int i = 0;
	int arr[] = { 1, 5, 2, 3, 8, 6, 9, 4, 7, 1, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	put_Odd_Even(arr, size);
	for (; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}



//2.
//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//数组：
//1 2 3
//3 4 5
//4 5 6

//该题以arr[0][2]为基准
//外层循环是arr[0][2] arr[1][2] arr[2][2]
//内层只需要判断每一行的大小即可
//时间复杂度小于O(N)

#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int search(int arr[][3], int num)
{
	int i = 0;
	for (; i < 3; i++)
	{
		int j = 2;
		while (j >= 0)
		{
			if (num == arr[i][j])
			{
				return 1;
			}
			else if (num < arr[i][j])
			{
				j--;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j;
	int arr[][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	int num = 0;
	scanf("%d", &num);
	int ret = search(arr, num);
	if (ret == 1)
	{
		printf("该数存在\n");
	}
	else
	{
		printf("该数不存在\n");
	}
	system("pause");
	return 0;
}