#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[21][21];

int calValue(vector<int> V, int value)
{
	int sum = 0;

	for (int i = 0; i < V.size()-1; i++)
		sum += arr[V[i]][V.back()] + arr[V.back()][V[i]];

	return sum+value;
}

void BFS(vector<int> V, int depth, int value)
{
	int start = V.empty() ? 0 : V.back()+1;

	if (depth == N/2) {
		for (int i = 0; i < N/2; i++) 
			printf("%d ", V[i]);
		printf("\n");

		return ;
	}

	for (int i = start; i < N/2; i++) { 
		V.push_back(i);
		BFS(V, depth+1, calValue(V, value));
		V.pop_back();
	}
}

int main(void)
{
	int cnt = 0;
	vector<int> V;
	freopen("input_3.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	BFS(V, 0, 0);
	
	return 0;
}
