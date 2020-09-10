#include <stdio.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
int array[] = {65, 78, 1, 99, 100, 0, -1, 1, 2, 0, -1, 100};
int partition(int array[], int low, int high)
{
	//填坑法比较好理解。
	int tmp;
	tmp = array[low];
	//第一个数字选做基数，它所在的位置就变成了一个坑。
	while (low < high) {
		while (low < high && array[high] > tmp)
			high--;	//大于基数的不动。
		array[low] = array[high];  //小于基数的填到事先挖好的坑里边。
		
		while (low < high && array[low] <= tmp)
			low++;
		array[high] = array[low];
	}
	array[low] = tmp;
	return low;
}
int fast_sort(int array[], int low, int high)
{
	int tmp;
	if (low < high) {
		tmp = partition(array, low, high);
		fast_sort(array, low, tmp - 1);
		fast_sort(array, tmp + 1, high);
	}	
}
void dump_array(int array[], int size)
{
	for (int i = 0; i < size; i++)
		printf("a[%d] = %d ", i, array[i]);
	putchar(10);
}
int main(int argc, const char *argv[])
{
	dump_array(array, ARRAY_SIZE(array));
	fast_sort(array, 0, ARRAY_SIZE(array) - 1);
	dump_array(array, ARRAY_SIZE(array));
	return 0;
}
