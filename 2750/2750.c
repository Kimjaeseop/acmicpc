#include <stdio.h>
#include <stdlib.h>

int N;
int arr[1001];

int comp (const void *a, const void *b)
{
	return *(int *)a - *(int *)b; // a가 더 크면 양수 반환 // a가 아래로 감
}

int main(void) 
{
	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(arr[0]), comp);

	for (int i=0; i<N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}
