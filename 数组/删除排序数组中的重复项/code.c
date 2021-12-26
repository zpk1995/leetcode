#include <stdio.h>
int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    int length = 0;
    if(nums == NULL && numsSize < 0)
        return -1;
    if(numsSize == 0)
        return 0;
    for(int j = 1; j < numsSize; j++)
    {
        if(nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    length = i + 1;
    return length;
}

int sum(int *array,int num)
{
	if(NULL == array)
		return 0;
	if (1 == num)
		return array[0];
	else
		return array[0] + sum(array + 1, num - 1);
}

int partion(int *array,int start,int end)
{
	int pivot = array[start];
	int swap = 0;
	while(1)
	{
		/*当左边数据小于pivot值，往右移*/
		while((array[start] < pivot) && (start < end))
		{
			start++;
		}
		/*当右边数据大于pivot值，往左移*/
		while((array[end] > pivot) && (start < end))
		{
			end--;
		}
		/*当遍历结束，跳出循环*/
		if(start >= end)
			break;
		else
		{
			/*找到本该在右边的数据和本该左边的数据进行互换然后进行下一次循环*/
			swap = array[start];		
			array[start] = array[end];
			array[end] = swap;
		}
		/*当左右数据相等时，从start下一个开始遍历*/
		if(array[start] == array[end])
			start++;
	}
	return start;
}

void qsort(int *array,int start,int end)
{
	if(start < end)
	{
		int k = partion(array,start,end);
		qsort(array,start,k - 1);
		qsort(array,k + 1, end);
	}
}

int binary_sort(int *array,int low,int high,int item)
{
	int mid = 0;
	if(low > high)
		return -1;
	mid = (low + high) / 2;
	if(array[mid] == item)
		return mid;
	else if(array[mid] < item)
		return binary_sort(array,mid + 1, high, item);
	else	
		return binary_sort(array, low, mid - 1,item);	
}
int main()
{
	int array[] = { 1,4,7,2,5,8,10};
	int my_list[] = {1,3,5,7,9};
	int q_list[] = { 1,4,7,2,5,8,10};
	int index = -1;
	printf("the all of array is %d\n", sum(array, sizeof(array) / sizeof(array[0])));
	index = binary_sort(my_list,0, sizeof(my_list) / sizeof(my_list[0]) - 1,3);
	if(index != -1)
		printf("the index of item in my_list is %d\n", index);
		
	index = -1;
	index = binary_sort(my_list,0, sizeof(my_list) / sizeof(my_list[0]) - 1,5);
	if(index != -1)
		printf("the index of item in my_list is %d\n", index);
	else
		printf("can not find item\n");
	qsort(q_list, 0, sizeof(q_list) / sizeof(q_list[0]) - 1);
	for(int i = 0; i < sizeof(q_list) / sizeof(q_list[0]); i++)
		printf("%d ", q_list[i]);
	return 0;
}