#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;

bool arr[101][101];
int ans[101][101];

int MIN, MIN_IDX;

// 기초적인 BFS

int main(void)
{
	int A, B, depth, q_size;

	//freopen("input.txt", "r", stdin);

	cin >> N >> M;

	MIN = MIN_IDX = 1e9;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		arr[A][B] = arr[B][A] = true;
	}

	for (int i = 1; i <= N; i++) {
		bool chk[101] = {false, };
		queue<pair<int, int>> q;

		chk[i] = true;
		q.push({0, i});

		for (int depth = 1; depth <= N; depth++) {
			q_size = q.size();

			while (q_size--) {
				pair<int, int> t = q.front();
				q.pop();

				for (int j = 1; j <= N; j++) {
					if (chk[j] == false && arr[t.second][j] == true) {
						chk[j] = true;

						q.push({t.second, j});
						ans[i][j] = depth;
					}
				}
			}
		}

		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += ans[i][j];
		}

		if (sum < MIN) {
			MIN = sum;
			MIN_IDX = i;
		}
	}

	cout << MIN_IDX << endl;

	return 0;
}

