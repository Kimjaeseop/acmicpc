#include <stdio.h>
#include <stdlib.h>

int N;
int arr[1001];

int comp (const void *a, const void *b)
{
	return *(int *)a - *(int *)b; // a�� �� ũ�� ��� ��ȯ // a�� �Ʒ��� ��
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
