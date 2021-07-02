# [스타트와 링크](https://www.acmicpc.net/problem/14889)
# 아이디어

1. 병합해서 2/N개 뽑으면 안되나? (X)
	- 겹치는 사람이 생길 수 있어서 안될 듯
	- 모든 쌍의 능력치 조합을 계산하기 어렵다

- (1, 2) : 1 + 4 = 5
- (1, 3) : 2 + 7 = 9 
- (1, 4) : 3 + 3 = 6
- (2, 3) : 5 + 1 = 6
- (2, 4) : 6 + 4 = 10
- (3, 4) : 2 + 5 = 7

2. nC(n/2)를 구해서 능력치를 계산한다. (O)
	- index, next_permutation 사용
		- next_permutation을 쓰는 것보다 직접 조합 재귀로 구하면서 능력치를 계산하면 이전 값 참조가 가능하니 효율적이지 않을까?
		- 직접 재귀로 모든 조합을 만들지 않고 첫 인덱스가 0인 조합만 만들고 나머지 여집합과의 차이를 구한다.
			- 시작이 0이 아닌 조합은 시작이 0인 조합의 여집합에 무조건 해당된다.

# Code
```C
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
```
