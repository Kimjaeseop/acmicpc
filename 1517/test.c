#include <stdio.h>

int N;
int cnt;
int arr[500001];

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				cnt++;
			}
		}
	}

	for (int i = 0; i < N; i++) 
		printf("%d ", arr[i]);
	printf("\n");
	printf("%d\n", cnt);
	
	return 0;
}
