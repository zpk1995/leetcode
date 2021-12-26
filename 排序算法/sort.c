#include <stdio.h>

int binary_search(int *array,int low,int high,int item)
{
	int mid = 0;
	if(low > high)
		return -1;
	mid = (low + high) / 2;
	if(array[mid] == item)
		return mid;
	else if(array[mid] < item)
		return binary_search(array,mid + 1, high, item);
	else	
		return binary_search(array, low, mid - 1,item);	
}

void print_binary_search(int *array,int low,int high,int item)
{
	int index = -1;
	index = binary_search(array,low, high,item);
	if(index != -1)
		printf("the index of item in my_list is %d\n", index);
	else
		printf("can not find item\n");
}

/*
两数交换
*/
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/*
用来查找分割点
*/
int partion(int *array,int start,int end)
{
	int pivot = array[start];
	while(1)
	{
		/*当数小于pivot值向右移动*/
		while((array[start] < pivot) && (start < end))
		{
			start++;
		}
		/*当数大于pivot值向左移动*/
		while((array[end] > pivot) && (start < end))
		{
			end--;
		}
		/*如果前后数据都完成分割，代表当前根据pivot排序好了*/
		if(start >= end)
			break;
		else
		{
			/*代表两个数据要进行交换*/
			swap(array + start, array + end);
		}
		/*array[start] == array[end]代表两头数据进行交换*/
		if(array[start] == array[end])
			start++;
	}
	return start;
}

/*
快速排序
*/
void qsort(int *array,int start,int end)
{
	if(start < end)
	{
		int k = partion(array,start,end);
		qsort(array,start,k - 1);
		qsort(array,k + 1, end);
	}
}

/*
打印快速排序前后的数据
*/
void print_qsort(int *array,int start,int end)
{
	if(NULL == array && (start < 0) && (end < 0) && (start > end))
	{
		printf("input array error\n");
		return;
	}
	printf("排序前数据为：");
	for(int i = 0; i <= end; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("快速排序后数据：");
	qsort(array, start, end);
	for(int i = 0; i <= end; i++)
		printf("%d ", array[i]);
	printf("\n");
}

/*
插入排序
*/
void insert_sort(int *array, int length)
{
	int preindex = -1;
	int currentnum = -1;
	for(int i = 1; i < length; i++)
	{
		preindex = i - 1;
		currentnum = array[i];
		while((preindex >= 0) && (currentnum < array[preindex]))
		{
			array[preindex + 1] = array[preindex];
			preindex--;
		}
		array[preindex + 1] = currentnum;
	}
}

/*
打印插入排序前后的数据
*/
void print_insert_sort(int *array, int length)
{
	if(NULL == array && length < 0)
	{
		printf("input array error\n");
		return;
	}
	printf("排序前数据为：");
	for(int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("插入排序后数据：");
	insert_sort(array, length);
	for(int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

/*
冒泡排序
*/
void bubble_sort(int *array, int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - 1 - i; j++)
			if(array[j] > array[j++])
			{
				swap(array + j,array + j + 1);
			}
	}
}

/*
打印插入排序前后的数据
*/
void print_bubble_sort(int *array, int length)
{
	if(NULL == array && length < 0)
	{
		printf("input array error\n");
		return;
	}
	printf("排序前数据为：");
	for(int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("冒泡排序后数据：");
	insert_sort(array, length);
	for(int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

/*
选择排序
*/
void select_sort(int *array, int length)
{
	int minindex = 0;
	for(int i = 0; i < length - 1; i++)
	{
		minindex = i;
		for(int j = i + 1; j < length ; j++)
			if(array[j] > array[minindex])
			{
				minindex = j;
			}
		if(minindex != i)
			swap(array + i,array + minindex);
	}
}

/*
打印选择排序前后的数据
*/
void print_select_sort(int *array, int length)
{
	if(NULL == array && length < 0)
	{
		printf("input array error\n");
		return;
	}
	printf("排序前数据为：");
	for(int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("选择排序后数据：");
	insert_sort(array, length);
	for(int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	int binary_list[] = {1,3,5,7,9};
	int q_list[] = { 1,4,7,2,5,8,10};
	int insert_list[] = { 1,4,7,2,5,8,10};
	int bubble_list[] = { 1,4,7,2,5,8,10};
	int select_list[] = { 1,4,7,2,5,8,10};
	
	print_binary_search(binary_list,0, sizeof(binary_list) / sizeof(binary_list[0]) - 1,3);
	print_binary_search(binary_list,0, sizeof(binary_list) / sizeof(binary_list[0]) - 1,5);
	print_qsort(q_list, 0, sizeof(q_list) / sizeof(q_list[0]) - 1);
	print_insert_sort(insert_list,sizeof(insert_list) / sizeof(insert_list[0]));
	print_bubble_sort(bubble_list,sizeof(bubble_list) / sizeof(bubble_list[0]));
	print_select_sort(select_list,sizeof(select_list) / sizeof(select_list[0]));
	return 0;
}