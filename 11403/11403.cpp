#include <stdio.h>
// 1 -> 2, 2 -> 3, 3 -> 1
// 1 -> 3 -> 1

// 플로이드 워셜
// N^3 이라서 시간초과 나올 줄 알았는데 안나온다,,

int N;
int arr[102][102];

int main(void)
{
	//freopen("input_2.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
