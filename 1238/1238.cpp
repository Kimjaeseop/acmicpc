#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// 다익스트라

int N, M, X;
vector<pair<int, int>> V[1001];

int dijkstra(int start, int dest)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	
	pair<int, int> curNode, nextNode;
	int dist[1001];

	for (int i = 0; i < 1001; i++) {
		dist[i] = INT_MAX;
	}

	dist[start] = 0;

	pq.push({0, start}); 

	while (!pq.empty()) {
		curNode = pq.top();
		pq.pop();

		// check visit
		if (dist[curNode.second] < curNode.first) {
			continue;
		}

		for (auto iter : V[curNode.second]) {
			nextNode = iter;
			nextNode.first += curNode.first;

			if (dist[nextNode.second] > nextNode.first) {
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
	int dist, ans;

	freopen("input_1.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &X);

	dist = ans = 0;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);

		// first : cost, second : destination
		V[a].push_back({c, b});
	}

	for (int i = 1; i <= N; i++) {
		dist = 0;

		dist += dijkstra(i, X);
		dist += dijkstra(X, i);

		if (ans < dist) {
			ans = dist;
		}
	}

	printf("%d\n", ans);

	return 0;
}
