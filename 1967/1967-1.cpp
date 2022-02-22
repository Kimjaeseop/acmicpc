#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

// dest, weight
vector<pair<int, int>> V[10001];
int visit[10001];
int N, u, v, w;
int maxPoint, maxWeight;

void DFS(int startPoint, int weight)
{
	//printf("startPoint : %d, weight : %d\n", startPoint, weight);
	if (weight > maxWeight) {
		maxPoint = startPoint;
		maxWeight = weight;
	}

	for (auto iter : V[startPoint]) {
		if (!visit[iter.first]) {
			visit[iter.first] = 1;
			DFS(iter.first, weight+(iter.second));
		}
	}
}

int main(void)
{
	//freopen("input_1.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N-1; i++) {
		scanf("%d %d %d", &u, &v, &w);
		V[u].push_back({v, w});
		V[v].push_back({u, w});
	}

	visit[1] = 1;
	DFS(1, 0);

	//printf("%d %d\n", maxPoint, maxWeight);
	maxWeight = 0;

	for (int i = 0; i < 10001; i++) {
		visit[i] = 0;
	}

	visit[maxPoint] = 1;
	DFS(maxPoint, 0);

	printf("%d\n", maxWeight);

	return 0;
}
