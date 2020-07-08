#include <iostream>
#include <utility>
#include <queue>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// 그리디
int dir[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}; // 4방향 알고리즘을 위한 방향 배열
int arr[102][102]; // input array
int land_chk[102][102]; // 섬의 군집화를 위해 필요한 배열

int ans, cnt;
int N;

queue <pair<int, int>> Q; // BFS를 위한 Queue

void DIV(int A, int B) // BFS로 구현한 군집화 알고리즘
{
	if (arr[A][B] == 1) {
		land_chk[A][B] = cnt;
	}

	for (int i = 0; i < 4; i++) {
		int Y = A + dir[i][0];
		int X = B + dir[i][1];

		if (Y < 1 || X < 1 || Y > N || X > N) {
			continue;
		}

		if (arr[Y][X] == 1 && land_chk[Y][X] == 0) {
			DIV(A + dir[i][0], B + dir[i][1]);
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	ans = 200; // 정답은 Minimum값이기 때문에 100 * 100에서 나올 수 있는 대충 최대값
	cnt = 1; // 섬의 개수를 counting할 변수

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (land_chk[i][j] == 0 && arr[i][j] == 1) {
				DIV(i, j);
				cnt++; // 섬의 numbering과 개수를 count하기 위함
			}
		}
	}

	cnt -= 1; 

	for (int i = 1; i <= cnt; i++) {
		int sea_chk[102][102] = {0, }; // 방문한 섬과 바다를 check

		while (!Q.empty()) {
			Q.pop(); // Queue init
		}

		for (int p = 1; p <= N; p++) {
			for (int q = 1; q <= N; q++) {
				if (land_chk[p][q] == i) {
					Q.push({p, q}); // BFS 준비 // 섬 별로 Queue에 넣어 처리
				}
			}
		}

		int escape = 0, depth = 0;
		// BFS의 depth 확인용 변수와 while을 빠져나오기 위한 escape 변수

		while (!escape) { // 중간에 섬이 닿는 곳을 찾았을 때를 생각한 escape 조건
			int S = Q.size(); // BFS를 depth별로 처리하기 위한 변수
			depth++;

			if (depth > ans) { // Greedy 중간에 이미 최소값을 넘어버리면 중단시킴
				break;
			}

			while (S-- && !escape) { // tree의 이번 depth의 node만큼 수행 및 escape 조건
				int A = Q.front().first;
				int B = Q.front().second;

				Q.pop();

				for (int j = 0; j < 4; j++) {
					int Y = A + dir[j][0];
					int X = B + dir[j][1];

					if (Y < 1 || X < 1 || Y > N || X > N) { // 방향을 벗어난 경우
						continue;
					}

					if (sea_chk[Y][X] == 1) { // 이미 방문한 경우
						continue;
					}

					if (i != land_chk[Y][X] && arr[Y][X] == 1) { // 섬을 찾은경우
						escape = 1;
						break;
					}

					if (sea_chk[Y][X] == 0) { // BFS에 추가할 바다 및 현재 섬
						sea_chk[Y][X] = 1;
						Q.push({Y, X});
					}
				}
			}
		}
		if ((depth - 1) < ans) { // Minimum check
			ans = (depth - 1);
		}
	}

	printf("%d\n", ans);

	return 0;
}

