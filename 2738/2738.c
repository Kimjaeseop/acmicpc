#include <stdio.h>

int N, M;
int in;
int arr[101][101];

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < 2; i++) {
		for (int p = 0; p < N; p++) {
			for (int q = 0; q < M; q++) {
				scanf("%d", &in);
				arr[p][q] += in;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
