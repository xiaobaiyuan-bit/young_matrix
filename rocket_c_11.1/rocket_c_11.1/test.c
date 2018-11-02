//1.��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
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
		if (pleft < pright)//��Ҫ����������ж�����
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
//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//���飺
//1 2 3
//3 4 5
//4 5 6

//������arr[0][2]Ϊ��׼
//���ѭ����arr[0][2] arr[1][2] arr[2][2]
//�ڲ�ֻ��Ҫ�ж�ÿһ�еĴ�С����
//ʱ�临�Ӷ�С��O(N)

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
		printf("��������\n");
	}
	else
	{
		printf("����������\n");
	}
	system("pause");
	return 0;
}