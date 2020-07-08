#include <stdio.h>

int N, M, B;
int arr[501][501];
int SUM, MIN = 2100000000, MAX; 
int min_val = 2100000000, max_h = 0;

// 간단한 brute-force로 풀 수 있다.
// 이진탐색으로 풀려다가 실패
// 간단하지만 문제를 대충읽어서 계속틀림 문제를 잘 읽자

int main(void)
{
	freopen("18111_t/3.in", "r", stdin);
	scanf("%d %d %d", &N, &M, &B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);

			if (arr[i][j] > MAX) {
				MAX = arr[i][j];
			}
			
			if (arr[i][j] < MIN) {
				MIN = arr[i][j];
			}
		}
	}

	for (int h = MIN, tmp = B; h <= MAX; h++, tmp = B, SUM = 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] - h > 0) {
					SUM += (arr[i][j] - h) * 2;
					tmp += (arr[i][j] - h);
				}
				else if (arr[i][j] - h < 0) {
					SUM += (h - arr[i][j]);
					tmp -= (h - arr[i][j]);
				}
			}
		}
		if (SUM <= min_val && h >= max_h && tmp >= 0) {
			min_val = SUM;
			max_h = h;
		}
	}

	printf("%d %d\n", min_val, max_h);

	return 0;
}
