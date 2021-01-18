#define MAX 100

#include <stdio.h>

int N;
int Arr[MAX];

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// 오름차순 정렬

int main(void)
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", Arr[j]);
		}
		printf("\n");
		for (int j = 0; j < N - i - 1; j++) {
			if (Arr[j] > Arr[j+1]) {
				swap(&Arr[j], &Arr[j+1]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", Arr[i]);
	}

	printf("\n");

	return 0;
}
