#include <stdio.h>

#define MIN(a, b) (((a) > (b)) ? (b) : (a))

int N;
int DP[1001][3];
int cost[1001][3];

// BFS, DFS 시간초과 -> 검색 후 DP
// 이런 문제가 나오면 머리속에 그래프부터 그려지는게 문제..

int main(void)
{
	freopen("input_1.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) 
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);

	for (int i = 1; i <= N; i++) { // i-1과 비교하기 위해 i = 1부터 시작
		DP[i][0] = MIN(DP[i-1][1], DP[i-1][2]) + cost[i][0];
		DP[i][1] = MIN(DP[i-1][0], DP[i-1][2]) + cost[i][1];
		DP[i][2] = MIN(DP[i-1][0], DP[i-1][1]) + cost[i][2];
	}

	printf("%d\n", MIN(DP[N][0], MIN(DP[N][1], DP[N][2])));

	return 0;
}
