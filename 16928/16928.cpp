#include <cstdio>
#include <queue>

using namespace std;

int main(void)
{
	int a, b;
	int N, M;
	int queueSize, curLoc, nextLoc, step;
	int arr[101] = { 0, };
	bool visit[101] = { false, };
	queue<int> Q;

	queueSize = curLoc = nextLoc = step = 0;

	freopen("input_1.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N + M; i++) {
		scanf("%d %d", &a, &b);

		arr[a] = b;
	}

	Q.push(1);
	visit[1] = true;

	while (!Q.empty()) {
		queueSize = Q.size();

		step++;
		while (queueSize--) {
			curLoc = Q.front();
			Q.pop();

			for (int i = 1; i <= 6; i++) {
				nextLoc = curLoc + i;

				if (nextLoc >= 100) {
					printf("%d\n", step);
					return 0;
				}

				if (arr[nextLoc] != 0) {
					nextLoc = arr[nextLoc];
				}

				if (!visit[nextLoc]) {
					visit[nextLoc] = true;
					Q.push(nextLoc);
				}
			}
		}
	}

	return 0;
}
