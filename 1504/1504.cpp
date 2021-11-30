#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// 다익스트라

int N, E, V1, V2;
vector<pair<int, int>> V[801];

int dijkstra(int start, int dest)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	
	pair<int, int> curNode, nextNode;
	int dist[801];

	for (int i = 0; i < 801; i++) {
		dist[i] = INT_MAX;
	}

	dist[start] = 0;

	pq.push({0, start}); 

	while (!pq.empty()) {
		curNode = pq.top();
		pq.pop();

		if (dist[curNode.second] < curNode.first) {
			continue;
		}

		for (auto iter : V[curNode.second]) {
			nextNode = iter;
			nextNode.first += curNode.first;

			if (dist[nextNode.second] >= nextNode.first) {
				dist[nextNode.second] = nextNode.first;
				pq.push(nextNode);
			}
		}

	}

	return dist[dest];
}

int main(void)
{
	int a, b, c;
	int dist, res1[3], res2[3], sumOfRes1, sumOfRes2;

	//freopen("input_1.txt", "r", stdin);

	scanf("%d %d", &N, &E);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);

		// first : cost, second : destination 
		// 양방향
		V[a].push_back({c, b});
		V[b].push_back({c, a});
	}

	scanf("%d %d", &V1, &V2);

	for (int i = 0; i < 3; i++) {
		res1[i] = res2[i] = 0;
	}

	res1[0] = dijkstra(1, V1);
	res1[1] = dijkstra(V1, V2);
	res1[2] = dijkstra(V2, N);

	res2[0] = dijkstra(1, V2);
	res2[1] = dijkstra(V2, V1);
	res2[2] = dijkstra(V1, N);

	/*
	for (int i = 0; i < 3; i++) {
		printf("%d %d\n", res1[i], res2[i]);
	}
	*/

	sumOfRes1 = res1[0]+res1[1]+res1[2];
	sumOfRes2 = res2[0]+res2[1]+res2[2];

	// 경로 못찾는 경우 예외 처리
	if (res1[0] == INT_MAX || res1[1] == INT_MAX || res1[2] == INT_MAX) {
		if (res2[0] == INT_MAX || res2[1] == INT_MAX || res2[2] == INT_MAX) {
			printf("-1\n");
		}
		else {
			printf("%d\n", sumOfRes2);
		}
	}
	else if (res2[0] == INT_MAX || res2[1] == INT_MAX || res2[2] == INT_MAX) {
		printf("%d\n", sumOfRes1);
	}
	else {
		printf("%d\n", sumOfRes1 > sumOfRes2 ? sumOfRes2 : sumOfRes1);
	}

	return 0;
}
