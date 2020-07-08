#include <stdio.h>

int arr[10001];
int K, N;
long long SUM;
long long L, R, M;
long long MAX;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%d", &arr[i]);

		if (MAX < arr[i])
			MAX = arr[i];
	}

	L = 1;
	R = MAX;

	MAX = 0;

	// ÀÌºÐ Å½»ö

	while (L <= R) {
		M = (L + R) / 2;

		for (int i = 0; i < K; i++) {
			SUM += (arr[i] / M);
		}

		if (SUM < N) {
			R = M - 1;
		}
		else if (SUM >= N) {
			L = M + 1;

			if (MAX < M) {
				MAX = M;
			}
		}

		SUM = 0;
	}

	printf("%lld\n", MAX);

	return 0;
}
