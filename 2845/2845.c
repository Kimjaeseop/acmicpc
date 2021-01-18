#include <stdio.h>

int L, P, N;
int arr[10];

int main(void)
{
	scanf("%d %d", &L, &P);
	N = L * P;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);

		printf("%d ", arr[i] - N);
	}

	return 0;
}
