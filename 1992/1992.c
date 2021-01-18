#include <stdio.h>

int arr[64][64];
int N;

// 전형적인 분할 정복 문제

void DFS(int X, int Y, int T)
{
	int found = 0;

	if (T == 1) {
		printf("%d", arr[Y][X]);
		return ;
	}

	for (int i = 0; i < T && !found; i++) {
		for (int j = 0; j < T; j++) {
			if (arr[Y + i][X + j] != arr[Y][X]) {
				found = 1;
				break;
			}
		}
	}

	if (!found) {
		printf("%d", arr[Y][X]);
		return ;
	}

	printf("(");

	DFS(X, Y, T/2); DFS(X + T/2, Y, T/2);
	DFS(X, Y + T/2, T/2); DFS(X + T/2, Y + T/2, T/2);

	printf(")");
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	DFS(0, 0, N);
	return 0;
}
