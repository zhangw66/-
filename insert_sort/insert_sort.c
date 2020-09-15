#include <stdio.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
int array[] = {65, 78, 1, 99, 100, 0, -1, 1, 2, 0, -1, 100};
int array1[] = {65, 78, 99, 100, 105};
int array3[] = {6, 6, 6, 6, 6};
int array2[] = {165, 78, 1, 99, -100, 0, -1, 1, 2, 0, -1, 0};
void insert_sort(int *array, int size)
{
	int temp, i, j;
	//i指的是有序表的个数。最终有序表肯定是要等于数组的个数。
	for (i = 1; i < size; i++) {
		//存储要插入的数字。
		temp = array[i];
		//找到在有序表中要插入的位置。
		for (j = 0; j < i; j++) {
			if (temp < array[j]) {
				break;	//记录要直接插入在有序表中的位置。
			}
		}
		//将其他元素全部后移。	
		while (i - j) {
			array[i] = array[i - 1]; //依次后移
			i--;
		}
		//插入刚才存的数字。
		array[j] = temp;
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
	insert_sort(array, ARRAY_SIZE(array));
	dump_array(array, ARRAY_SIZE(array));
	
	dump_array(array1, ARRAY_SIZE(array1));
	insert_sort(array1, ARRAY_SIZE(array1));
	dump_array(array1, ARRAY_SIZE(array1));
	
	dump_array(array2, ARRAY_SIZE(array2));
	insert_sort(array2, ARRAY_SIZE(array2));
	dump_array(array2, ARRAY_SIZE(array2));
	
	dump_array(array3, ARRAY_SIZE(array3));
	insert_sort(array3, ARRAY_SIZE(array3));
	dump_array(array3, ARRAY_SIZE(array3));
	return 0;
}
