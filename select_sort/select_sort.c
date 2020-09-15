#include <stdio.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
int array[] = {65, 78, 1, 99, 100, 0, -1, 1, 2, 0, -1, 100};
void select_sort(int *array, int size)
{
	int min_index = 0, temp;
	for (int i = 1; i < size; i++) {
		min_index = i - 1;
		for (int j = i; j < size; j++) {
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i - 1) {
			temp = array[min_index];
			array[min_index] = array[i - 1];
			array[i - 1] = temp;
		}
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
	select_sort(array, ARRAY_SIZE(array));
	dump_array(array, ARRAY_SIZE(array));
	
	return 0;
}
