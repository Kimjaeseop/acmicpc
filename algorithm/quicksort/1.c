#include <stdio.h>

void swap(int arr[])
{
	int temp = arr[1];
	arr[1] = arr[0];
	arr[0] = temp;
}

int main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};

	swap(arr);

	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}
