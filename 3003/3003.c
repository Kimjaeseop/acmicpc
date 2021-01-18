#include <stdio.h>

int arr_1[6] = {1, 1, 2, 2, 2, 8};
int arr_2[6];

int main(void)
{
	for (int i = 0; i < 6; i++) {
		scanf("%d", &arr_2[i]);

		printf("%d ", arr_1[i] - arr_2[i]);
	}

	return 0;
}
