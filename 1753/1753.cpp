#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// 다익스트라

int V, E, u, v, w, startVertex;
vector<pair<int, int>> edgeList[801];

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

		for (auto iter : edgeList[curNode.second]) {
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
	scanf("%d %d", &V, &E);
	scanf("%d", &startVertex);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		V[u].push_back({v, w});

	}
}


