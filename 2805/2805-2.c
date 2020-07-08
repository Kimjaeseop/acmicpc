#include <stdio.h>

// cpp 코드랑 시간 차이 별로 없음 그냥 cpp 쓰자

int N, M, ANS;
int arr[1000000];
int max, l, r, mid;
long long sum;

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		if (max < arr[i]) {
			max = arr[i];
		}
	}

	l = 0;
	r = max;

	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;

		for (int i = 0; i < N; i++) {
			sum += (arr[i] - mid) > 0 ? arr[i] - mid : 0;
		}

		if (sum == M) {
			ANS = mid;
			break;
		}
		if (sum > M) {
			l = mid + 1;
			ANS = mid;
		}
		else {
			r = mid - 1;
		}
	}

	printf("%d\n", ANS);

	return 0;
}

