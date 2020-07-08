#include <stdio.h>
#include <unistd.h>

int N, M, B;
int tmp;
long long sum;
int ANS;
int MIN=2100000000;
int min_sum, min_mid;

int arr[1000][1000];

int main(void)
{
	//freopen("input1.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);

			if (arr[i][j] > r) {
				r = arr[i][j];
			}
			if (arr[i][j] < l) {
				l = arr[i][j];
			}
		}
	}

	tmp = B;
	for (int h = 
		for (int i = 0; i < N && 0 <= B; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j]-mid > 0) {
					B += arr[i][j]-mid;
					sum += (arr[i][j]-mid)*2;
				}
				else if (arr[i][j]-mid < 0) {
					B -= mid - arr[i][j];
					sum += (mid-arr[i][j]);

					if (B < 0) {
						r = mid - 1;
						break;
					}
				}
			}
		}

		if (MIN==2100000000) {
			min_sum = sum;
			min_mid = mid;
			MIN = sum;
		}

		if (B < 0) {
			continue;
		}

		if (sum >= 0) {
			l = mid + 1;

			if (MIN > sum) {
				min_sum = sum;
				min_mid = mid;
				MIN = sum;
			}
		}
		else {
			MIN = sum;
			r = mid - 1;
		}
	}

	printf("%d %d\n", min_sum, min_mid);

	return 0;
}
