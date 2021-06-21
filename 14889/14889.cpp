#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int arr[21][21];
int MIN = 1e9;

int calValue(vector<int> V, int value)
{
	int sum = 0;

	for (int i = 0; i < V.size()-1; i++)
		sum += arr[V[i]][V.back()] + arr[V.back()][V[i]];

	return sum + value;
}

void DFS(vector<int> V, int depth, int value)
{
	int start = V.empty() ? 0 : (V.back() + 1);

	if (depth == N/2) {
		int link_score = 0;
		vector<int> link_team;

		for (int i = 0; i < N; i++) {
			int find = 0;
			for (int j = 0; j < N/2; j++) {
				if (i == V[j]) {
					find = 1;
					break;
				}
			}

			if (find == 0)
				link_team.push_back(i);
		}

		for (int i = 0; i < N/2; i++) {
			for (int j = i+1; j < N/2; j++) {
				link_score += arr[link_team[i]][link_team[j]] + arr[link_team[j]][link_team[i]];
			}
		}

		MIN = MIN > abs(value-link_score) ? abs(value-link_score) : MIN;
		return ;
	}

	if (V.empty() == false && V[0] != 0)
		return ;

	for (int i = start; i < N; i++) { 
		V.push_back(i);
		DFS(V, depth+1, calValue(V, value));
		V.pop_back();
	}
}

int main(void)
{
	int cnt = 0;
	vector<int> V;
	//freopen("input_1.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	DFS(V, 0, 0);

	printf("%d\n", MIN);
	
	return 0;
}
