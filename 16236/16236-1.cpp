#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N;

typedef struct {
	int y, x;
} location;

typedef struct {
	location loc;
	int size;
} node;

int dir[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int arr[102][102];

int getDistance(location fishLoc, node shark)
{
	int visit[N+2][N+2] = {{0, }, };
	int len, findFish, queueSize;
	queue<location> Q;
	location curLoc, nextLoc;

	Q.push(shark.loc);

	findFish = queueSize = 0;
	len = 0;

	while (!Q.empty() && findFish == 0) {
		queueSize = Q.size();

		len++;
		for (int q = 0; q < queueSize; q++) {
			curLoc = Q.front();
			Q.pop();

			for (int i = 0; i < 4; i++) {
				nextLoc.y = curLoc.y-dir[i][0];
				nextLoc.x = curLoc.x-dir[i][1];

				if (nextLoc.y == fishLoc.y && nextLoc.x == fishLoc.x) {
					findFish = 1;
					break;
				}

				if (arr[nextLoc.y][nextLoc.x] > shark.size) {
					visit[nextLoc.y][nextLoc.x] = 1;
					continue;
				}

				if (nextLoc.y > 0 && nextLoc.x > 0 && nextLoc.y <= N && nextLoc.x <= N && visit[nextLoc.y][nextLoc.x] == 0) {
					Q.push(nextLoc);

					visit[nextLoc.y][nextLoc.x] = 1;
				}
			}

			if (findFish == 1) {
				break;
			}
		}
	}

	return findFish == 1 ? len : 0;
}

int main(void)
{
	vector<node> fish;
	vector<node>::iterator it;
	node shark;

	int dist, minDist, minX, minY, sec, numEatFish;

	cin >> N;

	dist = sec = numEatFish = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 9) {
				arr[i][j] = 0;

				shark.loc.y = i;
				shark.loc.x = j;
				shark.size = 2;
			}
			else if (arr[i][j] != 0) {
				fish.push_back({{i, j}, arr[i][j]});
			}
		}
	}

	while (!fish.empty()) {
		minDist = minY = minX = INT_MAX;

		it = fish.end();

		for (vector<node>::iterator iter = fish.begin(); iter != fish.end(); iter++) {
			if (iter->size < shark.size) {
				dist = getDistance(iter->loc, shark);

				if (dist != 0 && dist < minDist) {
					minDist = dist;
					minX = iter->loc.x;
					minY = iter->loc.y;

					it = iter;
				}
			}
		}

		if (it != fish.end()) {
			sec += minDist;
			shark.loc.y = it->loc.y;
			shark.loc.x = it->loc.x;

			arr[it->loc.y][it->loc.x] = 0;
			fish.erase(it);

			numEatFish++;
			if (numEatFish == shark.size) {
				shark.size++;
				numEatFish = 0;
			}
		}
		else {
			break;
		}
	}

	printf("%d\n", sec);

	return 0;
}
