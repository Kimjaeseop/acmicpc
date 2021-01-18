#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[2000001];

int comp(const void *a, const void *b)
{
	return *(int *)a > *(int *)b;
}

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N + M; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N+M, sizeof(int), comp);

	for (int i = 0; i < N + M; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
