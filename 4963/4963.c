#include <stdio.h>

int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int arr[51][51] = {0, };

int w, h;
int cnt;

void BFS(int A, int B)
{
	arr[A][B] = 0;

	for (int i = 0; i < 8; i++) {
		if (arr[A + dir[i][0]][B + dir[i][1]] == 1) {
			BFS(A + dir[i][0], B + dir[i][1]);
		}
	}
}

int main (void)
{
	freopen("input2.txt", "r", stdin);

	while (1) {
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0) {
			break;
		}

		cnt = 0;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (arr[i][j] == 1) {
					cnt++;
					BFS(i, j);
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
