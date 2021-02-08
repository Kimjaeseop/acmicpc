#include <stdio.h>

using namespace std;

int N;
char arr[102][102];
bool check1[102][102], check2[102][102];
int dir[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int ANS1, ANS2;

void DFS_1(int y, int x, char c, bool check[102][102]);
void DFS_2(int y, int x, char c, bool check[102][102]);

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	scanf("%d\n", &N);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%c", &arr[i][j]);
		}
		getc(stdin);
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (check1[i][j] == 0) {
				DFS_1(i, j, arr[i][j], check1);
				ANS1++;
			}

			if (check2[i][j] == 0) {
				DFS_2(i, j, arr[i][j], check2);
				ANS2++;
			}
		}
	}

	printf("%d %d\n", ANS1, ANS2);

	return 0;
}

void DFS_1(int y, int x, char c, bool check[102][102]) {
	check[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dir[i][0];
		int next_x = x + dir[i][1];

		if (check[next_y][next_x] == 0 && arr[next_y][next_x] == c)
			DFS_1(next_y, next_x, c, check);
	}
}

void DFS_2(int y, int x, char c, bool check[102][102]) {
	check[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dir[i][0];
		int next_x = x + dir[i][1];

		if (check[next_y][next_x] == 0 && ((arr[next_y][next_x] == c) ||
				(c == 'R' && arr[next_y][next_x] == 'G') ||
				(c == 'G' && arr[next_y][next_x] == 'R')))
			DFS_2(next_y, next_x, c, check);
	}
}

