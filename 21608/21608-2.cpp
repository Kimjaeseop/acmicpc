#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<short>> arr(441, vector<short>(4, 0));
vector<short> lst(441);
short room[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N;
int n1, n2;

int countEmptyroom(int y, int x) {
	int num = 0;

	for (int i = 0; i < 4; i++) {
		if (y+dy[i] < 0 || y+dy[i] >= N || x+dx[i] < 0 || x+dx[i] >= N)
			continue;

		if (!room[y+dy[i]][x+dx[i]])
			num++;
	}

	return num;
}

bool checkPositivePer(int idx, int num) {
	for (int i = 0; i < 4; i++) 
		if (arr[idx][i] == num)
			return true;

	return false;
}

int countPositivePer(int idx, int y, int x) {
	int num = 0;

	for (int i = 0; i < 4; i++) {
		if (y+dy[i] < 0 || y+dy[i] >= N || x+dx[i] < 0 || x+dx[i] >= N)
			continue;

		num += checkPositivePer(idx, room[y+dy[i]][x+dx[i]]);
	}

	return num;
}

void makeRoom() {
	int savey, savex, per, tmp;
	savey = savex = per = tmp = 0;

	for (int i = 0; i < N*N; i++) {
		for (int y = 0; y < N; y++) { 
			for (int x = 0; x < N; x++) {
				if (room[y][x] != 0)
					continue;

				tmp = countPositivePer(lst[i], y, x);

				if (tmp > per) {
					per = tmp; savey = y; savex = x;
				}
				if (tmp == per) {
					if (savey == -1 && savex == -1) {
						per = tmp; savey = y; savex = x;
					}
					int n1 = countEmptyroom(y, x);
					int n2 = countEmptyroom(savey, savex);

					if (n1 > n2) {
						per = tmp; savey = y; savex = x;
					}
					if (n1 == n2) {
						if(y == savey) {
							if (x < savex) {
								per = tmp; savey = y; savex = x;
							}
						}
						else {
							if (y < savey) {
								per = tmp; savey = y; savex = x;
							}
						}
					}
				}
			}
		}
		room[savey][savex] = lst[i];
		savey = savex = -1;
		per = 0;
	}
}

int getPositivescore() {
	int score = 0;
	int cnt = 0;
	makeRoom();

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cnt = countPositivePer(room[y][x], y, x);

			if (cnt == 1)
				score += 1;
			else if (cnt == 2)
				score += 10;
			else if (cnt == 3)
				score += 100;
			else if (cnt == 4)
				score += 1000;
		}
	}

	return score;
}

int main(void)
{
	//freopen("input_2.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N*N; i++) {
		scanf("%d", &n1);
		lst[i] = n1;

		for (int j = 0; j < 4; j++)
			scanf("%hd", &arr[n1][j]);
	}

	printf("%d\n", getPositivescore());
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%hd ", room[i][j]);
		}
		printf("\n");
	}
	*/

	return 0;
}
