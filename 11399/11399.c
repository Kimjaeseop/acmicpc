#include <stdio.h>
#include <stdlib.h>

long long sum;
long long tmp;
int N;
int arr[1001];

int comp(const void *a, const void *b) 
{
	return (*(int *)a > *(int *)b);
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), comp);

	for (int i = 0; i < N; i++) {
		tmp += arr[i];
		sum += tmp;
	}

	printf("%lld\n", sum);

	return 0;
}

