#include <cstdio>
#include <queue>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, char> pic;

pii dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int visit[102][102];

pii getNextNode(pii queueBack, int curDir)
{
	return {queueBack.first + dir[curDir].first, queueBack.second + dir[curDir].second};
}

int main(void)
{
	queue<pii> Q;
	queue<pic> dirQ;
	int N, K, L, Y, X;
	char C;
	int curDir = 0, turn = 0;
	pii queueFront, queueBack, nextNode;
	pic dirQueueFront;

	freopen("input_3.txt", "r", stdin);

	scanf("%d", &N);
	scanf("%d", &K);

	// visit, 0 == empty, 1 == snake, 2 == apple
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &Y, &X);
		visit[Y][X] = 2;
	}

	scanf("%d", &L);

	for (int i = 0; i < L; i++) {
		scanf("%d %c", &Y, &C);
		dirQ.push({Y, C});
	}

	Q.push({1, 1});
	visit[1][1] = 1;

	while (1) {
		/*
		printf("(turn) %d, (curDir) %d\n", turn, curDir);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				printf("%d ", visit[i][j]);
			}
			printf("\n");
		}
		*/

		dirQueueFront = dirQ.front();

		if (dirQueueFront.first == turn) {
			if (dirQueueFront.second == 'L') {
				curDir -= 1;

				if (curDir == -1) {
					curDir = 3;
				}
			}
			else {
				curDir = (curDir + 1) % 4;
			}

			dirQ.pop();
		}

		queueBack = Q.back();

		nextNode = getNextNode(queueBack, curDir);

		// exit check
		if (nextNode.first < 1 || nextNode.second < 1 || nextNode.first > N || nextNode.second > N || visit[nextNode.first][nextNode.second] == 1) {
			break;
		}

		// if nextNode == apple -> no pop, else pop
		if (visit[nextNode.first][nextNode.second] != 2) {
			queueFront = Q.front();
			visit[queueFront.first][queueFront.second] = 0;
			Q.pop();
		}

		visit[nextNode.first][nextNode.second] = 1;
		Q.push(nextNode);

		turn++;
	}

	printf("%d\n", turn+1);

	return 0;
}

