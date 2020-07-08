#include <stdio.h>
#include <algorithm>

using namespace std;

// EX ) 4 2
// 0 + 4
// 1 + 3
// 2 + 2
// 3 + 1
// 4 + 0

// 3중 반복문 필요
// i <= N, j <= K, p <= i
// i는 N까지, j는 K까지의 인덱스 계산
// p는 i보다 작은 수들의 경우의 수를 모아서 계산

int dp[210][210]; // 201 201로 하니 200 200에서 쓰레기 값 나옴

int main(void)
{
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i=0; i<=N; i++)
		dp[i][1]=1;

	for (int i=0; i<=N; i++) {
		for (int j=0; j<=K; j++) {
			for (int p=0; p<=i; p++) {
				dp[i][j] += dp[p][j-1];
				dp[i][j] %= 1000000000;
			}
		}
	}

	printf("%d\n", dp[N][K]);

	return 0;
}
