#include <stdio.h>

int arr[301][301];

int N, M;
int i, j, x, y;
int K;
int sum;

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int p = 0; p < N; p++) {
		for (int q = 0; q < M; q++) {
			scanf("%d", &arr[p][q]);
		}
	}

	scanf("%d", &K);

	while(K--) {
		scanf("%d %d %d %d", &i, &j, &x, &y);

		for (int p= i - 1; p <= x - 1; p++) {
			for (int q = j - 1; q <= y - 1; q++) {
				sum += arr[p][q];
			}
		}

		printf("%d\n", sum);
		sum = 0;
	}

	return 0;
}
