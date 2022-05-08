#include <cstdio>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int countEmpty, countVirus, ANS;
int arr[10][10], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

queue<pair<int, int>> virus_queue;
vector<pair<int, int>> empty_space;

void solve()
{
	pair<int, int> coord[3], virus_coord;
	int visit[10][10] = {{0,}};
	int countResult = 0;

	for (int i = 0; i < countEmpty; i++) {
		coord[0] = empty_space[i];
		arr[coord[0].first][coord[0].second] = 1;

		for (int j = i + 1; j < countEmpty; j++) {
			coord[1] = empty_space[j];
			arr[coord[1].first][coord[1].second] = 1;


			for (int p = j + 1; p < countEmpty; p++) {
				coord[2] = empty_space[p];
				arr[coord[2].first][coord[2].second] = 1;

				// Initailize
				queue<pair<int, int>> bfsQueue = virus_queue;
				countResult = countEmpty;
				for (int a = 0; a < 10; a++) {
					for (int b = 0; b < 10; b++) {
						visit[a][b] = 0;
					}
				}

				while (!bfsQueue.empty()) {
					pair<int, int> queueFront = bfsQueue.front();
					bfsQueue.pop();

					for (int i = 0; i < 4; i++) {
						virus_coord.first = queueFront.first + dir[i][0];
						virus_coord.second = queueFront.second + dir[i][1];

						if (virus_coord.first < 1 || virus_coord.second < 1 || 
								virus_coord.first > N || virus_coord.second > M) {
							continue;
						}

						if (!visit[virus_coord.first][virus_coord.second] &&
								arr[virus_coord.first][virus_coord.second] == 0) {
							visit[virus_coord.first][virus_coord.second] = 2;
							countResult--;
							bfsQueue.push(virus_coord);
						}
					}
				}

				/*
				for (int a = 1; a <= N; a++) {
					for (int b = 1; b <= M; b++) {
						if (arr[a][b] != 0) {
							printf("%d ", arr[a][b]);
						}
						else {
							printf("%d ", visit[a][b]);
						}
					}
					printf("\n");
				}
				*/

				//printf("%d\n", countResult-3);

				arr[coord[2].first][coord[2].second] = 0;

				if (countResult-3 > ANS) {
					ANS = countResult-3;
				}
			}
			arr[coord[1].first][coord[1].second] = 0;
		}
		arr[coord[0].first][coord[0].second] = 0;
	}
}

int main(void)
{
	//freopen("input_3.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);

			if (arr[i][j] == 0) {
				countEmpty++;
				empty_space.push_back({i, j});
			}
			else if (arr[i][j] == 2) {
				countVirus++;
				virus_queue.push({i, j});
			}
		}
	}

	/*
	printf("%d\n", countEmpty);

	for (int i = 0; i < countEmpty; i++) {
		printf("[%d] : %d, %d\n", i, empty_space[i].first, empty_space[i].second);
	}
	*/

	solve();

	printf("%d\n", ANS);

	return 0;
}
